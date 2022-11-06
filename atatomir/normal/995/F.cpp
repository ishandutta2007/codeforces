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

const ll maxN = 3011;
const ll mod = 1000000007;

ll n, D, i, x;
vector<ll> list[maxN];
ll dp[maxN][maxN];
vector< pair<ll, ll> > points;

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

void dfs(int node) {
    int i, j;

    for (i = 1; i <= n; i++) dp[node][i] = 1;
    for (auto to : list[node]) {
        dfs(to);
        for (i = 1; i <= n; i++)
            dp[node][i] = (dp[node][i] * dp[to][i]) % mod;
    }

    for (i = 1; i <= n; i++)
        dp[node][i] = (dp[node][i] + dp[node][i - 1]) % mod;
}

ll interpolate_on_point(ll x) {
    ll i, j, up, down;
    ll ans = 0;

    for (i = 0; i < points.size(); i++) {
        up = down = 1;

        for (j = 0; j < points.size(); j++) {
            if (i == j) continue;
            up = (up * (mod + x - points[j].first)) % mod;
            down = (down * (mod + points[i].first - points[j].first)) % mod;
        }

        up = (up * points[i].second) % mod;
        up = (up * poww(down, mod - 2)) % mod;
        ans = (ans + up) % mod;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &D);
    for (i = 2; i <= n; i++) {
        scanf("%lld", &x);
        list[x].pb(i);
    }

    dfs(1);
    if (D <= n) {
        printf("%lld", dp[1][D]);
        return 0;
    }

    for (i = 0; i <= n; i++) points.pb(mp(i, dp[1][i]));
    ll ans = interpolate_on_point(D);

    printf("%lld", ans);

    return 0;
}