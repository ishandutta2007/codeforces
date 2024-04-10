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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 

#define equal equalll
#define less lesss
const int N = 1000;
const int INF = 1e9;

struct Edge {
    int v, f, mf, pid;
    Edge() { }
    Edge(int v, int f, int mf, int pid): v(v), f(f), mf(mf), pid(pid) { } 
};

int n, m;
vector < Edge > g[N];
int data[N][N];
int a[N];
int b[N];
int st, fn, all;
int dist[N];
int cur[N];
int res[N][N];
queue < int > q;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        data[v][u] = data[u][v] = 1;
    }
}

void addE(int v, int u, int flow) {
    int szV = g[v].size();
    int szU = g[u].size(); 
    g[v].pb(Edge(u, 0, flow, szU));
    g[u].pb(Edge(v, 0, 0, szV));
}

int bfs() {
    memset(dist, 63, sizeof(dist));
    dist[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto x: g[v]) {
            int u = x.v;
            if (dist[u] > dist[v] + 1 && x.f < x.mf) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist[fn] < INF;
}


int dfs(int v, int flow) {
    if (v == fn)
        return flow;
    for (; cur[v] < (int)g[v].size(); cur[v]++) {
        auto &x = g[v][cur[v]];
        if (dist[x.v] == dist[v] + 1 && x.f < x.mf) {
            int r = dfs(x.v, min(flow, x.mf - x.f));
            if (r > 0) {
                x.f += r;
                g[x.v][x.pid].f -= r;
                return r;
            }
        }
    }
    return 0;
}

void ret(int x) {
    if (x == 0) {
        printf("NO\n");
        exit(0);
    }
}


void solve() {
    st = n * 2;
    fn = n * 2 + 1;
    all = n * 2 + 2;
    for (int i = 0; i < n; i++) {
        addE(st, i, a[i]);
        addE(i + n, fn, b[i]);
    }
    for (int i = 0; i < n; i++)
        data[i][i] = 1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            int flow = data[i][j] * INF;
            addE(i, j + n, flow);
        }
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += b[i];
        sum2 += a[i];
    }
    if (sum1 != sum2)
        ret(0);

    //cerr << "sdf\n";
    while (bfs()) {
        //cerr << "sdf\n";
        for (int i = 0; i < all; i++)
            cur[i] = 0;
        while (true) {
            int x = dfs(st, INF);
            //db(x);
            if (x == 0) break;

            sum1 -= x;
        }
    }
    assert(sum1 >= 0);
    if (sum1 > 0) ret(0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (int)g[i].size(); j++) {
            int v = g[i][j].v - n;
            if (0 <= v && v < n) {
                res[i][v] = g[i][j].f;
            }
        }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    } 
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}