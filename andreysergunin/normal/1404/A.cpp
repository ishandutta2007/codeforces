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
    freopen("input.txt", "r", stdin);
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> r(k, -1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            continue;
        }
        if (r[i % k] == -1) {
            r[i % k] = s[i] - '0';
        }
        if (r[i % k] != s[i] - '0') {
            cout << "NO\n";
            return;
        }
    }

    int a = 0, b = 0;
    for (int i = 0; i < k; ++i) {
        if (r[i] == 0) {
            ++a;
        } else if (r[i] == 1) {
            ++b;
        }
    }

    cout << (a <= k / 2 && b <= k / 2 ? "YES\n" : "NO\n");
}