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

const long long INFLL = 1e18;
const int INF = 1e9 + 1;
const int mod = 1e9 + 7;

ll mul(ll a, ll b) {
    return (a * b) % mod;
}

ll add(ll a, ll b) {
    return ((a + b) % mod + mod) % mod;
}

ll my_pow(ll n, ll m) {
    if (m == 0) return 1;
    ll now = my_pow(n, m / 2);
    if (m % 2 == 0) return (now * now) % mod;
    else return (((now * now) % mod) * n) % mod;
}

ll rev(ll a) {
    return my_pow(a, mod - 2);
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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &c : a) cin >> c;
    vector<vector<ll>> h(n, vector<ll>(1 << n));
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) continue;
            h[i][mask] = 1;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) h[i][mask] = mul(h[i][mask], mul(a[i], rev(add(a[i], a[j]))));
            }
        }
    }
    vector<ll> f(1 << n);
    ll ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        ll x = 1;
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) continue;
            x = mul(x, h[j][((1 << n) - 1) ^ mask]);
        }
        ll y = 1;
        for (int mask1 = mask; mask1 > 0; mask1 = (mask1 - 1) & mask) {
            if (mask1 == mask) continue;
            ll z = 1;
            for (int j = 0; j < n; j++) {
                if (!(mask1 & (1 << j))) continue;
                z = mul(z, h[j][((1 << n) - 1) ^ mask]);
            }
            y = add(y, -mul(f[mask1], rev(z)));
        }
        f[mask] = mul(x, y);
        ans = add(ans, mul(f[mask], __builtin_popcount(mask)));
        //cout << mask << " " << f[mask] << endl;
    }
    cout << ans;
    return 0;
}