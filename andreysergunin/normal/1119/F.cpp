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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 250250;

struct Edge {
    int to, c;
};

vector<Edge> g[MAXN];
int deg[MAXN];
int used[MAXN];
ll dp[MAXN][2];
int ptr[MAXN];
ll sum[MAXN];
set<pii> setik[MAXN];

bool comp(int i, int j) {
    return deg[i] > deg[j];
}

bool comp1(Edge i, Edge j) {
    return deg[i.to] > deg[j.to];
}

void dfs(int v, int d, int p = -1) {
    used[v] = 1;
    int k = 0;
    while (k < sz(g[v]) && deg[g[v][k].to] > d) {
        ++k;
    }
    for (int i = k; i < ptr[v]; ++i) {
        if (g[v][i].to == p) {
            continue;
        }
        setik[v].insert({g[v][i].c, g[v][i].to});
        sum[v] += g[v][i].c;
    }
    ptr[v] = k;

    while (sz(setik[v]) > deg[v] - d) {
        auto it = --setik[v].end();
        sum[v] -= it->first;
        setik[v].erase(it);
    }

    for (int i = 0; i < k; ++i) {   
        if (g[v][i].to == p) {
            continue;
        }
        dfs(g[v][i].to, d, v);
    }

    vector<pii> add, del;   

    ll f = 0;

    for (int i = 0; i < k; ++i) {
        if (g[v][i].to == p) {
            continue;
        }
        int u = g[v][i].to;
        f += dp[u][0];
        pii p = {dp[u][1] + g[v][i].c - dp[u][0], u};
        del.push_back(p);
        sum[v] += p.first;
        setik[v].insert(p);
    }

    while (sz(setik[v]) > deg[v] - d) {
        auto it = --setik[v].end();
        pii p = *it;
        if (p.first <= 0) {
            break;
        }
        add.push_back(p);
        sum[v] -= p.first;
        setik[v].erase(p);
    }


    if (!setik[v].empty()) {
        dp[v][1] = f + sum[v] - max(0, (--setik[v].end())->first);
    } else {
        dp[v][1] = f + sum[v];
    }
    dp[v][0] = f + sum[v];

    for (pii p : add) {
        sum[v] += p.first;
        setik[v].insert(p);
    }

    for (pii p : del) {
        sum[v] -= p.first;
        setik[v].erase(p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    ll cost = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        cost += c;
        --u; --v;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        ++deg[u];
        ++deg[v];
    }   

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    sort(all(p), comp);

    for (int i = 0; i < n; ++i) {
        int m = sz(g[i]); 
        vector<Edge> q(m);
        for (int j = 0; j < m; ++j) {
            q[j] = g[i][j];
        }
        sort(all(q), comp1);

        for (int j = 0; j < m; ++j) {
            g[i][j] = q[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        ptr[i] = deg[i];
    }

    cout << cost << " ";
    for (int d = 1; d <= n - 1; ++d) {   
        int m = 0;
        while (m < n && deg[p[m]] > d) {
            ++m;
        }   
        for (int i = 0; i < m; ++i) {
            used[p[i]] = 0;
        }

        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            if (!used[p[i]]) {
                dfs(p[i], d);
                ans += dp[p[i]][0];
            }
        }

        cout << ans << " ";
    }
    cout << endl;

}