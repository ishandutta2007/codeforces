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

const int INF = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> segs(n);
    for (auto &[l, r, c] : segs) {
        cin >> l >> r >> c;
    }

    int lf = INF, rg = 0;
    int cost_lf = 0, cost_rg = 0;

    bool big_seg = false;
    int cost_big = 0;

    for (auto [l, r, c] : segs) {
        if (l < lf) {
            lf = l;
            cost_lf = c;
            big_seg = false;
        } else if (l == lf) {
            cost_lf = min(cost_lf, c);
        }

        if (rg < r) {
            rg = r;
            cost_rg = c;
            big_seg = false;
        } else if (r == rg) {
            cost_rg = min(cost_rg, c);
        }

        if (lf == l && rg == r) {
            if (big_seg) {
                cost_big = min(cost_big, c);
            } else {
                big_seg = true;
                cost_big = c;
            }
        }

        int res = cost_lf + cost_rg;
        if (big_seg) {
            res = min(res, cost_big);
        }

        cout << res << "\n";
    }


}