#include <bits/stdc++.h>

using namespace std;
using matrix = vector <vector <int> >;

const int MOD = 998'244'353;

matrix fast(matrix a, int b)
{
    const int n = a.size();
    matrix ret(n, vector <int> (n, 0));
    for (int i = 0; i < n; ++i) ret[i][i] = 1;

    auto mult = [&](const matrix &a, const matrix &b) {
        matrix result(n, vector <int> (n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result[i][j] = (result[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return result;
    };

    while (b) {
        if (b & 1)  ret = mult(a, ret);
        a = mult(a, a);
        b >>= 1;
    }

    return ret;
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    if (k < 3) {
        puts("0");
        exit(0);
    }

    matrix N(n, vector <int> (n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        u--, v--;
        N[u][v]++;
        N[v][u]++;
    }

    matrix S(n + n, vector <int> (n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i != k) {
                    S[i][k] += N[i][j] * N[j][k];
                }
            }

            S[n + i][j] = N[i][j];
        }
    }

    matrix Q(n + n, vector <int> (n + n, 0));
    for (int i = 0; i < n; ++i) {
        Q[n + i][i] = 1;
        Q[i][n + i] = MOD + 1;

        for (int j = 0; j < n; ++j) {
            Q[i][n + i] -= N[i][j];
            Q[i][j] = N[i][j];
        }

        Q[i][n + i] %= MOD;
    }
    
    Q = fast(Q, k - 2);

    int ans = 0;
    for (int g = 0; g < n; ++g) {
        for (int j = 0; j < n + n; ++j) {
            ans = (ans + 1LL * Q[g][j] * S[j][g]) % MOD;
        }
    }

    printf("%d\n", ans);
    return 0;
}