#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 105

const ll mod = 1000000007;

int n, x, y, i, j;
vector<int> list[maxN];
ll dp[maxN][maxN][maxN]; //! dp[root][zones][act_dim]

int down[maxN];
ll pre[maxN][maxN], act[maxN][maxN]; //! [zones][act_dim]
ll sol[maxN], poww[maxN], ans[maxN];
ll comb[maxN][maxN];

void dfs(int node, int root) {
    int i, j, k, l;

    down[node] = 1;
    for (auto to : list[node])
        if (to != root)
            dfs(to, node);

    memset(act, 0, sizeof(act));
    act[1][1] = 1;

    for (auto to : list[node]) {
        if (to == root) continue;

        memcpy(pre, act, sizeof(act));
        memset(act, 0, sizeof(act));

        for (i = 1; i <= down[node]; i++) { //! i zones
            for (j = 1; j <= down[node]; j++) { //! j elements
                if (pre[i][j] == 0) continue;

                for (k = 1; k <= down[to]; k++) { //! k zones
                    for (l = 1; l <= down[to]; l++) { //! l elements
                        if (dp[to][k][l] == 0) continue;

                        //! do not merge the upper components
                        act[i + k][j] += ((pre[i][j] * dp[to][k][l]) % mod) * l;
                        act[i + k][j] %= mod;

                        //! merge the upper components
                        act[i + k - 1][j + l] += pre[i][j] * dp[to][k][l];
                        act[i + k - 1][j + l] %= mod;
                    }
                }
            }
        }


        down[node] += down[to];
    }

    memcpy(dp[node], act, sizeof(act));
}

int main()
{
   // freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i < n; i++) {
        cin >> x >> y;
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1, 0);

    poww[0] = 1;
    for (i = 1; i <= n; i++) poww[i] = (poww[i - 1] * n) % mod;

    sol[1] = 1;
    for (i = 2; i <= n; i++) { //! i zones
        for (j = 1; j <= n; j++) { //! j elements
            sol[i] += ((dp[1][i][j] * j) % mod) * poww[i - 2];
            sol[i] %= mod;
        }
    }

    for (i = 1; i <= n; i++) ans[n - i] = sol[i];

    for (i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for (j = 1; j <= i; j++)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = i + 1; j < n; j++)
            ans[i] += mod - ((ans[j] * comb[j][i]) % mod);
        ans[i] %= mod;
    }

    for (i = 0; i < n; i++) cout << ans[i] << ' ';



    return 0;
}