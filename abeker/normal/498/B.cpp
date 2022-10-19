#include <iostream>
#include <cstdio>
using namespace std;

typedef double ld;

const int MAXN = 5005;

int N, T;
int t[MAXN];
ld p[MAXN];
ld val[MAXN];
ld f[MAXN][MAXN], g[MAXN][2];

ld pow(ld x, int e) {
    if (!e) return 1.0;
    if (e % 2) return x * pow(x, e - 1);
    ld res = pow(x, e / 2);
    return res * res;
}

void load() {
    scanf("%d%d", &N, &T);
    for (int i = 1; i <= N; i++) {
        cin >> p[i] >> t[i];
        p[i] /= 100.0;
        val[i] = pow(1 - p[i], t[i]);
    }
}

ld solve() {
    f[1][1] = 1.0;
    int c = 1;
    for (int j = 2; j <= T + 1; j++) {
        for (int i = 1; i <= N + 1; i++) {
            f[i][j] = p[i - 1] * (f[i - 1][j - 1] + g[i - 1][c ^ 1]);
            if (j >= t[i - 1]) f[i][j] += val[i - 1] * f[i - 1][j - t[i - 1]];
            g[i][c] = (1 - p[i]) * (f[i][j - 1] + g[i][c ^ 1]);
            if (j >= t[i]) g[i][c] -= val[i] * f[i][j - t[i]];
        }
        c ^= 1;
    }
    ld sol = 0.0;
    for (int i = 1; i <= N; i++) 
        sol += (f[i][T + 1] + g[i][c ^ 1]) * (i - 1);
    for (int i = 1; i <= T + 1; i++) 
        sol += f[N + 1][i] * N;
    return sol;
}

int main() {
    load();
    printf("%.9lf\n", solve());
    return 0;
}