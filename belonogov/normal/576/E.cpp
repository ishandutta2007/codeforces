#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

const int N = 5e5 + 10;
const int INF = 1e9 + 19;
const int K = 51;

struct Rev {
    int * ptr;
    int val;
    Rev(int *ptr, int val): ptr(ptr), val(val) { }
};

struct CEdge {
    int v, u, color;
    CEdge(int v, int u, int color): v(v), u(u), color(color) { }
};

int n, m, k, q;
pair < int, int > edge[N];
pair < int, int > query[N];
int h[K][N];
pair < int, int > p[K][N];
vector < int > where[N];
vector < Rev > stac;
vector < CEdge > data[N * 4];
int color[N];


void read() {
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &edge[i].fr, &edge[i].sc);
        edge[i].fr--;
        edge[i].sc--;
    }
    for (int i = 0; i < q; i++) {
        int e, color;
        scanf("%d%d", &e, &color);
        e--; color--;
        query[i] = mp(e, color);
    }
}

pair < int, int > getId(int v, int color) {
    int cnt = 0;
    for (; p[color][v].fr != v; v = p[color][v].fr)
        cnt += p[color][v].sc;
    return mp(v, cnt % 2);
}

void merge(int v, int u, int w, int color) {
    if (h[color][v] > h[color][u]) swap(v, u);

    stac.pb(Rev(&(p[color][v].fr), p[color][v].fr));
    stac.pb(Rev(&(p[color][v].sc), p[color][v].sc));
    p[color][v] = mp(u, w);
    if (h[color][v] == h[color][u]) {
        stac.pb(Rev(&(h[color][v]), h[color][v]));
        h[color][u]++;
    }
}

void addSeg(int v, int ll, int rr, int l, int r, int id, int c) {
    if (ll >= r || l >= rr) return;
    if (l <= ll && rr <= r) {
        data[v].pb(CEdge(edge[id].fr, edge[id].sc, c));
        return;
    } 
    addSeg(v * 2 + 1, ll, (ll + rr) / 2, l, r, id, c);
    addSeg(v * 2 + 2, (ll + rr) / 2, rr, l, r, id, c);
}

void rec(int v, int ll, int rr) {
    int cur = stac.size();
    for (auto x: data[v]) {
        auto r1 = getId(x.v, x.color);
        auto r2 = getId(x.u, x.color);
        if (r1.fr != r2.fr)
            merge(r1.fr, r2.fr, r1.sc == r2.sc, x.color);
    } 

    if (ll + 1 == rr) {
        int id = query[ll].fr;
        int c = query[ll].sc;
        auto r1 = getId(edge[id].fr, c);
        auto r2 = getId(edge[id].sc, c);
        int nc = color[id];
        if (r1.fr != r2.fr || r1.sc != r2.sc) {
            puts("YES");
            nc = c; 
        }
        else
            puts("NO");
    
        if (nc != -1) {
            int pos = lower_bound(where[id].begin(), where[id].end(), ll) - where[id].begin();
            assert(where[id][pos] == ll);
            int r = q;
            if (pos + 1 < (int)where[id].size())
                r = where[id][pos + 1] + 1;
            addSeg(0, 0, q, ll + 1, r, id, nc);
        }

        color[id] = nc;
    }
    else {
        rec(v * 2 + 1, ll, (ll + rr) / 2);
        rec(v * 2 + 2, (ll + rr) / 2, rr);
    }
    for (; cur < (int)stac.size(); stac.pop_back())
        *(stac.back().ptr) = stac.back().val; 
}

void solve() {
    for (int j = 0; j < K; j++)
        for (int i = 0; i < n; i++)
            p[j][i] = mp(i, 0);

    for (int i = 0; i < q; i++) 
        where[query[i].fr].pb(i);

    memset(color, -1, sizeof(color));
    rec(0, 0, q);
}


int main(){
    read();
    solve();
}