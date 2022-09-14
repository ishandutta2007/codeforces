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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        zeros += a[i] == 0;
    }
    int l = 0, r = 0;
    for (int i = 0; i < n && a[i] == 0; ++i) {
        ++l;
    }
    for (int i = n - 1; i >= 0 && a[i] == 0; --i) {
        ++r;
    }
    if (l == n) {
        cout << 0 << endl;
    } else if (l + r == zeros) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}