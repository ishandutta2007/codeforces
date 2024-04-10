#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;

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

// ----------------------------------------------------------------- 

const int INF = 1e9 + 1;

void solve() {  
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> f(k + 1, INF);

    for (int i = 0; i + n - m + 1 <= n; ++i) {
        int lf = i;
        int rg = i + n - m + 1;
        int cur = max(a[lf], a[rg - 1]);
        for (int j = 0; j <= k; ++j) {
            if (lf >= j && n - rg >= k - j && (lf <= m - 1 - k + j || n - rg <= m - 1 - k + (k - j))) {
                f[j] = min(f[j], cur);
            }
        }
    }

    int res = 0;
    for (int x : f) {
        res = max(res, x);;
    }
    cout << res << endl;

}