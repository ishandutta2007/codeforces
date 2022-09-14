#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const bool READ = true;

void solve() {  
    int n, m;
    ll k;
    if (READ) {
        cin >> n >> m >> k;
    } else {
        n = 2; m = 2; k = ll(1e12);
    }

    vector<int> a(n), b(m);
    if (READ) {
        for (int &x : a) {
            cin >> x;
            --x;
        }
        for (int &y : b) {
            cin >> y;
            --y;
        }
    } else {
        iota(all(a), 0); iota(all(b), 0);
        reverse(all(b));
    }

    if (n < m) {
        swap(n, m);
        swap(a, b);
    } 

    vector<int> pos(2 * n, -1);
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }

    vector<int> cnt(n, m);
    for (int j = 0; j < m; ++j) {
        int i = pos[b[j]];
        if (i != -1) {
            --cnt[(i - j + n) % n];
        }
    }

    ll res = 0;

    ll period = 0;
    int g = gcd(n, m);
    for (ll t = 0; t < n / g; ++t) {
        ll x = t * m;
        period += cnt[x % n];
    }
    ll l = ll(n) * m / g;

    ll full = (k - 1) / period;
    res += full * l;
    k -= full * period;
    assert(k > 0);

    ll x = 0;
    for (ll ops = 0; k > 0; ++ops) {
        // assert(ops <= 2 * (n + m));
        if (cnt[x % n] < k) {
            k -= cnt[x % n];
            x += m;
        } else {
            while (k > 0) {
                k -= (a[x % n] != b[x % m]);
                ++x;
            }
            break;
        }
    }

    cout << res + x << endl;
}