#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

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
    cout << setprecision(8) << fixed;
    cerr << setprecision(5) << fixed;

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

void solve() {    
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pii> res;

    vector<pii> heights;
    int good = -1;

    int h = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            continue;
        } else if (a[i] == 1) {
            res.push_back({h, i});
            heights.push_back({h, i});
            --h;
        } else if (a[i] == 2) {
            if (heights.empty()) {
                cout << -1 << endl;
                return;
            }
            res.push_back({heights.back().first, i});
            heights.pop_back();

            if (good == -1) {
                good = i;
            }
        } else if (a[i] == 3) {
            if (good != -1) {
                res.push_back({h, good});
            } else {
                if (heights.empty()) {
                    cout << -1 << endl;
                    return;
                }
                res.push_back({h, heights.back().second});
                heights.pop_back();
            }

            res.push_back({h, i});
            --h;
            good = i;
        }

    }

    cout << sz(res) << endl;
    for (auto [x, y] : res) {
        cout << x + 1 << " " << y + 1 << endl;
    }

}