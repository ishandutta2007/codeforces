#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

struct network {
    int n;
    vector<int> to, cost, cap, dist;
    vector<vector<int>> g;
    
    network(int n): n(n), dist(n), g(n) {}
    
    void add_edge(int a, int b, int cst, int cp) {
        g[a].push_back(to.size());
        to.push_back(b);
        cap.push_back(cp);
        cost.push_back(cst);
    }
    
    void add(int a, int b, int cst, int cp = 1) {
        add_edge(a, b, cst, cp);
        add_edge(b, a, -cst, 0);
    }
    int total = 0;
    void mincost(int total) {
        do {
            vector<int> in_que(n), par(n);
            deque<int> que = {0};
            dist.assign(n, inf);
            dist[0] = 0;
            while(!que.empty()) { // SPFA
                int v = que.front();
                in_que[v] = 0;
                que.pop_front();
                for(auto it: g[v]) {
                    if(cap[it]) {
                        auto [u, c] = tie(to[it], cost[it]);
                        if(dist[v] + c < dist[u]) {
                            dist[u] = dist[v] + c;
                            par[u] = it;
                            if(!in_que[u]) {
                                que.push_back(u);
                                in_que[u] = true;
                            }
                        }
                    }
                }
            }
            if(dist[1] < inf) {
                vector<int> path;
                int t = 1;
                int mn = inf;
                while(t) {
                    auto it = par[t];
                    path.push_back(it);
                    mn = min(mn, cap[it]);
                    t = to[it ^ 1];
                }
                for(auto it: path) {
                    cap[it] -= mn;
                    cap[it ^ 1] += mn;
                }
                total -= mn;
            }
        } while(total > 0);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    network me(n + 2);
    vector<int> b(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        me.add(u + 2, v + 2, -1, inf);
        b[u] += w;
        b[v] -= w;
    }
    int total = 0;
    for(int i = 0; i < n; i++) {
        if(b[i] > 0) {
            total += b[i];
            me.add(0, i + 2, 0, b[i]);
        } else if(b[i] < 0) {
            me.add(i + 2, 1, 0, -b[i]);
        }
    }
    me.mincost(total);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = me.dist[i + 2];
    }
    int mn = *ranges::min_element(ans);
    for(auto it: ans) {
        cout << it - mn << ' ';
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;// cin >> t;
    while(t--) {
        solve();
    }
}