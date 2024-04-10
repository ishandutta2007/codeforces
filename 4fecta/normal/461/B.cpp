#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005; ll MOD = 1e9 + 7;

int n, u, v, val[MN];
vector<int> a[MN];
ll dp[MN][2];

ll fpow(ll x, ll p) {
    if (p == 0) return 1;
    ll pre = fpow(x, p / 2);
    if (p % 2) return ((pre * pre) % MOD * x) % MOD;
    else return (pre * pre) % MOD;
}

void dfs(int cur) {
    vector<ll> zero, one;
    for (int nxt : a[cur]) {
        dfs(nxt);
        one.push_back(dp[nxt][1]);
        zero.push_back((dp[nxt][0] + dp[nxt][1]) % MOD);
    }
    if (!val[cur]) {
        dp[cur][0] = 1;
        for (ll num : zero) dp[cur][0] *= num, dp[cur][0] %= MOD;
        for (int i = 0; i < one.size(); i++) dp[cur][1] += ((dp[cur][0] * one[i]) % MOD * fpow(zero[i], MOD - 2)) % MOD;
    } else {
        dp[cur][1] = 1;
        for (ll num : zero) dp[cur][1] *= num, dp[cur][1] %= MOD;
    }
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u;
        a[u].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) cin >> val[i];
    dfs(0);
    printf("%lld\n", dp[0][1] % MOD);

    return 0;
}