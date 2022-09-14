#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

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
    // cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------


void solve() {
    vector<ll> x(1), y(1);
    cin >> x[0] >> y[0];
    ll ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    while (x.back() < 2e16 && y.back() < 2e16) {
        ll xx = x.back() * ax + bx;
        ll yy = y.back() * ay + by;
        x.push_back(xx);
        y.push_back(yy);
    }

    if (x.back() > 1e17 || y.back() > 1e17) {
        x.pop_back();
        y.pop_back();
    }

    ll sx, sy, t;
    cin >> sx >> sy >> t;

    int res = 0;

    for (int i = 0; i < sz(x); ++i) {
        for (int j = 0; j < sz(x); ++j) {
            if (abs(x[i] - sx) + abs(y[i] - sy) + abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t) {
                res = max(res, abs(i - j) + 1);
            }
        }   
    }

    cout << res << endl;
}