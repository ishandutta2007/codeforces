#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;

const int N = (int) 1e4 + 7;
const int K = (int) 20;
const int M = (int) 1e7 + 7;
vector <pair <int, int> > g[N];
int u[N];
int p[N];
int mum[N];
bool cycle[M];
pair <int, int> st[4 * N][K];
int bin[4 * N];
int tin[N], tout[N];
bool vis[N];
vector <int> pos, tos;
int in[N];
int n; 
int sz;

struct max_flow {

    const ll INF = (ll) (1e18);

    struct edge {
        int v, to, cap;
        edge(int a, int b, int c) {
            v = a, to = b, cap = c;
        }
        edge() {}
    };

    vector <edge> e;
    vector <vector <int> > g;
    vector <int> d;
    vector <int> st;
    int s, t;
    int n;

    void init(int n) {
        this->n = n;
        g.resize(n);
        st.resize(n);
    }

    void add_edge(int u, int v, int cap) {
        g[u].pb(e.size());
        e.pb({u, v, cap});
        g[v].pb(e.size());
        e.pb({v, u, 0});
    }

    bool bfs() {
        d.assign(n, -1);
        queue <int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto f : g[v]) {
                int to = e[f].to;
                if (d[to] == -1 && e[f].cap > 0) {
                    d[to] = d[v] + 1;
                    q.push(to);
                }
            }
        }
        return d[t] != -1;
    }

    ll dfs(int v, ll flow) {
        if (v == t) return flow;
        if (!flow) return 0;
        for (; st[v] < (int) g[v].size(); ++st[v]) {
            auto f = e[g[v][st[v]]];
            if (d[f.to] != d[v] + 1) continue;
            ll push = dfs(f.to, min(flow, (ll) f.cap));
            if (push) {
                e[g[v][st[v]]].cap -= push;
                e[g[v][st[v]] ^ 1].cap += push;
                return push;
            }
        }
        return 0;
    }

    ll find(int s, int t) {
        this->s = s, this->t = t;
        ll flow = 0;
        while (bfs()) {
            st.assign(n, 0);
            while (ll push = dfs(s, INF)) {
                flow += push;
            }
        }
        return flow;
    }

    max_flow() {}
};

pair <int, int> q(int l, int r) {
    if (l > r) swap(l, r);
    int p = bin[r - l + 1];
    return min(st[l][p], st[r - (1 << p) + 1][p]);
}


void ds(int v, int h) {
    vis[v] = 1;
    in[v] = pos.size();
    tos.pb(v);
    pos.pb(h);
    for (auto to : g[v]) {
        if (!vis[to.fc]) {
            ds(to.fc, h + 1);
            tos.pb(v);
            pos.pb(h);
        }
    }
}


void sparse() {
    sz = tos.size();
    for (int i = 2; i < 4 * N; i++) bin[i] = bin[i / 2] + 1;
    for (int i = sz - 1; i >= 0; i--) {
        st[i][0] = {pos[i], tos[i]};
        for (int j = 1; j < K; j++) {
            st[i][j] = min(st[i][j - 1], ((i + (1 << (j - 1)) < n) ? st[i + (1 << (j - 1))][j - 1] : mp(INT_MAX, -1)));
        }
    }
}

pair <int, int> gr(int a, int b) {
    if (a > b) swap(a, b);
    return {a, b};
}

void dfs(int v, int pr, int ch) {
    mum[v] = ch;
    u[v] = 1;
    p[v] = pr;
    for (auto to : g[v]) {
        if (!u[to.fc]) {
            dfs(to.fc, v, to.sc);
        }
    }
}

int lca(int a, int b) {
    return q(in[a], in[b]).sc;
}

int main() {

    max_flow flow;
    int start = clock();
    int n, m;
    vector <pair <pair <int, int>, int> > ed;
    scanf("%d%d", &n, &m);
   
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--, v--;
        g[u].pb({v, c});
        g[v].pb({u, c});
        ed.pb({gr(u, v), c});
    }
    dfs(0, 0, -1);
    ds(0, 0);
    sparse();
    flow.init(4 * m);
    int num = 0;
    int col = 2 * m;
    int s = 3 * m + 1, t = 3 * m + 2;
    for (int i = 0; i < m; i++) {
        if (!(p[ed[i].fc.fc] == ed[i].fc.sc || p[ed[i].fc.sc] == ed[i].fc.fc)) {
            int len = 0;
            flow.add_edge(num, col + ed[i].sc, 1);
            int f = lca(ed[i].fc.fc, ed[i].fc.sc);
            int v = ed[i].fc.fc;
            while (v != f) {
                cycle[v] = 1;
                flow.add_edge(num, col + mum[v], 1), len++;
                v = p[v];
            }
            v = ed[i].fc.sc;
            while (v != f) {
                cycle[v] = 1;
                flow.add_edge(num, col + mum[v], 1), len++;
                v = p[v];
            }
            flow.add_edge(s, num, len);
            num++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (p[ed[i].fc.fc] == ed[i].fc.sc || p[ed[i].fc.sc] == ed[i].fc.fc) {
            int u = ed[i].fc.fc, v = ed[i].fc.sc;
            if (p[u] == v) {
                swap(u, v);
            } 
            if (!cycle[v]) {
                flow.add_edge(num, col + ed[i].sc, 1);
                flow.add_edge(s, num, 1);
                num++;
            }
        }
    }
    for (int i = 1; i <= m; i++) flow.add_edge(col + i, t, 1);
    printf("%d\n", (int) (flow.find(s, t)));
}