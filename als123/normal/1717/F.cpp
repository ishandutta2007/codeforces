//test
#include <bits/stdc++.h>
template<class T>
struct Flow {
    const int n;
    struct Edge {
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
            	int v=e[i].to,c=e[i].cap;
                //auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            //auto [v, c] = e[i];
            int v=e[j].to,c=e[j].cap;
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
    //	printf("%d %d %d\n",u,v,c);
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T maxFlow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
};

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> u(m), v(m);
    for (int i = 0; i < m; i++) {
        std::cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        a[u[i]]++, a[v[i]]--;
    }
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 1 && a[i] % 2 != 0) {
            std::cout << "NO\n";
            return 0;
        }
        a[i] /= 2;
    }
    
    Flow<int> flow(n + 3);
    
    const int source = n, sink = n + 1, tmp = n + 2;
    
    for (int i = 0; i < m; i++) {
        flow.addEdge(u[i], v[i], 1);
    }
  //  printf("a:");for (int u=0;u<n;u++) printf("%d ",a[u]);printf("\n");
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            flow.addEdge(tmp, i, inf);
            flow.addEdge(i, tmp, inf);
        } else if (a[i] > 0) {
            flow.addEdge(source, i, a[i]);
            pos += a[i];
        } else {
            flow.addEdge(i, sink, -a[i]);
            neg -= a[i];
        }
    }
    
    if (pos > neg) {
        flow.addEdge(tmp, sink, pos - neg);
    } else {
        flow.addEdge(source, tmp, neg - pos);
    }
    
    if (flow.maxFlow(source, sink) != std::max(pos, neg)) {
        std::cout << "NO\n";
        return 0;
    }
    
    std::cout << "YES\n";
    for (int i = 0; i < m; i++) {
        if (flow.e[2 * i].cap == 1) {
            std::cout << u[i] + 1 << " " << v[i] + 1 << "\n";
        } else {
            std::cout << v[i] + 1 << " " << u[i] + 1 << "\n";
        }
    }
    
    return 0;
}