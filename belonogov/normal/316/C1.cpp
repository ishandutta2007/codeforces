#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxN = 81;
const int maxNN = maxN * maxN;
const int inf = 1e9;
const int step[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

struct edge {
    int v, c, f, mf, idp;
    edge() { }
    edge(int v, int c, int f, int mf, int idp): v(v), c(c), f(f), mf(mf), idp(idp){}
};

vector < edge > e[maxNN];
int dist[maxNN];
int p[maxNN];
int idp[maxNN];
bool inQueue[maxNN];
int a[maxN][maxN];
queue < int > q;
int ans, n, m, fn, st;

int code(int v, int u) {
    return v * m + u;
}

void add(int v, int u, int f, int c) {
    int idv = e[v].size();
    int idu = e[u].size();
    e[v].pb(edge(u, c, 0, f, idu));
    e[u].pb(edge(v, -c, 0, 0, idv));
}

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}


void bfs() {
    int v;
    memset(dist, 63, sizeof(dist));
    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();     
        inQueue[v] = 0;
        for (int i = 0; i < (int)e[v].size(); i++) 
            if (dist[e[v][i].v] > dist[v] + e[v][i].c && e[v][i].f < e[v][i].mf) {
                dist[e[v][i].v] = dist[v] + e[v][i].c;
                p[e[v][i].v] = v;
                idp[e[v][i].v] = i;
                if (!inQueue[e[v][i].v]) {
                    q.push(e[v][i].v);
                    inQueue[e[v][i].v] = 1;
                }
            }
    }
    assert(dist[fn] < inf);
    v = fn;
    //cerr << "dist: " <<  dist[fn] << endl;
    for (;v != st;) {
        int newV = p[v];
        //cerr << "newV v: " << newV << " " << v << endl;
        e[newV][idp[v]].f++;
        ans += e[newV][idp[v]].c;
        e[v][e[newV][idp[v]].idp].f--;
        v = newV;
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 1) continue;
            for (int t = 0; t < 4; t++) {
                x = i + step[t][0];
                y = j + step[t][1];
                if (!check(x, y)) continue;
                add(code(i, j), code(x, y), 1, a[i][j] != a[x][y]);
            }
        }
    st = n * m;
    fn = n * m + 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if ((i + j) % 2 == 0)
                add(st, code(i, j), 1, 0);
            else
                add(code(i, j), fn, 1, 0);
        }
    //for (int i = 0; i <= fn; i++) {
        //cerr << "i: " << i << endl;
        //for (int j = 0; j < (int)e[i].size(); j++)
            //epr("v c f mf idp    %d %d %d %d %d\n", e[i][j].v, e[i][j].c, e[i][j].f, e[i][j].mf, e[i][j].idp);
    //}
    for (int i = 0; i < (n * m) / 2; i++) {
        bfs();
        //cerr << "ans: " << ans << endl;
    }
    printf("%d\n", ans);
    return 0;
}