#include <iostream>
#include <cstdio>
using namespace std;
typedef bool boolean;

const int N = 2001;

int a, b, c;
int num = 0;
int mu[N], ps[N / 5];
int g[N][N];

inline void init() {
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 1; i < N; i++)
        g[i][0] = g[0][i] = i;
    for (int i = 1; i < N; i++)
        for (int j = 1; j <= i; j++)
            g[i][j] = g[j][i] = g[i - j][j];
}

boolean vis[N];
inline void Euler() {
    mu[1] = 1;
    for (int i = 2, x; i < N; i++) {
        if (!vis[i]) ps[num++] = i, mu[i] = -1;
        for (int j = 0; j < num && (x = ps[j] * i) < N; j++) {
            vis[x] = true;
            if (i % ps[j])
                mu[x] = -mu[i];
            else {
                mu[x] = 0;
                break;
            }
        }    
    }
}

int calc(int x, int lim) {
    int rt = 0;
    for (int i = 1; i <= lim; i++)
        if (g[x][i] == 1)
            rt += lim / i;
    return rt;
}

int res = 0;
inline void solve() {
    for (int i = 1; i <= a; i++) {
        for (int d = 1; d <= b && d <= c; d++)
            if (g[i][d] == 1 && mu[d])
                res += (a / i) * mu[d] * calc(i, b / d) * calc(i, c / d);
    }
    int M = (1 << 30);
    res %= M;
    if (res < 0)    res += M;
    printf("%d", res);
}

int main() {
    init();
    Euler();
    solve();
    return 0;
}