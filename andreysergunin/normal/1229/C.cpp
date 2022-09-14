#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 100100;

vector<int> g[MAXN];
int l[MAXN];
int r[MAXN];
ll diff[MAXN];

ll deg[MAXN];
int cnt[MAXN];

vector<int> up[MAXN];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        if (u < v) {
            swap(u, v);
        }
        ++l[u];
        ++r[v];
        ++deg[u];
        ++deg[v];
        up[v].push_back(u);
    }

    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += ll(l[i]) * r[i];
    }


    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int v;
        cin >> v;
        --v;
        diff[i] -= sz(up[v]) * (deg[v] - sz(up[v]));
        for (int u : up[v]) {
            diff[i] -= sz(up[u]) * (deg[u] - sz(up[u]));
            up[u].push_back(v);
            diff[i] += sz(up[u]) * (deg[u] - sz(up[u]));
        }
        up[v].clear();
    }

    cout << cur << endl;

    for (int i = 0; i < q; ++i) {
        cur += diff[i];
        cout << cur << endl;
    }




#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}