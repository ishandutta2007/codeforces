#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int task;
 
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

pair<int, string> f(const string &s) {
    string res;
    int cnt = 0;
    for (char c : s) {
        if (c == 'B') {
            cnt ^= 1;
        } else {
            if (!res.empty() && res.back() == c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
    }
    return {cnt, res};
}

void solve() {
    string s, t;
    cin >> s >> t;

    cout << (f(s) == f(t) ? "YES\n" : "NO\n");
}