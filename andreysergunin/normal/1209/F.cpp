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
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 1000500;
const int P = 1e9 + 7;

vector<int> g[MAXN];
vector<int> w[MAXN];
int d[MAXN];

vector<int> block[MAXN];
int id[MAXN];
int res[MAXN];
pii minn[MAXN];
int val[MAXN];

int cnt;

void add(int u, int v, int val) {
    vector<int> dig;
    while (val > 0) {
        dig.push_back(val % 10);
        val /= 10;
    }
    reverse(all(dig));

    int cur = v;
    for (int i = 0; i < sz(dig) - 1; ++i) {
        g[cur].push_back(cnt);
        w[cur].push_back(dig[i]);
        cur = cnt++;
    }
    g[cur].push_back(u);
    w[cur].push_back(dig.back());

    cur = u;
    for (int i = 0; i < sz(dig) - 1; ++i) {
        g[cur].push_back(cnt);
        w[cur].push_back(dig[i]);
        cur = cnt++;
    }
    g[cur].push_back(v);
    w[cur].push_back(dig.back());
}

void solve() {
    int n, m;
    cin >> n >> m;
    cnt = n;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        add(u, v, i + 1);
    } 

    for (int i = 0; i < cnt; ++i) {
        d[i] = 100 * n;
    } 
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    for (int i = 0; i < cnt; ++i) {
        block[d[i]].push_back(i);
    }

    id[0] = 0;
    res[0] = 0;
    val[0] = 0;

    for (int i = 0; i < cnt; ++i) {
        minn[i] = {100 * m, 0};
    }

    for (int i = 1; sz(block[i]) > 0; ++i) {
        vector<pii> p;
        for (int v : block[i - 1]) {
            for (int j = 0; j < sz(g[v]); ++j) {
                int u = g[v][j];
                int dig = w[v][j];

                if (d[v] + 1 == d[u]) {
                    minn[u] = min(minn[u], {id[v], dig});
                }
            }
        }
        for (int v : block[i]) {
            p.push_back(minn[v]);
        }

        sort(all(p));
        p.resize(unique(all(p)) - p.begin());
        for (int v : block[i]) {
            id[v] = lower_bound(all(p), minn[v]) - p.begin();
            res[v] = ((ll)val[minn[v].first] * 10 + minn[v].second) % P;
        }
        for (int v : block[i]) {
            val[id[v]] = res[v];
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << res[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif  

    int tests = 1;
    // cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }
    
#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}