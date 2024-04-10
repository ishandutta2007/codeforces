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

#define maxN 100011
#define maxLimit 12
#define mod 1000000007


/*
    0 = < k
    1 = k
    2 = > k
*/

int n, m, i, j, limit, x, y, k;
vector<int> list[maxN];
ll dp[maxN][maxLimit][3], aux[maxLimit][3];
ll cnt0, cnt1, cnt2, down[maxN];
ll ans;

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void dfs(int node, int root) {
    int i, s1, s2, tp;

    down[node] = 1;

    for (i = 0; i < list[node].size(); i++) {
        if (list[node][i] == root) {
            list[node][i] = list[node].back();
            list[node].pop_back();
            i--;
            continue;
        }
        dfs(list[node][i], node);
        down[node] += down[list[node][i]];
    }

    memset(aux, 0, sizeof(aux));
    aux[0][0] = cnt0;
    aux[1][1] = cnt1;
    aux[0][2] = cnt2;

    for (auto to : list[node]) {
        memcpy(dp[node], aux, sizeof(aux));
        memset(aux, 0, sizeof(aux));

        for (int s1 = 0; s1 <= limit; s1++) {
            for (tp = 0; tp <= 2; tp++) {
                if (dp[node][s1][tp] == 0) continue;

                for (int s2 = 0; s1 + s2 <= limit && s2 <= down[to]; s2++) {
                    if (tp == 0) {
                        add(aux[s1 + s2][tp], (dp[node][s1][tp] * (dp[to][s2][0] + dp[to][s2][1] + dp[to][s2][2])) % mod );
                        continue;
                    }

                    if (tp == 1) {
                        add(aux[s1 + s2][tp], (dp[node][s1][tp] * dp[to][s2][0]) % mod);
                        continue;
                    }

                    if (tp == 2) {
                        add(aux[s1 + s2][tp], (dp[node][s1][tp] * (dp[to][s2][0] + dp[to][s2][2])) % mod );
                        continue;
                    }
                }
            }
        }
    }

    memcpy(dp[node], aux, sizeof(aux));
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m;
    for (i = 1; i < n; i++) {
        cin >> x >> y;
        list[x].pb(y);
        list[y].pb(x);
    }

    cin >> k >> limit;
    cnt0 = k - 1;
    cnt1 = 1;
    cnt2 = m - k;

    dfs(1, 0);
    for (i = 0; i <= limit; i++) {
        for (j = 0; j <= 2; j++) {
            ans += dp[1][i][j];
            ans %= mod;
        }
    }

    cout << ans;


    return 0;
}