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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txst", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int  &x : p) {
        cin >> x;
    }

    vector<int> f(n), g(n);
    int maxx = 0, cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (p[i - 1] < p[i]) {
            f[i] = f[i - 1] + 1;
        }
        if (maxx < f[i]) {
            maxx = f[i];
            cnt = 1;
        } else if (maxx == f[i]) {
            ++cnt;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (p[i + 1] < p[i]) {
            g[i] = g[i + 1] + 1;
        }
        if (maxx < g[i]) {
            maxx = g[i];
            cnt = 1;
        } else if (maxx == g[i]) {
            ++cnt;
        }
    }

    cerr << maxx << " " << cnt << endl;

    int res = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (f[i] == maxx && g[i] == maxx && cnt == 2 && maxx % 2 == 0) {
            ++res;
        }
    }

    cout << res << endl;


}