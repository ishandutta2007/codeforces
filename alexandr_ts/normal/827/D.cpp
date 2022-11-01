#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int LOG = 19;
const ll INF = 1e9 + 10;

struct Edge {
    int v;
    int u;
    int w;
    int num;
    bool inSpan;
};

vector<Edge> edges;
vector<int> g[N];

int tin[N], tout[N];
int par[N];
int height[N];

int tim = 1;
int jump[LOG][N];
int minEdge[LOG][N];

void dfs(int v, int h = 0) {
    height[v] = h;
    tin[v] = tim++;
    for (auto i: g[v]) {
        if (!edges[i].inSpan) {
            continue;
        }
        int u = (edges[i].v == v ? edges[i].u : edges[i].v);
        if (!tin[u]) {
            par[u] = v;
            minEdge[0][u] = edges[i].w;
            dfs(u, h + 1);
        }
    }
    tout[v] = tim++;
}

void precJumps(int n) {
    for (int i = 0; i < n; i++)
        jump[0][i] = par[i];
    for (int pw = 1; pw < LOG; pw++) {
        for (int i = 0; i < n; i++) {
            jump[pw][i] = jump[pw - 1][jump[pw - 1][i]];
            minEdge[pw][i] = max(minEdge[pw - 1][i], minEdge[pw - 1][jump[pw - 1][i]]);
        }
    }
}

bool cmp(Edge& a, Edge& b) {
    if (a.w != b.w)
        return a.w < b.w;
    return a.num < b.num;
}

bool cmpBack(Edge& a, Edge& b) {
    return a.num < b.num;
}

int rnkDsu[N];
int parDsu[N];

void buildSet(int v) {
    rnkDsu[v] = 1;
    parDsu[v] = v;
}

int findSet(int v) {
    if (parDsu[v] == v) return v;
    return parDsu[v] = findSet(parDsu[v]);
}

void unionSets(int v, int u) {
    int v1 = findSet(v);
    int u1 = findSet(u);
    if (v1 == u1) return;
    if (rnkDsu[v1] < rnkDsu[u1]) swap(v1, u1);
    parDsu[u1] = v1;
    rnkDsu[v1] += rnkDsu[u1];
}

void buildSpan(int n, int m) {
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < n; i++) {
        buildSet(i);
    }
    for (auto& edge: edges) {
        if (findSet(edge.v) != findSet(edge.u)) {
            edge.inSpan = true;
            unionSets(edge.v, edge.u);
        }
    }
    sort(edges.begin(), edges.end(), cmpBack);
}

bool isAncestor(int v, int anc) {
    return tin[anc] <= tin[v] && tout[v] <= tout[anc];
}

int findLca(int v, int u) {
    //cout << "findLca: " << v << " " << u << "\n ";
    if (isAncestor(v, u)) return u;
    if (isAncestor(u, v)) return v;
    for (int pw = LOG - 1; pw >= 0; pw--) {
        if (!isAncestor(u, jump[pw][v]))
            v = jump[pw][v];
    }
    //cout << "newv: " << par[v] << " " << u << endl;
    //cout << tin[v] << " " << tout[v] << endl;
    //cout << tin[u] << " " << tout[u] << endl;
    assert(!isAncestor(u, v));
    assert(isAncestor(u, par[v]));
    return par[v];
}

int findMinEdge(int v, int lca) {
    if (v == lca) return 0;
    int h = height[v] - height[lca];
    assert(h > 0);
    int ans = 0;
    for (int pw = LOG - 1; pw >= 0; pw--) {
        if (h & (1 << pw)) {
            ans = max(ans, minEdge[pw][v]);
            v = jump[pw][v];
        }
    }
    assert(v == lca);
    return ans;
}

int answer[N];

multiset<int> openVal[N], closeVal[N];

void dfs2(int v) {
    for (auto i: g[v]) {
        int u = (edges[i].v == v ? edges[i].u : edges[i].v);
        if (isAncestor(u, v) && edges[i].inSpan) {
            dfs2(u);
            if (openVal[u].size()) {
//                if (*openVal[u].begin() == edges[i].w)
//                    answer[edges[i].num] = edges[i].w - 1;
//                else
//                    answer[edges[i].num] = edges[i].w;
                answer[edges[i].num] = (*openVal[u].begin()) - 1;
            }
        }
    }

    int bigu = -1;
    for (auto i: g[v]) {
        int u = (edges[i].v == v ? edges[i].u : edges[i].v);
        if (isAncestor(u, v) && edges[i].inSpan) {
            if (bigu == -1 || openVal[bigu].size() < openVal[u].size())
                bigu = u;
        }
    }

    if (bigu != -1 && openVal[v].size() < openVal[bigu].size()) {
        openVal[v].swap(openVal[bigu]);
    }

    for (auto i: g[v]) {
        int u = (edges[i].v == v ? edges[i].u : edges[i].v);
        if (isAncestor(u, v) && edges[i].inSpan) {
            for (auto x: openVal[u])
                openVal[v].insert(x);
        }
    }

    for (auto x: closeVal[v]) {
        assert(openVal[v].count(x));
        openVal[v].erase(openVal[v].find(x));
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    fill(answer, answer + m, -1);

    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].pb(edges.size());
        g[u].pb(edges.size());
        edges.pb({v, u, w, i, false});
    }

    buildSpan(n, m);

//    cout << "spantree: \n";
//    for (int i = 0; i < m; i++)
//        if (edges[i].inSpan)
//            cout << edges[i].v << " " << edges[i].u << endl;
//    cout << "-----------\n";

    par[0] = 0;
    minEdge[0][0] = INF;
    dfs(0);

//    cout << "pars: \n";
//    for (int i = 0; i < n; i++)
//        cout << "par: " << i << " " << par[i] << "\n";
//    cout << "-----------\n";

    precJumps(n);

    for (auto& edge: edges) {
        if (!edge.inSpan) {
            int v = edge.v;
            int u = edge.u;
            int lca = findLca(v, u);
            int minEdgeVal = max(findMinEdge(v, lca), findMinEdge(u, lca));
            answer[edge.num] = minEdgeVal - 1;

            if (v != lca) {
                openVal[v].insert(edge.w);
                closeVal[lca].insert(edge.w);
            }

            if (u != lca) {
                openVal[u].insert(edge.w);
                closeVal[lca].insert(edge.w);
            }
        }
    }

    dfs2(0);

    for (int i = 0; i < m; ++i)
        cout << answer[i] << " ";
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    solve();
}