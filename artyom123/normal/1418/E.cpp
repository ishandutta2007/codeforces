#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

ll mod = 998244353;

ll my_pow(ll n, ll m) {
    if (m == 0) return 1;
    ll now = my_pow(n, m / 2);
    if (m % 2 == 0) return (now * now) % mod;
    return (((now * now) % mod) * n) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (auto &c : d) cin >> c;
    sort(all(d));
    vector<ll> pr(n + 1);
    for (int i = 1; i <= n; i++) pr[i] = (pr[i - 1] + d[i - 1]) % mod;
    while (m--) {
        ll a, b;
        cin >> a >> b;
        ll small = lower_bound(all(d), b) - d.begin();
        ll big = n - small;
        if (big < a) {
            cout << 0 << "\n";
            continue;
        }
        ll small_sum = pr[small], big_sum = pr.back() - pr[small];
        ll ans = ((1 - (a * my_pow(big, mod - 2) % mod)) * big_sum) % mod + ((1 - (a * my_pow(big + 1, mod - 2) % mod)) * small_sum) % mod;
        ans %= mod;
        if (ans < 0) ans += mod;
        cout << ans << "\n";
    }
    return 0;
}