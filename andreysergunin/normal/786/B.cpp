#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());
    
const ll INF = 1e18;

vector<vector<int>> g;
vector<vector<int>> cost;
vector<ll> dist;

void dejikstra(int s) {
    int n = sz(g);
    dist.resize(n);

    set<pair<ll, int>> st;
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
    }
    dist[s] = 0;

    for (int i = 0; i < n; ++i) 
        st.insert({dist[i], i});

    while (!st.empty()) {
        int v = st.begin()->second;
        // cout << v << " " << dist[v] << endl;
        st.erase(st.begin());
        for (int i = 0; i < sz(g[v]); ++i) {
            int u = g[v][i];
            if (dist[v] + cost[v][i] < dist[u]) {
                st.erase({dist[u], u});
                dist[u] = dist[v] + cost[v][i];
                st.insert({dist[u], u});
            }
        }
    }
}

vector<int> lft, rgh;

int build(int l, int r, int dir) {
    if (l + 1 == r)
        return l;
    
    int mid = (l + r) / 2;
    int u = build(l, mid, dir);
    int v = build(mid, r, dir);
    
    lft.push_back(u);
    rgh.push_back(v);
    int k = sz(g);
    g.push_back({});
    cost.push_back({});

    if (dir == 0) {
        g[k].push_back(lft[k]);
        g[k].push_back(rgh[k]);
        cost[k].push_back(0);
        cost[k].push_back(0);
    } else {
        g[lft[k]].push_back(k);
        g[rgh[k]].push_back(k);
        cost[lft[k]].push_back(0);
        cost[rgh[k]].push_back(0);
    }
    return k;
}

vector<int> nd;

void get(int v, int lf, int rg, int l, int r) {
    if (r <= lf || rg <= l)
        return;
    if (l <= lf && rg <= r) {
        nd.push_back(v);
        return;
    }

    int mid = (lf + rg) / 2;
    get(lft[v], lf, mid, l, r);
    get(rgh[v], mid, rg, l, r);
}



int main() {
    // freopen("jackpot.in", "r", stdin);
    // freopen("jackpot.out", "w", stdout);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //ifstream cin("breakfree.in");
    //ofstream cout("breakfree.out");
    
    int n, q, s;
    cin >> n >> q >> s;
    --s;

    g.resize(n);
    cost.resize(n);
    lft.resize(n);
    rgh.resize(n);

    int t1 = build(0, n, 0);
    int t2 = build(0, n, 1);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        // cout << "!" << type << endl;
        if (type == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            g[u].push_back(v);
            cost[u].push_back(w);
        } else if (type == 2) {
            int u, l, r, w;
            cin >> u >> l >> r >> w;
            --u; --l;
            get(t1, 0, n, l, r);
            // cout << "?" << sz(nd) << endl;
            for (int v : nd) {
                g[u].push_back(v);
                cost[u].push_back(w);
            }
            nd.clear();
        } else {
            int u, l, r, w;
            cin >> u >> l >> r >> w;
            --u; --l;;
            get(t2, 0, n, l, r);
            // cout << "?" << sz(nd) << endl;
            for (int v : nd) {
                g[v].push_back(u);
                cost[v].push_back(w);
            }
            nd.clear();
        }
    }

    // for (int i = 0; i < sz(g); ++i) {
    //     for (int j = 0; j < sz(g[i]); ++j)
    //         cout << g[i][j] << " ";
    //     cout << endl;
    // }

    dejikstra(s);

    for (int i = 0; i < n; ++i)
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    cout << endl;

}