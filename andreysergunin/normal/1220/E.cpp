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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);
    
const int MAXN = 200200;
int w[MAXN];
int deg[MAXN];

ll d[4][MAXN];
vector<int> ch[MAXN];

int used[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }

    int s;
    cin >> s;
    --s;

    set<pii> setik;
    for (int i = 0; i < n; ++i) {
        setik.insert({deg[i], i});
        for (int k = 1; k < 4; ++k) {
            d[k][i] = -1;
        }
    }

    ll res = 0;
    bool ok = true;
    while (sz(setik) > 0) {
        pii p = *setik.begin();
        if (p.first > 1) {
            ok = false;
        } 
        setik.erase(p);

        int v = p.second;
        // cout << "! " << ok << " " << v << endl;
        // for (int u : ch[v]) {
        //     cout << u << " ";
        // }
        // cout << endl;

        int t = -1;
        for (int u : ch[v]) {
            d[0][v] = max(d[0][v], d[0][u] + w[u]);
            if (d[1][u] != -1) {
                t = u;
            }
        }

        if (t != -1) {
            d[1][v] = d[1][t] + w[t];
            d[2][v] = 0;
            for (int u : ch[v]) {
                if (u == t) {
                    continue;
                }
                d[2][v] = max(d[2][v], d[0][u] + w[u]);
            }
            d[2][v] += d[1][v];
            d[3][v] = max(d[2][v], d[3][t] + w[t]);
        }

        if (v == s) {
            d[1][v] = 0;
            d[2][v] = d[0][v];
            d[3][v] = d[0][v];
        }
        if (d[2][v] != -1) {
            res = max(res, d[2][v] + w[v]);
        }

        if (ok) {
            used[v] = 1;
            for (int u : g[v]) {
                if (used[u]) {
                    continue;
                }
                setik.erase({deg[u], u});
                --deg[u];
                setik.insert({deg[u], u});
                ch[u].push_back(v);
                break;
            }    
        }
    }


    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            sum += w[i];    
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i] && d[3][i] != -1) {
            res = max(res, sum + d[3][i]);
            sum += d[1][i];
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i] && d[3][i] == -1) {
            res = max(res, sum + d[0][i]);
        }
    }

    cout << res << endl;

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}