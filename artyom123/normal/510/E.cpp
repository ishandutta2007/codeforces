#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

struct Graph{
    struct edge{
        int c, f, link, to, ind;
        int c2 = 0;
        edge(){}
        edge(int c, int f, int link, int to, int ind) : c(c), f(f), link(link), to(to), ind(ind) {}

    };

    vector<vector<edge>> g;

    int s, t, n;

    Graph(int N, int S, int T) {
        n = N;
        s = S, t = T;
        g.resize(n);
    }

    vector<int> usd;

    int dfs(int v, int now) {
        usd[v] = 1;
        if (v == t) return now;
        for (auto &e : g[v]) {
            if (usd[e.to] || e.f == e.c) continue;
            int x = dfs(e.to, min(now, e.c - e.f));
            if (x == 0) continue;
            e.f += x;
            g[e.to][e.link].f -= x;
            return x;
        }
        return 0;
    }

    int Ford_Fulkerson() {
        int ans = 0;
        while (1) {
            usd.assign(n, 0);
            int d = dfs(s, INF);
            ans += d;
            if (d == 0) break;
        }
        return ans;
    }

    void add_not_dir(int a, int b, int c, int i) {
        g[a].pb(c, 0, g[b].size(), b, i);
        g[b].pb(c, 0, g[a].size() - 1, a, i);
    }

    void add_dir(int a, int b, int c, int i) {
        g[a].pb(c, 0, g[b].size(), b, i);
        g[b].pb(0, 0, g[a].size() - 1, a, i);
    }

    int Edmonds_Karp() {
        int ans = 0;
        while (1) {
            queue<int> q;
            vector<int> p(n, -1), dist(n, INF), mn(n, INF);
            q.push(s);
            dist[s] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto &e : g[v]) {
                    if (e.f == e.c || dist[e.to] != INF) continue;
                    p[e.to] = v;
                    q.push(e.to);
                    dist[e.to] = dist[v] + 1;
                    mn[e.to] = min(mn[v], e.c - e.f);
                }
            }
            if (dist[t] == INF) break;
            vector<int> path;
            int now = t;
            while (now != -1) {
                path.pb(now);
                now = p[now];
            }
            reverse(all(path));
            int F = mn[t];
            ans += F;
            for (int i = 0; i < (int)path.size() - 1; i++) {
                int v = path[i];
                for (auto &e : g[v]) {
                    if (e.to == path[i + 1] && e.c - e.f >= F) {
                        e.f += F;
                        g[e.to][e.link].f -= F;
                        break;
                    }
                }
            }
        }
        return ans;
    }

    vector<int> d, uk;

    int dfs_Dinic(int v, int now) {
        if (v == t || now == 0) return now;
        for (int i = uk[v]; i < (int)g[v].size(); i++) {
            if (d[g[v][i].to] == d[v] + 1) {
                int can = g[v][i].c2 - g[v][i].f;
                int x = dfs_Dinic(g[v][i].to, min(can, now));
                if (x != 0) {
                    g[v][i].f += x;
                    g[g[v][i].to][g[v][i].link].f -= x;
                    return x;
                }
            }
            uk[v]++;
        }
        return 0;
    }

    bool bfs() {
        d.assign(n, INF);
        d[s] = 0;
        deque<int> q;
        q.push_back(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            for (auto &e : g[v]) {
                if (e.f < e.c2 && d[e.to] == INF) {
                    d[e.to] = d[v] + 1;
                    q.push_back(e.to);
                }
            }
        }
        return d[t] != INF;
    }

    ll Dinic() {
        ll ans = 0;
        while (bfs()) {
            uk.assign(n, 0);
            while (1) {
                int d = dfs_Dinic(s, INF);
                if (d == 0) break;
                ans += d;
            }
        }
        return ans;
    }

    ll Fast_Dinic() {
        ll ans = 0;
        for (int j = 29; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < (int)g[i].size(); k++) {
                    if (g[i][k].c & (1 << j)) g[i][k].c2 += (1 << j);
                }
            }
            ans += Dinic();
        }
        return ans;
    }
};

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<int> usd;
vector<vector<int>> gr;

void dfs_ans(int v, vector<int> &comp) {
    comp.pb(v);
    usd[v] = 1;
    for (auto &to : gr[v]) {
        if (!usd[to]) dfs_ans(to, comp);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt0 = 0, cnt1 = 0;
    for (auto &c : a) {
        cin >> c;
        if (c % 2 == 0) cnt0++;
        else cnt1++;
    }
    if (cnt0 != cnt1) {
        cout << "Impossible";
        return 0;
    }
    Graph g(n + 2, n, n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            g.add_dir(n, i, 2, -1);
        } else {
            g.add_dir(i, n + 1, 2, i);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] % 2 == 1 && a[j] % 2 == 0) {
                if (is_prime(a[i] + a[j])) {
                    g.add_dir(i, j, 1, -1);
                }
            }
        }
    }
    int x = g.Edmonds_Karp();
    if (x != 2 * cnt0) {
        cout << "Impossible";
        return 0;
    }
    gr.resize(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        for (auto &e : g.g[i]) {
            if (e.f == 1) {
                gr[i].pb(e.to);
                gr[e.to].pb(i);
            }
        }
    }
    usd.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!usd[i]) {
            ans.pb(vector<int>());
            dfs_ans(i, ans.back());
        }
    }
    cout << ans.size() << "\n";
    for (auto &c : ans) {
        cout << c.size() << " ";
        for (auto &l : c) {
            cout << l + 1 << " ";
        }
        cout << "\n";
    }
	return 0;
}