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
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;
const int LOG = 20;

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
        e[v].pb(data.size());
        data.pb(Edge(u, 0, f));
        e[u].pb(data.size());
        data.pb(Edge(v, 0, 0));
    }
    
    int myq[FLOW_N];
    bool bfs() {
        int curL = 0;
        int curR = 0;
        //queue<int> q;

        //q.push(st);
        myq[curR++] = st;
        for (int i = 0; i < all; i++)
            dist[i] = INF;
        dist[st] = 0;
        //while (!q.empty()) {
        while (curL != curR) {
            int v = myq[curL++];
            //int v = q.front();
            //q.pop();
            for (auto id: e[v]) {
                auto x = data[id];
                int u = x.u;
                if (dist[u] > dist[v] + 1 && x.f < x.mf) {
                    dist[u] = dist[v] + 1;
                    myq[curR++] = u;
                    //q.push(u);
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
};


struct Event {
    int t, y;
    int l, r;
};

MaxFlow flow;
int cur;

struct SparseTable {
    vector<int> table[LOG]; 
    vector<int> deg;
    void build(vector<int> a, bool flagDown) {
        table[0] = a;
        deg.pb(0);
        deg.pb(0);
        for (int i = 2; i <= sz(a); i++) {
            deg.pb(deg[i / 2] + 1);
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + pw(j) <= sz(a); i++) {
                //db2(i, j);
                table[j].pb(cur);
                if (flagDown) {
                    flow.addE(cur, table[j - 1][i], INF);
                    flow.addE(cur, table[j - 1][i + pw(j - 1)], INF);
                }
                else {
                    flow.addE(table[j - 1][i], cur, INF);
                    flow.addE(table[j - 1][i + pw(j - 1)], cur, INF);
                }
                cur++;
            }            
        }
    }
    pair<int,int> ask(int l, int r) {
        int k = deg[r - l];
        return {table[k][l], table[k][r - pw(k)]};
    }
};



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    //freopen("test.txt", "r", stdin);
#endif
    int n, Q;
    vector<Event> event; 
    if (true) {
        scanf("%d%d", &n, &Q);
        for (int i = 0; i < Q; i++) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2); 
            x1--;
            y1--;
            event.pb({y1, y2, x1, x2});
        }
    }
    else {
        n = 10000;
        Q = 10000;
        for (int i = 0; i < Q; i++) {
            int x1, y1, x2, y2;
            x1 = rand() % n + 1;
            x2 = rand() % n + 1;
            y1 = y2 = i + 1;
            if (x1 > x2) swap(x1, x2);
            x1--;
            y1--;
            event.pb({y1, y2, x1, x2});
        }
    }



    event.pb({n, n, 0, n});
    sort(all(event), [](Event A, Event B) {
                return A.t < B.t;
            });
    flow.st = n * 2;
    flow.fn = n * 2 + 1;
    vector<int> L;    
    vector<int> R;

    for (int i = 0; i < n; i++) {
        L.pb(i);
        flow.addE(flow.st, i, 1);
    }
    for (int i = 0; i < n; i++) {
        R.pb(i + n);
        flow.addE(i + n, flow.fn, 1);
    }

    cur = n * 2 + 2;
    SparseTable tableL;
    SparseTable tableR;
    //db(cur);
    tableL.build(L, 0);
    tableR.build(R, 1);
    //db(cur);

    vector<int> h(n);

    set<pair<int,int>> q;
    q.insert({0, n});
    h[0] = 0;
    for (auto E: event) {
        //db2(E.t, E.y);
        auto it = q.lower_bound({E.l, n + 1});
        assert(it != q.begin());
        it--;
        vector<pair<int,int>> seg;
        for (;;) {
            if (it == q.end()) break;
            if (E.r <= it->F) break;
            seg.pb(*it);
            auto itNext = it;
            itNext++;
            q.erase(it);
            it = itNext;
        }
        for (auto S: seg) {
            int tl = max(S.F, E.l);
            int tr = min(S.S, E.r);
            assert(tl < tr);
            int x = h[S.F];
            int y = E.t;
            //db3(x, y, S.F);
            if (x < y) {
                auto B1 = tableL.ask(x, y);
                auto B2 = tableR.ask(tl, tr);
                //db2(tl, tr);
                //db2(x, y);
                for (auto v: {B1.F, B1.S})
                    for (auto u: {B2.F, B2.S})
                        flow.addE(v, u, INF);
            }
            if (S.F < E.l) {
                q.insert({S.F, E.l});
            }
            if (E.r < S.S) {
                q.insert({E.r, S.S});
                h[E.r] = x;
            }
        }
        q.insert({E.l, E.r});
        h[E.l] = E.y;
    }
    flow.all = cur;

    db2(cur, flow.data.size());
    cout << flow.getFlow() << endl;
    db2(cur, flow.data.size());
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}