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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct Past {
    int v, p, w;
};

vector<Past> used;

vector<int> w;
vector<int> p;

int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return get(p[v]);
}

bool merge(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
        return false;
    }
    if (w[u] < w[v]) {
        swap(u, v);
    }
    used.push_back({u, p[u], w[u]});
    used.push_back({v, p[v], w[v]});
    p[v] = u;
    w[u] += w[v];
    return true;
}

struct Edge {
    int u, v, w;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

map<int, vector<pair<int, vector<Edge>>> > query;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges.push_back({u, v, w});
    }
    vector<Edge> copy = edges;
    sort(all(edges));
    p.resize(n);
    w.resize(n);
    for (int i = 0; i < n; ++i) {
        w[i] = 1;
        p[i] = i;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int cnt = 0;
        cin >> cnt;
        vector<Edge> e;
        for (int j = 0; j < cnt; ++j) {
            int id;
            cin >> id;
            --id;
            e.push_back(copy[id]);
        }
        sort(all(e));
        for (int j = 0; j < sz(e); ) {
            int l = j;
            for (; l < sz(e) && e[j].w == e[l].w; ++l) {};

            vector<Edge> x;
            for (int k = j; k < l; ++k) {
                x.push_back(e[k]);
            }
            query[e[j].w].push_back({i, x});
            j = l;
        }
    }

    vector<int> ok(q, true);

    for (int i = 0; i < m; ) {
        for (auto el : query[edges[i].w]) {
            int id = el.first;
            vector<Edge> v = el.second;

            for (int j = 0; j < sz(v); ++j) {
                ok[id] &= merge(v[j].u, v[j].v);
            }
            for (int j = sz(used) - 1; j >= 0; --j) {
                p[used[j].v] = used[j].p;
                w[used[j].v] = used[j].w;
            }
            used.clear();
        }

        int j = i;
        for (; j < m && edges[j].w == edges[i].w; ++j) {};

        for (int k = i; k < j; ++k) {
            if (merge(edges[k].u, edges[k].v)) {
            }
        }

        used.clear();
        i = j;
    }

    for (int i = 0; i < q; ++i) {
        cout << (ok[i] ? "YES\n" : "NO\n");
    }
    
}