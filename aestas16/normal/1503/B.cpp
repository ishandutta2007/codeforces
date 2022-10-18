/*
    I will never forget it.
*/
 
// 392699
 
#include <bits/stdc++.h>
 
using namespace std;
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 1e2;
const int nx[] = {0, 0, 0, 1, -1};
const int ny[] = {0, 1, -1, 0, 0};
 
int n, c[N + 10][N + 10], qwq[N + 10][N + 10];
 
int getcolor(int x, int y = 0) {
    for (int i = 1; i <= 3; i++)
        if (i != x && i != y) return i;
    return 0;
}
 
int x, y;
 
void getid(int col) {
    x = y = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == 0) {
                for (int k = 1; k <= 4; k++)
                    if (c[i + nx[k]][j + ny[k]] == col) goto cat;
                x = i, y = j;
                return;
                // if (qwq[x][y] == 0 || qwq[x][y] == col) return (void)(qwq[x][y] = col);
            }
        cat:;
        }
}
 
struct OI {
    int RP, score;
} FJOI2021;
 
int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    n = fr();
    for (int i = 0; i <= n + 1; i++) c[0][i] = c[n + 1][i] = c[i][0] = c[i][n + 1] = 4;
    int a = fr(), b = getcolor(a);
    c[1][1] = b, printf("%d %d %d\n", b, 1, 1), fflush(stdout);
    for (int i = 2; i <= n * n; i++) {
        a = fr(), b = getcolor(a), getid(b);
        if (x == 0 && y == 0) b = getcolor(a, b), getid(b);
        printf("%d %d %d\n", b, x, y), c[x][y] = b, fflush(stdout);
    }
    return 0;
}