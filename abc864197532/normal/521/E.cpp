#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 2e5 + 87, logN = 20, K = 111, M = N * 20;

vector <pii> adj[N], edge;
vector <int> stk;
int low[N], dep[N], _t;
bool vis_vertex[N], vis_edge[N];

void out(vector <int> a) {
    cout << a.size() << ' ';
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] + 1 << " \n"[i == a.size() - 1];
}

struct BCC {
    vector <pii> adj[N];
    vector <int> cycle, path;
    bool vis[N], in_cycle[N], edge_dead[N];
    
    bool dfs1(int v, int pa, int st, int w) {
        if (~w)
            edge_dead[w] = true;
        cycle.pb(v);
        if (v == st)
            return true;
        vis[v] = true;
        for (auto [u, id] : adj[v]) if (u != pa) {
            if (!vis[u] && dfs1(u, v, st, id))
                return true;
        }
        if (~w)
            edge_dead[w] = false;
        cycle.pop_back();
        return false;
    }

    bool dfs2(int v, int pa) {
        path.pb(v);
        if (in_cycle[v] && path.size() > 1)
            return true;
        vis[v] = true;
        for (auto [u, id] : adj[v]) if (!edge_dead[id] && u != pa) {
            if (!vis[u] && dfs2(u, v))
                return true;
        }
        path.pop_back();
        return false;
    }

    void solve(vector <int> bcc) {
        vector <int> active_vertex;
        for (int id : bcc)
            active_vertex.push_back(edge[id].X), active_vertex.push_back(edge[id].Y);
        sort(all(active_vertex)), active_vertex.resize(unique(all(active_vertex)) - active_vertex.begin());
        int m = active_vertex.size();
        vector <int> in(m, 0);
        for (int id : bcc) {
            int u = lower_bound(all(active_vertex), edge[id].X) - active_vertex.begin();
            int v = lower_bound(all(active_vertex), edge[id].Y) - active_vertex.begin();
            adj[u].eb(v, id), adj[v].eb(u, id), in[u]++, in[v]++;
            test(u, v);
        }
        for (int i = 0; i < m; ++i) if (in[i] > 2) {
            assert(dfs1(adj[i][0].X, i, i, -1));
            edge_dead[adj[i][0].Y] = true;
            fill(vis, vis + m,  false);
            fill(in_cycle, in_cycle + m,  false);
            for (int v : cycle)
                in_cycle[v] = true;
            test(cycle);
            assert(dfs2(i, -1));
            // cycle, path
            rotate(cycle.begin(), cycle.end() - 1, cycle.end());
            cout << "YES\n";
            int to = find(all(cycle), path.back()) - cycle.begin();
            vector <int> a, b, c;
            for (int i = 0; i <= to; ++i)
                a.pb(active_vertex[cycle[i]]);
            b.pb(active_vertex[cycle[0]]);
            for (int i = cycle.size() - 1; i >= to; --i)
                b.pb(active_vertex[cycle[i]]);
            for (int i = 0; i < path.size(); ++i)
                c.pb(active_vertex[path[i]]);
            out(a), out(b), out(c);
            exit(0);
        }
        for (int i = 0; i < m; ++i)
            adj[i].clear();
        active_vertex.clear();
        fill(vis, vis + m, false);
    }
} solver;

void dfs(int v, int pa) {
    low[v] = dep[v] = _t++;
    vis_vertex[v] = true;
    for (auto [u, id] : adj[v]) if (u != pa) {
        if (!vis_edge[id])
            vis_edge[id] = true, stk.push_back(id);
        if (vis_vertex[u])
            low[v] = min(low[v], dep[u]);
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= dep[v]) {
                int x;
                vector <int> bcc;
                do {
                    x = stk.back(); stk.pop_back();
                    bcc.push_back(x);
                } while (x != id);
                solver.solve(bcc);
            }
        }
    }
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].eb(v, i), adj[v].eb(u, i);
        edge.eb(u, v);
    }
    for (int i = 0; i < n; ++i) if (!vis_vertex[i])
        dfs(i, -1);
    cout << "NO\n";
}