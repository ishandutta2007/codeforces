#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int N = 2 * 1037;
const int C = 1e9 + 239;

namespace MinCostMaxFlow {
    const int INF = 1e18 + 239;

    struct Edge {
        int u;
        int v;
        int cost;
        int flow;
        int cap;

        Edge(){}

        Edge(int u_, int v_, int cost_, int flow_, int cap_) {
            u = u_;
            v = v_;
            cost = cost_;
            flow = flow_;
            cap = cap_;
        }
    };

    int n;
    int start;
    int end;

    int d[N];
    int p[N];
    int poten[N];
    vector<Edge> ed;
    vector<int> g[N];

    vector<int> path;

    void init_potent() {
        fill(d, d + n, INF);
        d[start] = 0;
        for (int i = 0; i < n; i++) {
            for (auto t : ed) {
                if (t.flow < t.cap && d[t.v] > d[t.u] + t.cost) {
                    d[t.v] = d[t.u] + t.cost;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            poten[i] = d[i];
        }
    }

    void renew_poten() {
        for (int i = 0; i < n; i++) {
            poten[i] = d[i];
        }
    }

    bool dij() {
        fill(d, d + n, INF);
        d[start] = 0;
        set<pair<int, int>> h;
        h.insert({d[start], start});
        while (!h.empty()) {
            int to = h.begin()->second;
            h.erase(h.begin());
            for (auto ind : g[to]) {
                auto e = ed[ind];
                int rc = e.cost + poten[e.u] - poten[e.v];
                if (e.flow < e.cap && poten[e.v] < INF && d[e.v] > d[e.u] + rc) {
                    h.erase({d[e.v], e.v});
                    d[e.v] = d[e.u] + rc;
                    h.insert({d[e.v], e.v});
                    p[e.v] = ind;
                }
            }
        }
        if (d[end] == INF) {
            return false;
        } else {
            for (int i = 0; i < n; i++) {
                d[i] -= poten[start];
                d[i] += poten[i];
            }
            path.clear();
            int cur = end;
            while (cur != start) {
                path.push_back(p[cur]);
                cur = ed[p[cur]].u;
            }
            return true;
        }
    }

    int run() {
        init_potent();
        while (dij()) {
            int S = 0;
            for (auto ind : path) {
                S += ed[ind].cost;
            }
            if (S > 0) break;
            int cur = INF;
            for (auto ind : path) {
                cur = min(cur, ed[ind].cap - ed[ind].flow);
            }
            for (auto ind : path) {
                ed[ind].flow += cur;
                ed[ind ^ 1].flow -= cur;
            }
            renew_poten();
        }
        int ans = 0;
        for (auto t : ed) {
            ans += t.flow * t.cost;
        }
        return ans / 2;
    }

    void init(int n_, int start_, int end_) {
        n = n_;
        start = start_;
        end = end_;
    }

    void add_edge(int u, int v, int cost, int cap) {
        int f = (int)ed.size();
        ed.push_back(Edge(u, v, cost, 0, cap));
        ed.push_back(Edge(v, u, -cost, 0, 0));
        g[u].push_back(f);
        g[v].push_back(f + 1);
    }

    vector<int> P;

    void dfs(int cur) {
        for (auto ind : g[cur]) {
            if (ed[ind].flow > 0) {
                ed[ind].flow--;
                ed[ind ^ 1].flow++;
                P.push_back(ed[ind].v);
                dfs(ed[ind].v);
                return;
            }
        }
    }

    vector<int> recover() {
        P = {start};
        dfs(start);
        return P;
    }
}

vector<int> res;

int d;

int inf(int x) {
    return 0 <= x && x < (1 << d);
}

int ins(int x) {
    return inf(x - (1 << d));
}

int get(int x) {
    for (int i = 0; i < d; i++) {
        if (x == (1 << i)) {
            return d - 1 - i;
        }
    }
    assert(false);
    return -1;
}

bool it() {
    vector<int> p = MinCostMaxFlow::recover();
    if (p.size() == 1) return 0;
    for (int i = 0; i + 1 < (int)p.size(); i++) {
        if (inf(p[i]) && ins(p[i + 1])) {
            res.push_back(get(p[i] ^ (p[i + 1] - (1 << d))));
        }
    }
    res.push_back(-1);
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> d >> n;
    int ST = 2 * (1 << d);
    int EN = 2 * (1 << d) + 1;
    MinCostMaxFlow::init((2 << d) + 2, ST, EN);
    for (int f = 0; f < (1 << d); f++) {
        for (int s = 0; s < d; s++) {
            if (!((f >> s) & 1)) {
                MinCostMaxFlow::add_edge(f, f + (1 << s) + (1 << d), 1, C);
            }
        }
    }
    for (int f = 0; f < 1; f++) {
        MinCostMaxFlow::add_edge(ST, f, 0, C);
    }
    for (int f = 0; f < (1 << d); f++) {
        MinCostMaxFlow::add_edge(f, EN, 1, C);
    }
    for (int f = 0; f < (1 << d); f++) {
        MinCostMaxFlow::add_edge(f + (1 << d), f, 0, C);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int c = 0;
        for (auto x : s) {
            c *= 2;
            c += (x - '0');
        }
        MinCostMaxFlow::add_edge(c + (1 << d), c, -C, 1);
    }
    int ans = MinCostMaxFlow::run();
    ans += n * C;
    cout << ans - 1 << endl;
    while (it()) {
        //
    }
    res.pop_back();
    for (auto t : res) {
        if (t == -1) {
            cout << 'R' << ' ';
        } else {
            cout << t << ' ';
        }
    }
    cout << '\n';
}