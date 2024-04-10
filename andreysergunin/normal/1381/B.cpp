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
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    vector<int> arr;
    int cnt = 1;
    int cur = a[0];
    for (int i = 1; i <= 2 * n; ++i) {
        if (i == 2 * n || cur < a[i]) {
            arr.push_back(cnt);
            cnt = 0;
            cur = a[i];
        } 
        ++cnt;
    }
    vector<int> s(2 * n + 1);
    s[0] = 1;
    for (int x : arr) {
        for (int i = 2 * n - x; i >= 0; --i) {
            if (s[i]) {
                s[i + x] = 1;
            }
        }
    }

    cout << (s[n] ? "YES\n" : "NO\n");
}