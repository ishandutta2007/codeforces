#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005, MOD = 1e9 + 7;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, k, fact[MN], inv[MN], dp[MN], vis[MN], id = 1;
vector<int> divs[MN];

int choose(int n, int r) {
    if (n < r) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int rec(int cur) { //partition cur obj into n box s.t. gcd of all sizes is 1.
    if (cur < n) return 0;
    if (vis[cur] == id) return dp[cur];
    vis[cur] = id;
    int ret = choose(cur - 1, n - 1);
    for (int i : divs[cur]) if (cur % i == 0) ret -= rec(cur / i), ret %= MOD;
    ret %= MOD, ret += MOD, ret %= MOD;
    return dp[cur] = ret;
}

int32_t main() {
    boost();

    inv[0] = fact[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    for (int i = 2; i < MN; i++) for (int j = i; j < MN; j += i) divs[j].push_back(i);
    int t;
    cin >> t;
    while (t--) {
        cin >> k >> n;
        printf("%lld\n", rec(k));
        id++;
    }

    return 0;
}