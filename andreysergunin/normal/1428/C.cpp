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
    string s;
    cin >> s;
    int n = sz(s);

    string t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            if (!t.empty() && t.back() == 'A') {
                t.pop_back();
            } else {
                t.push_back(s[i]);
            }
        } else {
            t.push_back(s[i]);
        }
    }

    reverse(all(t));
    while (sz(t) >= 2 && t.back() == 'B' && t[sz(t) - 2] == 'B') {
        t.pop_back();
        t.pop_back();
    }

    cout << sz(t) << endl;

}