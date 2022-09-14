#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
// using ld = long double; 
using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

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

    if (n == 2) {
        cout << -1 << endl;
        return;
    }

    int m = n & 1;
    while (m * m <= n) {
        m += 2;
    }
    m -= 2;

    // m * m + 2 * m * k >= n;
    // k >= (n - m * m) / (2 * m)

    int k = (n - m * m + 2 * m - 1) / (2 * m);

    cout << m + k << endl;
    // cerr << m << " " << k << endl;

    vector<string> res(m + k, string(m + k, 'o'));
    for (int i = m; i < m + k; ++i) {
        for (int j = m; j < m + k; ++j) {
            res[i][j] = '.';
        }
    }
    int cur = (m + k) * (m + k) - k * k - n;
    for (int i = m - 1; cur > 0; cur -= 2, --i) {
        res[i][m + k - 1] = res[m + k - 1][i] = '.';
    }

    reverse(all(res));
    for (int i = 0; i < m + k; ++i) {
        cout << res[i] << endl;
    }

}