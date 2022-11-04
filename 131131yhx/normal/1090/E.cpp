#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

bool B[11][11];

int O[64] = {18,35,52,69,54,71,56,62,72,55,40,46,63,48,31,16,22,39,24,30,47,64,70,53,38,23,13,28,45,60,66,49,59,65,50,33,43,37,20,14,29,12,27,10,25,42,36,19,9,26,41,58,68,51,57,67,61,44,34,17,11,21,15,32};

int n;

int Rk[11][11];

void move(int a, int b, int c, int d) {
    putchar(a + 'a' - 1);
    putchar(b + '0');
    putchar('-');
    putchar(c + 'a' - 1);
    putchar(d + '0');
    putchar('\n');
}

void move(int a, int b) {
    move((a - 1) / 8 + 1, (a - 1) % 8 + 1, (b - 1) / 8 + 1, (b - 1) % 8 + 1);
}

vector <int> V, Ans1, Ans2;
void Do(int a, int b) {
    Ans1.push_back(a);
    Ans2.push_back(b);
}

int vis[11][11];

int main() {
    for(int i = 0; i < 64; i++) O[i] -= 8;
    for(int i = 0; i < 64; i++) Rk[(O[i] - 1) / 8 + 1][(O[i] - 1) % 8 + 1] = i;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        char ch[23];
        scanf("%s", ch);
        B[ch[0] - 'a' + 1][ch[1] - '0'] = 1;
    }
    if(n == 0 || n == 64) return puts("0"), 0;
    vector <int> A(0), B(0);
    int cnt = 0;
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++) {
            int x = j * 8 - 8 + i;
            A.push_back(Rk[j][i]);
            if(++cnt == n) goto bomb;
        }
bomb:;
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            if(::B[i][j]) {
                B.push_back(Rk[i][j]);
            }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    for(; i < B.size(); i++)
        if(B[i] < A[i]) {
            for(int j = B[i]; j < A[i]; j++) {
                int k = i;
                while(k + 1 != B.size() && B[k + 1] == B[k] + 1) k++;
                for(int l = k; l >= i; l--) {
                    Do(O[B[l]], O[B[l] + 1]);
                    B[l]++;
                }
            }
        } else {
            for(int j = B[i]; j > A[i]; j--)
                Do(O[j], O[j - 1]);
        }
    printf("%d\n", Ans1.size());
    for(int i = 0; i < Ans1.size(); i++) move(Ans1[i], Ans2[i]);
    return 0;
}