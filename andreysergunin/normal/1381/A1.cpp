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
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int l = 0, r = n - 1;
    bool rev = false;
    vector<int> ans;

    for (int i = n - 1; i >= 0; --i) {
        if (rev) {
            if (s[r] != t[i]) {
                ans.push_back(1);
            } 
            ans.push_back(i + 1);
            rev ^= 1;
            --r;
        } else {
            if (s[l] == t[i]) {
                ans.push_back(1);
            }
            ans.push_back(i + 1);
            rev ^= 1;
            ++l;
        }
    }

    cout << sz(ans) << " ";
    for (int pos : ans) {
        cout << pos << " ";
    }
    cout << "\n";
}