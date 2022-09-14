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
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int op = 0; op < 2; ++op) {
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << " ";        
            }   
        }
        cout << endl;
        return;
    }

    cout << "Second" << endl;

    vector<vector<int>> p(n);
    for (int i = 0; i < 2 * n; ++i) {
        int t;
        cin >> t;
        --t;
        p[t].push_back(i);
    }

    vector<vector<pii>> g(n);

    for (int i = 0; i < n; ++i) {
        g[p[i][0] % n].push_back({p[i][1], i});
        g[p[i][1] % n].push_back({p[i][0], i});
    }

    vector<int> used(n);
    vector<int> res(n, -1);

    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        int cur = i;

        int prv = -1;
        while (!used[cur]) {
            used[cur] = 1;
            if (g[cur][0].second == prv) {
                swap(g[cur][0], g[cur][1]);
            }
            prv = g[cur][0].second;
            res[g[cur][0].second] = g[cur][0].first;
            cur = g[cur][0].first % n;
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += res[i] + 1;
    }

    if (sum % (2 * n) != 0) {
        for (int i = 0; i < n; ++i) {
            res[i] = p[i][0] + p[i][1] - res[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] + 1 << " ";
    }
    cout << endl;


}