#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;
const ll mod = 998244353;
const int MAXN = 1e6 + 5;

vector<ll> fact, invfact;

ll my_pow(ll n, ll m) {
    if (m == 0) return 1;
    ll now = my_pow(n, m / 2);
    now = (now * now) % mod;
    if (m % 2 == 1) now = (now * n) % mod;
    return now;
}

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    bool one = 0;
    vector<int> valid;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == n) one = 1;
        if (cnt[i]) valid.pb(i);
    }
    if (one) {
        cout << 1 << "\n";
        return;
    }
    ll total = 0, sum = 0;
    vector<ll> res(n + 1), dp(n + 1);
    for (int j = 1; j <= n; j++) {
        if (n % j) continue;
        int k = n / j;
        bool ok = 1;
        for (auto &i : valid) {
            if (cnt[i] % k) ok = 0;
        }
        if (!ok) continue;
        ll X = fact[j];
        for (auto &i : valid) {
            X *= invfact[cnt[i] / k];
            X %= mod;
        }
        res[j] += X;
        res[j] %= mod;
        for (int i = 2 * j; i <= n; i += j) res[i] = (res[i] - res[j] + mod) % mod;
        total += res[j] * my_pow(j, mod - 2);
        total %= mod;
        ll A = 0;
        ll pr = 1;
        for (auto &p : valid) pr = (pr * invfact[cnt[p] / k]) % mod;
        for (auto &i : valid) {
            if (cnt[i] / k < 2) continue;
            ll now = (fact[j - 2] * pr) % mod;
            now *= fact[cnt[i] / k];
            now %= mod;
            now *= invfact[cnt[i] / k - 2];
            now %= mod;
            A += now;
            A %= mod;
        }
        dp[j] += (A * n) % mod;
        dp[j] %= mod;
        for (int i = 2 * j; i <= n; i += j) dp[i] = (dp[i] - dp[j] + mod) % mod;
        sum += dp[j] * my_pow(j, mod - 2);
        sum %= mod;
    }
    cout << (((total * n - sum + mod) % mod) * my_pow(total, mod - 2)) % mod << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    fact.resize(MAXN);
    invfact.resize(MAXN);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = (invfact[i - 1] * my_pow(i, mod - 2)) % mod;
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}