#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e6 + 10;
const int INF = 1e9;

struct query {
    int type, v, u;
    query() { }
    query(int type, int v, int u): type(type), v(v), u(u) { }
};

struct node {
    int p, r, d;
    node() { }
    node(int p, int r, int d): p(p), r(r), d(d) { }
};

int n, m;
vector < query > b;
node a[N];
vector < int > answer;
vector < pair < int, int > > edge;
vector < int > e[N];
queue < int > q;
int dist[N];
int ver[N];
bool use[N];
int tmr;

int getId(int v) {
    return (a[v].p == v)? v: a[v].p = getId(a[v].p);
}

void merge(int v, int u) {
    if (a[v].r < a[u].r)
        swap(v, u);
    a[u].p = v;
    a[v].d = max(a[v].d, a[v].r + a[u].r + 1);
    a[v].r = max(a[v].r, a[u].r + 1);
}

void read() {
    int v, u, type, qq;
    b.clear();
    if (scanf("%d%d%d", &n, &m, &qq) != 3) exit(0);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v, &u); 
        v--; u--;
        e[v].pb(u);
        e[u].pb(v);
        edge.pb(mp(v, u));
    }
    for (int i = 0; i < qq; i++) {
        scanf("%d%d", &type, &v); v--;
        if (type == 1)
            b.pb(query(type, v, -1));
        else {
            scanf("%d", &u); u--;
            b.pb(query(type, v, u));
        }
    }

}

pair < int, int > bfs(int v) {
    tmr++;
    dist[v] = 0;
    ver[v] = tmr;
    q.push(v);
    int res = 0;
    int where = v;
    while (!q.empty()) {
        use[v] = 1;
        v = q.front();
        q.pop();
        for (int u : e[v]) {
            if (ver[u] != tmr) {
                ver[u] = tmr;
                dist[u] = dist[v] + 1;
                q.push(u);
                if (dist[u] > res) {
                    res = dist[u];
                    where = u;
                }
            }
        }
    }
    return mp(res, where);
}


void solve() {
    int v, u;
    for (int i = 0; i < n; i++)
        a[i] = node(i, 0, 0);
    for (int i = 0; i < (int)edge.size(); i++) {
        v = getId(edge[i].fr);
        u = getId(edge[i].sc);
        if (v != u) 
            merge(v, u);
    }
    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            pair < int, int > tmp = bfs(i);
            tmp = bfs(tmp.sc);
            v = getId(i);
            a[v].d = tmp.fr;
            a[v].r = (tmp.fr + 1) / 2;
        }
    }

    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i].type == 1) {
            v = getId(b[i].v); 
            answer.pb(a[v].d);
        } 
        if (b[i].type == 2) {
            v = getId(b[i].v);
            u = getId(b[i].u);
            if (v == u) continue;
            merge(v, u);
        }
    }
}

void printAns() {
    for (int i = 0; i < (int)answer.size(); i++)
        printf("%d\n", answer[i]);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
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