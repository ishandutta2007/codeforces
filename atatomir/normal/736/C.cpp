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

#define maxN 111
#define maxK 23

#define mod 1000000007

int n, k, i, j, x, y;
vector<int> list[maxN];
vector<int> act;

ll dp[maxN][maxK][maxK]; // dp[node][need][down]
ll aux[maxK][maxK];

int n1, d1, n2, d2, nn, dd;


inline int get_nn(int n1, int n2) {
    if (n1 != k + 1 && n1 >= d2 + 1) n1 = k + 1;
    if (n2 != k + 1 && n2 >= d1 + 1) n2 = k + 1;

    if (n1 == n2 && n1 == k + 1) return k + 1;

    if (n1 == k + 1) return n2 - 1;
    if (n2 == k + 1) return n1;
    return min(n1, n2 - 1);
}

void compute(int node) {
    static int i, j;
    ll paint;


    if (act.size() == 0) {
        dp[node][k + 1][0] = 1; // paint it
        dp[node][k][k + 1] = 1; // don't paint it
        return;
    }

    // add initial state
    for (i = 1; i <= k + 1; i++)
        for (j = 0; j <= k + 1; j++)
            dp[node][ (i == k + 1 ? k + 1 : i - 1) ][min(k + 1, j + 1)] += dp[act[0]][i][j];

    for (i = 0; i <= k + 1; i++)
        for (j = 0; j <= k + 1; j++)
            dp[node][i][j] %= mod;

    // add other states
    for (i = 1; i < act.size(); i++) {
        int newn = act[i];

        memcpy(aux, dp[node], sizeof(dp[node]));
        memset(dp[node], 0, sizeof(dp[node]));


        for (n1 = 0; n1 <= k + 1; n1++) {
            for (d1 = 0; d1 <= k + 1; d1++) {
                if (aux[n1][d1] == 0) continue;

                for (n2 = 1; n2 <= k + 1; n2++) {
                    for (d2 = 0; d2 <= k + 1; d2++) {
                        nn = get_nn(n1, n2);
                        dd = min(d1, d2 + 1);

                        dp[node][nn][dd] = (dp[node][nn][dd] + aux[n1][d1] * dp[newn][n2][d2]) % mod;
                    }
                }
            }
        }
    }

    dp[node][k][k + 1] += dp[node][k + 1][k + 1] ;
    dp[node][k + 1][k + 1] = 0;


    paint = 0;
    for (i = 0; i <= k + 1; i++) {
        paint += dp[node][0][i];
        dp[node][0][i] = 0;
    }

    for (i = 1; i <= k + 1; i++) {
        //if (dp[node][i][0] != 0) cerr << "err";
        dp[node][i][0] = 0;

        for (j = 1; j <= k + 1; j++)
            paint += dp[node][i][j];
    }

    dp[node][k + 1][0] += paint;
    dp[node][k + 1][0] %= mod;
}

void solve(int node, int root) {
    for (auto to : list[node]) {
        if (to == root) continue;
        solve(to, node);
    }

    act.clear();
    for (auto to : list[node]) {
        if (to == root) continue;
        act.pb(to);
    }

    compute(node);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    if (k == 0) {
        printf("1");
        return 0;
    }

    solve(1, 0);


    ll ans = 0;
    for (i = k + 1; i <= k + 1; i++)
        for (j = 0; j <= k + 1; j++)
            ans += dp[1][i][j];

    ans %= mod;
    printf("%lld", ans);

    return 0;
}