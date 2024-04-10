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
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

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
    int x, y;
    cin >> x >> y;
    vector<int> a, b;
    for (int i = 0; i < 30; ++i) {
        if (x & (1 << i)) {
            a.push_back(i);
        }
        if (y & (1 << i)) {
            b.push_back(i);
        }
    }
    if (x > y) {
        cout << "NO\n";
        return;
    }

    while (sz(a) > 0 && sz(b) > 0 && a.back() == b.back()) {
        a.pop_back();
        b.pop_back();
    }

    while (!b.empty()) {
        if (a.empty()) {
            cout << "NO\n";
            return; 
        } else if (a.back() <= b.back()) {
            a.pop_back();
            b.pop_back();
        } else {
            a.pop_back();
        }
    }

    cout << "YES\n";



}