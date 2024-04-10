#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

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
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    // cin >> tests;

    while (tests--) {
        solve();
    }


#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        x[i] += 1e6;
        y[i] += 1e6;
    }

    vector<vector<int>> g(2);
    
    while (true) {   
        g[0].clear();
        g[1].clear(); 

        for (int i = 0; i < n; ++i) {
            g[(x[i] + y[i]) & 1].push_back(i);
        }

        if (sz(g[0]) > 0 && sz(g[1]) > 0) {
            cout << sz(g[0]) << endl;
            for (int id : g[0]) {
                cout << id + 1 << " ";
            }
            cout << endl;
            return;
        }

        if (sz(g[0]) == 0) {
            for (int i = 0; i < n; ++i) {
                x[i] += 1;
            }
        }

        g[0].clear();
        g[1].clear();
        
        for (int i = 0; i < n; ++i) {
            g[x[i] & 1].push_back(i);
        }

        if (sz(g[0]) > 0 && sz(g[1]) > 0) {
            cout << sz(g[0]) << endl;
            for (int id : g[0]) {
                cout << id + 1 << " ";
            }
            cout << endl;
            return;
        }

        if (sz(g[0]) == 0) {
            for (int i = 0; i < n; ++i) {
                x[i] += 1;
                y[i] += 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            x[i] /= 2;
            y[i] /= 2;
        }

   
    }





}