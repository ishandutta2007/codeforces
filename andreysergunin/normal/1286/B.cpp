#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

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

const int MAXN = 2222;
vector<int> g[MAXN];
int c[MAXN];
int w[MAXN];
int a[MAXN];
int p[MAXN];
int n;

int dfs(int v) {
    w[v] = 1;
    for (int u : g[v]) {
        w[v] += dfs(u);
    }
    return w[v];
}   

void solve() {
    cin >> n;

    int root = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> c[i];
        --p[i];
        if (p[i] >= 0) {
            g[p[i]].push_back(i);
        } else {
            root = i;
        }
    }   

    dfs(root);


    for (int i = 0; i < n; ++i) {
        c[i] = w[i] - c[i];
    }

    for (int i = 0; i < n; ++i) {
        int opt = -1;

        for (int j = 0; j < n; ++j) {
            if (a[j]) {
                continue;
            }

            if (opt == -1 || pii(c[opt], -w[opt]) > pii(c[j], -w[j])) {
                opt = j;
            }
        }

        if (c[opt] != 1) {
            cout << "NO" << endl;
            return;
        }

        a[opt] = n - i;

        int v = opt;
        while (v != -1) {
            --c[v];
            v = p[v];
        }
    }


    cout << "YES" << endl;

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;



}