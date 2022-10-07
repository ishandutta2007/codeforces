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
const int N = 111;
const int INF = 1e9 + 19;

struct Edge {
    int v, f, mf, pid;
    Edge() { }
    Edge(int v, int f, int mf, int pid): v(v), f(f), mf(mf), pid(pid) { }
};

int n, m;
int a[N];
int b[N];
int all[N];
vector < pair < int, int > > edge;
vector < Edge > e[N];
int dist[N];
int cur[N];
int S, T;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        all[i] = x;
        if (i % 2 == 0)
            a[i / 2] = x;
        else
            b[i / 2] = x;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        if (v % 2 == 1)
            swap(v, u);
        edge.pb(mp(v / 2, u / 2));
    }
}

void addE(int v, int u, int f) {
    //cerr << "v u f: " << v << " " << u << " " << f << endl;
    int szV = e[v].size();
    int szU = e[u].size();
    e[v].pb(Edge(u, 0, f, szU));
    e[u].pb(Edge(v, 0, 0, szV));
}

bool bfs() {
    memset(dist, 63, sizeof(dist));
    dist[S] = 0;
    queue < int > q;
    q.push(S);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto x: e[v]) {
            int u = x.v;
            if (dist[u] > dist[v] + 1 && x.f < x.mf) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    //for (int i = 0; i < n + 2; i++)
        //cerr << dist[i] << " ";
    //cerr << endl;
        
    return dist[T] < INF;
}

int dfs(int v, int flow) {
    if (v == T) 
        return flow;
    for (; cur[v] < (int)e[v].size(); cur[v]++) {
        auto & x = e[v][cur[v]];
        int u = e[v][cur[v]].v;
        if (dist[u] > dist[v] && x.f < x.mf) {
            int r = dfs(u, min(flow, x.mf - x.f)); 
            if (r > 0) {
                x.f += r;  
                e[u][x.pid].f -= r;
                return r;
            }
        }
    }
    return 0;
}

void solve() {
    set < int > q; 
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int x = all[i];
        for (int j = 2; j * j <= x; j++)
            for (; x % j == 0; x /= j) 
                q.insert(j);
        if (x > 1)
            q.insert(x);
    }
    int L = (n + 1) / 2;
    int R = n / 2;

    for (auto p: q) {
        //db(p);
        S = n;
        T = n + 1;
        for (int i = 0; i < n + 2; i++)
            e[i].clear();
        for (int i = 0; i < L; i++) {
            int k = 0;
            int x = a[i];
            for (; x % p == 0; x /= p, k++);
            addE(S, i, k);
        }
        for (int i = 0; i < R; i++) {
            int k = 0; 
            int x = b[i];
            for (; x % p == 0; x /= p, k++);
            addE(L + i, T, k);
        }
        for (auto x: edge)
            addE(x.fr, x.sc + L, INF);
        while (bfs()) {
            //db("here");
            memset(cur, 0, sizeof(cur));
            while (true) {
                int x = dfs(S, INF);
                if (x == 0) break;
                    answer += x;
            }
        }

    }
    cout << answer << endl;


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