#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double; 
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
    int n, m, d;
    cin >> n >> d >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    sort(all(a));

    ll cur = 0;
    vector<int> s, b;
    for (int x : a) {
        if (x <= m) {
            cur += x;
            s.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    reverse(all(s));
    reverse(all(b));
    ll res = cur;

    for (int i = 1; i <= sz(b) && i * (d + 1) - d <= n; ++i) {
        while (sz(s) > 0 && sz(s) > n - d * (i - 1) - i) {
            cur -= s.back();
            s.pop_back();   
        }
        cur += b[i - 1];
        res = max(res, cur);
    }

    cout << res << endl;
}