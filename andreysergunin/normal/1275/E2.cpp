#pragma GCC optimize("Ofast", "unroll-loops")
 
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
    cin >> tests;
 
    while (tests--) {
        solve();
    }
 
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// -----------------------------------------------------------------------
 
void solve() {
    string s;
    cin >> s;
    int n = sz(s);
 
 
    vector<int> idx;
    vector<int> used(n);
 
    for (int i = 0; i + 5 <= n; ++i) {
        if (s.substr(i, 3) == "two" && s.substr(i + 2, 3) == "one") {
            idx.push_back(i + 2);
            used[i + 2] = 1;
        }
    }
 
    for (int i = 0; i + 3 <= n; ++i) {
        if (s.substr(i, 3) == "one" || s.substr(i, 3) == "two") {
            bool ok = true;
            for (int j = 0; j < 3; ++j) {
                ok &= !used[i + j];
            }
            if (ok) {
                idx.push_back(i + 1);
                used[i + 1] = 1;
            }
        }
    }
 
 
    cout << sz(idx) << endl;
    for (int i : idx) {
        cout << i + 1 << " ";
    }
    cout << endl;
}