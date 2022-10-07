#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 2e4 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int LOG = 20;

map<int,int> query;
vector<int> road;
map<int,int> help;

struct MaxFlow {
    const static int FLOW_N = 1e6;
    struct Edge {
        int u, f, mf;
        Edge() { }
        Edge(int _u, int _f, int _mf): u(_u), f(_f), mf(_mf) { }
    };
    
    int st;
    int fn;
    int all;
    vector<int> e[FLOW_N];
    vector<Edge> data;
    int dist[FLOW_N];
    int cur[FLOW_N];
    void addE(int v, int u, int f) {
        //db3(v, u, f);
        e[v].pb(data.size());
        data.pb(Edge(u, 0, f));
        e[u].pb(data.size());
        data.pb(Edge(v, 0, 0));
        all = max(all, v + 1);
        all = max(all, u + 1);
    }
    
    bool bfs() {
        queue<int> q;
        q.push(st);
        for (int i = 0; i < all; i++)
            dist[i] = INF;
        dist[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto id: e[v]) {
                auto x = data[id];
                int u = x.u;
                if (dist[u] > dist[v] + 1 && x.f < x.mf) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
        return dist[fn] < INF;
    }
    
    int dfs(int v, int flow) {
        if (v == fn) return flow;
        for (; cur[v] < (int)e[v].size(); cur[v]++) {
            int id = e[v][cur[v]];
            auto& x = data[id];
            if (dist[x.u] == dist[v] + 1 && x.f < x.mf) {
                int res = dfs(x.u, min(flow, x.mf - x.f));
                if (res > 0) {
                    x.f += res;
                    data[id ^ 1].f -= res;
                    return res;
                }
            }
        }
        return 0;
    }
    int getFlow() {
        int res = 0;
        while (bfs()) {
            //db(res);
            for (int i = 0; i < all; i++)
                cur[i] = 0;
            for (;;) {
                int tmp = dfs(st, INF);
                res += tmp;
                if (tmp == 0) 
                    break;
            }
        }
        return res;
    }

    bool used[FLOW_N];

    void dfs2(int v) {
        used[v] = 1;
        if (help.count(v)) {
            road.pb(help[v]);
        }
        if (query.count(v)) {
            query.erase(v);
        }
        for (auto id: e[v]) {
            Edge x = data[id];
            if (!used[x.u] && x.f < x.mf) {
                dfs2(x.u);
            }
        } 
    }

    void getRes() {
        memset(used, 0, sizeof used);
        dfs2(st);        
    }
};

int n, m;
vector<pair<int,int>> e[N];
int jump[LOG][N];
int id[LOG][N];
int h[N];
MaxFlow flow;
int cur;

void dfs(int v, int p, int pid) {
    //id[0][v] = cur++;
    jump[0][v] = p;
    if (v != p) {
        flow.addE(id[0][v], flow.fn, 1);
        help[id[0][v]] = pid;
    }
    for (int i = 1; i < LOG; i++) {
        jump[i][v] = jump[i - 1][jump[i - 1][v]];
        //id[i][v] = cur++;
        flow.addE(id[i][v], id[i - 1][v], INF); 
        flow.addE(id[i][v], id[i - 1][jump[i - 1][v]], INF); 
    }
    for (auto x: e[v]) if (x.F != p) {
        int u = x.F;
        h[u] = h[v] + 1;
        dfs(u, v, x.S);
    }
}

int getLCA(int v, int u, int vertId) {
    if (h[v] < h[u]) swap(v, u);
    int dh = h[v] - h[u];
    for (int i = 0; i < LOG; i++) {
        if (dh & pw(i)) {
            flow.addE(vertId, id[i][v], 1);
            v = jump[i][v];
        }
    }
    if (v == u) return v;
    for (int i = LOG - 1; i >= 0; i--) {
        if (jump[i][v] != jump[i][u]) {
            flow.addE(vertId, id[i][v], 1);
            flow.addE(vertId, id[i][u], 1);
            v = jump[i][v];
            u = jump[i][u];
        }
    }
    flow.addE(vertId, id[0][v], 1);
    flow.addE(vertId, id[0][u], 1);
    return jump[0][v];

}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb({u, i});
        e[u].pb({v, i});
    }
    flow.st = 0;
    flow.fn = 1;
    cur = 2;
    memset(id, -1, sizeof id);
    srand(time(NULL));
    //int st = rand() % n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < LOG; j++)
            id[j][i] = cur++;
    dfs(0, 0, -1);

    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        int vertId = cur++;
        flow.addE(flow.st, vertId, 1);
        query[vertId] = i;
        getLCA(v, u, vertId);
    }
    int res = flow.getFlow();
    flow.getRes();
    
    printf("%d\n", res);

    printf("%d ", (int)query.size());
    for (auto x: query) printf("%d ", x.S + 1);
    puts("");

    printf("%d ", (int)road.size());
    for (auto x: road) printf("%d ", x + 1);
    puts("");

#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}