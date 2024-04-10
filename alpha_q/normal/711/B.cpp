#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, a, b;
long long g[N][N];

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%lld", g[i] + j);
            if (g[i][j] == 0) a = i, b = j;
        }
    } 

    if (n == 1) {
        if (g[1][1] != 0) printf("-");
        printf("1\n");
        return 0;
    }

    long long ro = 0LL;
    for (int i = 1; i <= n; ++i) {
        int flag = 0;
        if (i != a) {
            for (int j = 1; j <= n; ++j) ro += g[i][j];
            flag = 1;
            break;
        }
        if (flag) break;
    }

    long long av = 0LL;
    for (int j = 1; j <= n; ++j) av += g[a][j];

    if (av >= ro) {
        printf("-1\n");
        return 0;
    }

    g[a][b] = ro - av;

    for (int i = 1; i <= n; ++i) {
        long long sro = 0LL, scol = 0LL;
        for (int j = 1; j <= n; ++j) sro += g[i][j], scol += g[j][i];
        if (sro != ro or scol != ro) {
            printf("-1\n");
            return 0;
        }
    }

    long long dia1 = 0LL, dia2 = 0LL;
    for (int i = 1; i <= n; ++i) {
        dia1 += g[i][i];
        dia2 += g[i][n + 1 - i];
    }

    if (dia1 != ro or dia2 != ro) {
        printf("-1\n");
        return 0;
    }

    printf("%lld\n", g[a][b]);
    return 0;
}