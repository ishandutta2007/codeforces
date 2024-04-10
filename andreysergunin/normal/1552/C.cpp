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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

void solve() { 
    int n, k;
    cin >> n >> k;
    vector<pii> p(k);
    vector<int> used(2 * n);
    for (auto &[x, y] : p) {
        cin >> x >> y;
        --x; --y;
        used[x] = 1;
        used[y] = 1;
    }

    vector<int> unused;
    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i]) {
            unused.push_back(i);
        }
    }
    for (int i = 0; i < sz(unused) / 2; ++i) {
        p.push_back({unused[i], unused[i + sz(unused) / 2]});
    }
    assert(sz(p) == n);

    auto dst = [&](int x, int y) {
        if (x < y) {
            return y - x;
        }
        return n - (x - y);
    };

    auto on_segment = [&](int x, int y, int z) {
        return dst(x, z) + dst(z, y) == dst(x, y);
    };

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [x, y] = p[i];
            auto [u, v] = p[j];

            cnt += on_segment(x, y, u) ^ on_segment(x, y, v);
        }
    }

    cout << cnt << endl;


}