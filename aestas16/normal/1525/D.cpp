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

const int N = 5e3, INF = 0x7f7f7f7f;

int a[N + 10], pos[N + 10], f[N + 10][N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    int n = fr(), tot = 0;
    for (int i = 1; i <= n; i++) {
        fr(a[i]);
        if (a[i]) pos[++tot] = i;
    }
    for (int i = 1; i <= tot; i++)
        for (int j = 0; j <= n; j++) f[i][j] = INF;
    for (int i = 1; i <= tot; i++)
        for (int j = 1; j <= n; j++)
            if (a[j] == 0) f[i][j] = min(f[i][j - 1], f[i - 1][j - 1] + abs(j - pos[i]));
            else f[i][j] = f[i][j - 1];
    printf("%d\n", f[tot][n]);
    return 0;
}