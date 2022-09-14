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
    freopen("input.txt", "r", stdin);
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
    ll n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<ll> a(k);
    for (ll &x : a) {
        cin >> x;
    } 

    bool ok = false;
    for (int i = 0; i < k; ++i) {
        ok |= a[i] >= n * m;
    }

    for (int t = 0; t < 2; ++t) {
        ll cnt = 0;
        bool big = false;
        for (int i = 0; i < k; ++i) {
            if (a[i] >= 2 * n) {
                big |= a[i] >= 3 * n;
                cnt += min(m - 2, a[i] / n);
            }
        }
        ok |= cnt >= m && ((m & 1) == 0 || big);
        swap(n, m);
    }

    cout << (ok ? "Yes\n" : "No\n");
}