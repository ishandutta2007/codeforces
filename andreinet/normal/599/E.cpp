#include <bits/stdc++.h>
#define bitCount(x) __builtin_popcount(x)
using namespace std;

typedef long long i64;
const int NMAX = 13, MMAX = NMAX * NMAX, DMAX = 1 << NMAX;

bool graph[NMAX][NMAX];
int lcas[NMAX][NMAX];

i64 dp[NMAX][DMAX];

int biggestOneByte(int x) {
    int ret = NMAX;
    while ((x & (1 << ret)) == 0) --ret;
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x][y] = graph[y][x] = true;
    }

    memset(lcas, -1, sizeof lcas);
    for (int i = 0; i < n; ++i)
        lcas[i][i] = i;

    for (int i = 0; i < q; ++i) {
        int x, y, l;
        cin >> x >> y >> l;
        x--;
        y--;
        l--;
        if (lcas[x][y] != -1 && lcas[x][y] != l) {
            puts("0");
            return 0;
        }
        lcas[x][y] = lcas[y][x] = l;
    }

    for (int conf = 1; conf < 1 << n; ++conf) {
        for (int root = 0; root < n; ++root) {
            if ((conf & (1 << root)) == 0) continue;
            if (bitCount(conf) == 1) {
                dp[root][conf] = 1;
                continue;
            }
            int xconf = conf ^ (1 << root);
            int take = biggestOneByte(xconf);
            for (int pconf = xconf; pconf & (1 << take);
                    pconf = (pconf - 1) & xconf) {
                for (int i = 0; i < n; ++i) {
                    if ((pconf & (1 << i)) == 0) continue;
                    for (int j = 0; j < n; ++j) {
                        if ((pconf & (1 << j)) != 0 ||
                                (xconf & (1 << j)) == 0) continue;
                        if (graph[i][j] ||
                                (lcas[i][j] != -1 &&
                                 lcas[i][j] != root)) goto FINISH1;
                    }
                }
                for (int proot = 0; proot < n; ++proot) {
                    if ((pconf & (1 << proot)) == 0) continue;
                    for (int i = 0; i < n; ++i) {
                        if ((pconf & (1 << i)) && i != proot &&
                                graph[i][root]) goto FINISH2;
                        if ((pconf & (1 << i)) && lcas[root][i] != -1 &&
                                lcas[root][i] != root) goto FINISH2;
                    }
                    
                    dp[root][conf] += dp[root][conf ^ pconf] *
                        dp[proot][pconf];
                    FINISH2:;
                }
                FINISH1:;
            }
        }
    }

    cout << dp[0][(1 << n) - 1] << '\n';
}