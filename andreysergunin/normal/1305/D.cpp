// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
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
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    while (tests--) {
       solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

const int MAXN = 1010;

set<int> g[MAXN];

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].insert(v);
        g[v].insert(u);
    }

    set<int> good;
    for (int i = 0; i < n; ++i) {
        good.insert(i);
    }

    for (int i = 0; i < n / 2; ++i) {
        vector<int> arr;
        for (int v : good) {
            if (sz(g[v]) == 1) {
                arr.push_back(v);
            }
        }
        assert(sz(arr) >= 2);
        int u = arr[0];
        int v = arr[1];
        cout << "? " << u + 1 << " " << v + 1 << endl;
        int w;
        cin >> w;
        --w;
        if (w == u || w == v) {
            cout << "! " << w + 1 << endl;
            return;
        } 
        for (int s : {u, v}) {
            int t = *g[s].begin();
            g[t].erase(s);
            g[s].erase(t);
        }
        good.erase(u);
        good.erase(v);
    }

    assert(sz(good) == 1);
    int v = *good.begin();
    cout << "! " << v + 1 << endl;
}