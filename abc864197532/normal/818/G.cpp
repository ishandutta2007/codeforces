/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 5001, logN = 20, K = 111;

struct MCMF {
    const int INF = 1 << 30;
    struct edge {
        int v, id, revid, f, c;
        edge (int _v, int _f, int _c, int _id, int _revid) : v(_v), f(_f), c(_c), id(_id), revid(_revid) {}
    };
    vector <vector <edge>> adj;
    vector <pair <int, int>> rt;
    vector <int> dis;
    int n, s, t;
    MCMF (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
    }
    void add_edge(int u, int v, long long f, long long c) {
        test(u, v, f, c);
        adj[u].push_back(edge(v, f, c, adj[u].size(), adj[v].size()));
        adj[v].push_back(edge(u, 0, -c, adj[v].size(), adj[u].size() - 1));
    }
    bool SPFA() {
        rt.assign(n, make_pair(-1, -1));
        dis.assign(n, INF);
        vector <bool> vis(n, false);
        queue <int> q;
        q.push(s);
        dis[s] = 0;
        vis[s] = true;
        while (q.size()) {
            int v = q.front(); q.pop();
            vis[v] = false;
            for (edge &e : adj[v]) if (e.f > 0 && dis[e.v] > dis[v] + e.c) {
                    dis[e.v] = dis[v] + e.c;
                    rt[e.v] = make_pair(v, e.id);
                    if (!vis[e.v]) {
                        vis[e.v] = true;
                        q.push(e.v);
                    }
                }
        }
        return dis[t] != INF;
    }
    pair <int, int> runFlow() { // cost, flow
        int cost = 0, flow = 0;
        while (SPFA()) {
            vector <pair <int, int>> E;
            int v = t;
            int addflow = INF;
            while (v != s) {
                E.push_back(rt[v]);
                addflow = min(addflow, adj[rt[v].first][rt[v].second].f);
                v = rt[v].first;
            }
            for (pair <int, int> a : E) {
                adj[a.first][a.second].f -= addflow;
                adj[adj[a.first][a.second].v][adj[a.first][a.second].revid].f += addflow;
            }
            flow += addflow;
            cost += addflow * dis[t];
        }
        return make_pair(cost, flow);
    }
};

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    MCMF flow(n * 4 + 4, n * 4, n * 4 + 2);
    for (int i = 0; i < n; ++i) flow.add_edge(i + n, i, 1, -1);
    flow.add_edge(n * 4, n * 4 + 1, 4, 0);
    for (int i = 0; i < n; ++i) flow.add_edge(n * 4 + 1, i + n, 1, 0);
    for (int i = 0; i < n; ++i) flow.add_edge(i, n * 4 + 3, 1, 0);
    flow.add_edge(n * 4 + 3, n * 4 + 2, 4, 0);
    int ty = n * 2;
    vector <int> pre(7, -1);
    for (int i = 0; i < n; ++i) {
        int r = a[i] % 7;
        if (pre[r] != -1) {
            flow.add_edge(pre[r], ty, 1 << 20, 0);
        }
        flow.add_edge(i, ty, 1, 0);
        if (pre[r] != -1) flow.add_edge(pre[r], i + n, 1, 0);
        pre[r] = ty++;
    }
    pre.assign(100002, -1);
    for (int i = 0; i < n; ++i) {
        if (pre[a[i]] != -1) {
            flow.add_edge(pre[a[i]], ty, 1 << 20, 0);
        }
        flow.add_edge(i, ty, 1, 0);
        if (pre[a[i] - 1] != -1) flow.add_edge(pre[a[i] - 1], i + n, 1, 0);
        if (pre[a[i] + 1] != -1) flow.add_edge(pre[a[i] + 1], i + n, 1, 0);
        pre[a[i]] = ty++;
    }
    pii ans = flow.runFlow();
    assert(ans.Y == 4);
    cout << -ans.X << endl;
}