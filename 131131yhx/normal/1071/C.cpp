#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int A[100010], n, tot = 0;

int B1[1 << 15], Pr1[1 << 15], B2[1 << 6], Pr2[1 << 6], Ans[100010][3], Cnt = 0;

void add(int a, int b, int c) {
    Ans[++Cnt][0] = a;
    Ans[Cnt][1] = b;
    Ans[Cnt][2] = c;
    A[a] ^= 1, A[b] ^= 1, A[c] ^= 1;
}

void DFS1(int x, int y, int lst = 0, int dep = 0) {
    if(B1[x] <= dep || dep > 7) return;
    B1[x] = dep, Pr1[x] = lst;
    for(int i = 0; i < y; i++)
        for(int j = i + 1; j < y; j++)
            if(j * 2 - i < y) DFS1(x ^ ((1 << i) + (1 << j) + (1 << j * 2 - i)), y, x, dep + 1);
}

void DFS2(int x, int y, int lst = 0, int dep = 0) {
    if(B2[x] <= dep || dep > 2) return;
    B2[x] = dep, Pr2[x] = lst;
    for(int i = 0; i < y; i++)
        for(int j = i + 1; j <= y; j++) {
            int tmp = x ^ (1 << i);
            if(j < y) tmp ^= (1 << j);
            if(j * 2 - i < y) tmp ^= (1 << j * 2 - i);
            DFS2(tmp, y, x, dep + 1);
        }
}

void Do2(int nwi, int x) {
    if(x == 0) return;
    int y = Pr2[x], z = x ^ y;
    vector <int> V;
    V.clear();
    for(int i = 0; i < 6; i++) if((z >> i) & 1) V.push_back(i);
    if(V.size() == 1) add(nwi + V[0], nwi + 6, nwi + 12 - V[0]);
    else add(nwi + V[0], nwi + V[1], nwi + 2 * V[1] - V[0]);
    Do2(nwi, y);
}

void Do1(int nwi, int x, int xx) {
    if(x == 0) return;
    int y = Pr1[x], z = x ^ y;
    vector <int> V;
    V.clear();
    for(int i = 0; i < xx; i++) if((z >> i) & 1) V.push_back(i);
    add(nwi + V[0], nwi + V[1], nwi + V[2]);
    Do1(nwi, y, xx);
}

int main() {
    memset(B1, 63, sizeof B1);
    memset(B2, 63, sizeof B2);
    DFS2(0, 6);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    int i = 1;
    for( ; i + 15 <= n; i += 6) {
        int nw = 0;
        for(int j = i; j < i + 6; j++) nw = nw + (A[j] << j - i);
        Do2(i, nw);
    }
    int nw = 0;
    for(int j = n; j >= i; j--) nw = nw * 2 + A[j];
    DFS1(0, n - i + 1);
    if(B1[nw] > 1000) {
        puts("NO");
        return 0;
    }
    Do1(i, nw, n - i + 1);
    puts("YES");
    printf("%d\n", Cnt);
    for(int i = 1; i <= Cnt; i++) printf("%d %d %d\n", Ans[i][0], Ans[i][1], Ans[i][2]);
    return 0;
}