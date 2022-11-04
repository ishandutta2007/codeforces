#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> Ans;

bool B[22][22];

int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            B[i][j] = 1;
    int a = 1, b = 1;
    Ans.push_back(a * 12 + b);
    B[a][b] = 0;
    if(n != 63) {
    while(n >= 3) {
        if(a <= 6) {
            if(B[a][b - 1] == 1) b--;
            else if(B[a][b + 1] == 1) b++;
            else a++;
        } else {
            if(B[a + 1][b] == 1) a++;
            else if(B[a - 1][b] == 1) a--;
            else b++;
        }
        B[a][b] = 0;
        Ans.push_back(a * 12 + b);
        n--;
    }
    if(a == 8) {
        b++;
        Ans.push_back(a * 12 + b);
        b = 8;
        Ans.push_back(a * 12 + b);
    } else if(b == 8) {
        a++;
        Ans.push_back(a * 12 + b);
        a = 8;
        Ans.push_back(a * 12 + b);
    } else if(B[8][b]) {
        a = 8;
        Ans.push_back(a * 12 + b);
        b = 8;
        Ans.push_back(a * 12 + b);
    } else {
        b = 8;
        Ans.push_back(a * 12 + b);
        a = 8;
        Ans.push_back(a * 12 + b);
    }
        for(int i = 0; i < Ans.size(); i++)
            printf("%c%d ", Ans[i] % 12 + 'a' - 1, Ans[i] / 12);
    } else {
        while(a != 7 || b != 6) {
            if(a <= 6) {
                if(B[a][b - 1] == 1) b--;
                else if(B[a][b + 1] == 1) b++;
                else a++;
            } else {
                if(B[a + 1][b] == 1) a++;
                else if(B[a - 1][b] == 1) a--;
                else b++;
            }
            B[a][b] = 0;
            Ans.push_back(a * 12 + b);
            n--;
        }
        for(int i = 0; i < Ans.size(); i++)
            printf("%c%d ", Ans[i] % 12 + 'a' - 1, Ans[i] / 12);
        puts("h7 g7 g8 h8");
        
    }
    return 0;
}