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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 222;
const long long INF = 1e9 + 19;

struct Edge {
    int v, f, mf, c, pid;
};


int n, m;
int st, fn, all;
vector < Edge > e[N];

void addE(int v, int u, int f, int c) {
    //cerr << "addE: " << v << " " << u << " " << f << " " << c  << endl;
    int szV = e[v].size();    
    int szU = e[u].size();
    e[v].pb({u, 0, f, c, szU});
    e[u].pb({v, 0, 0, -c, szV});
}

int dist[N];
bool inq[N];
int p[N];
int pid[N];
int answer = 0;

bool bfs() {
    memset(inq, 0, sizeof(inq));
    memset(dist, 63, sizeof(dist));
    queue < int > q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inq[v] = 0;
        for (int i = 0; i < (int)e[v].size(); i++) {
            auto x = e[v][i];
            int u = x.v;
            if (dist[u] > dist[v] + x.c && x.f < x.mf) {
                dist[u] = dist[v] + x.c;
                p[u] = v;
                pid[u] = i;
                //mnFlow[u] = min(mnFlow[v], x.mf - x.f);
                if (!inq[u]) {
                    q.push(u);
                    inq[u] = 1;
                }
            }
        }
    }
    if (dist[fn] < INF) {
        int flow = INF;
        int v = fn;
        for (; v != st; v = p[v])
            flow = min(flow, e[p[v]][pid[v]].mf - e[p[v]][pid[v]].f);
        v = fn;

        answer += flow * dist[fn];
        for (; v != st; v = p[v]) {
            int u = p[v];
            int id = pid[v];
            e[u][id].f += flow;
            e[v][e[u][id].pid].f -= flow;
        }

        return 1;
    }
    return 0;

}


void read() {
    scanf("%d%d", &n, &m);
    st = n;
    fn = n + 1;
    all = n + 2;
    addE(n - 1, 0, INF, 0);
    for (int i = 0; i < m; i++) {
        int v, u, c, f;
        scanf("%d%d%d%d", &v, &u, &c, &f); v--; u--; 
        addE(st, u, f, 0);
        addE(v, fn, f, 0);
        if (f <= c) {
            addE(u, v, f, 1);
            addE(v, u, c - f, 1);
            addE(v, u, INF, 2);
        }
        else {
            answer += f - c;
            addE(u, v, f - c, 0);
            addE(u, v, c, 1);
            addE(v, u, INF, 2);
        }
    }
}



void solve() {
    while (bfs());

    cout << answer << endl;
}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}