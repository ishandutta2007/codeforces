#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

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

const ll INF = 4e18;

ll mySqrt(__int128 val) {
    ll x = sqrtl(val);
    while (__int128(x) * x < val) { 
        ++x;
    }
    while (__int128(x - 1) * (x - 1) >= val) {
        --x;
    }
    return x;
}

void solve() {
    int n;
    // n = 100000;
    ll target;
    // target = n * (rnd() % int(1e9)) + rnd() % n + 1;
    cin >> n >> target;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // a[i] = 1e9;
    }
    vector<ll> b(n);

    ll lf = -INF, rg = INF;

    auto get = [&](ll t) {
        ll sum = 0;
        bool ok = true;

        for (int i = 0; i < n; ++i) {
            if (__int128(9) * t + 12 * a[i] < 0) {
                continue;
            }
            ll val = mySqrt(__int128(9) * t + 12 * a[i]);
            val = (val - 3 + 5) / 6;

            b[i] = min(a[i], val);

            sum += b[i];
            if (sum > target) {
                ok = false;
            }
        }
        return ok;
    };

    while (lf + 1 < rg) {
        ll t = (lf + rg) / 2;
        if (get(t)) {   
            lf = t;
        } else {
            rg = t;
        }
    }

    get(lf);
    vector<ll> res = b;
    for (int x : res) {
        target -= x;
    }

    get(rg);
    for (int i = 0; i < n; ++i) {
        if (res[i] != b[i] && target) {
            --target;
            ++res[i];
        }
    }

    assert(target == 0);

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
}