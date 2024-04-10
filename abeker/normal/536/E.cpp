#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int offset = 1 << 17;
const int LOG = 17;

struct event {
    int a, b, c, id;
    event(int a, int b, int c, int id) : a(a), b(b), c(c), id(id) {}
    event() : a(0), b(0), c(0), id(0) {}
    bool operator <(const event &rhs) const {
        if (c != rhs.c) return c > rhs.c;
        return id < rhs.id;
    }
};

struct node {
    int sum, pref, suff, len;
    node(int sum, int pref, int suff, int len) : sum(sum), pref(pref), suff(suff), len(len) {}
    node() : sum(0), pref(0), suff(0), len(0) {}
};

int N, Q;
vector <pii> E[MAXN];
int f[MAXN];
vector <event> sweep;
int dad[MAXN][LOG];
int who[MAXN];
int depth[MAXN], sub[MAXN];
int head[MAXN], idx[MAXN], pos[MAXN];
int chain, ptr;
int sol[MAXN];
node t[2 * offset];

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i < N; i++)
        scanf("%d", f + i);
    for (int i = 1; i < N; i++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        E[u].push_back(pii(v, i));
        E[v].push_back(pii(u, i));
        sweep.push_back(event(u, v, l, i));
    }
    for (int i = 0; i < Q; i++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        sweep.push_back(event(u, v, l, N + i));
    }
}

void dfs(int x, int p) {
    dad[x][0] = p;
    depth[x] = depth[p] + 1;
    sub[x] = 1;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        if (nxt == p) continue;
        dfs(nxt, x);
        who[E[x][i].second] = nxt;
        sub[x] += sub[nxt];
    }
}

void hld(int x, int p) {
    if (!head[chain]) 
        head[chain] = x;
    idx[x] = chain;
    pos[x] = ptr++;
    
    int spec = 0;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        if (nxt != p && sub[nxt] > sub[spec])
            spec = nxt;
    }
    
    if (spec) hld(spec, x);
    
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        if (nxt != p && nxt != spec) {
            chain++;
            hld(nxt, x);
        }
    }
}

node merge(node L, node R) {
    node res;
    res.sum = L.sum + R.sum;
    if (L.suff && R.pref) res.sum += f[L.suff + R.pref] - f[L.suff] - f[R.pref];
    res.pref = L.pref;
    if (L.pref == L.len) res.pref = L.len + R.pref;
    res.suff = R.suff;
    if (R.suff == R.len) res.suff = L.suff + R.len;
    res.len = L.len + R.len;
    return res;
}

void update(int x) {
    x += offset;
    t[x] = node(f[1], 1, 1, 1);
    for (x /= 2; x; x /= 2)
        t[x] = merge(t[2 * x], t[2 * x + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return node();
    if (lo >= from && hi <= to) return t[x];
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for (int i = 0; i < LOG; i++)
        if (diff >> i & 1) x = dad[x][i];
    if (x == y) return x;
    for (int i = LOG - 1; i >= 0; i--)
        if (dad[x][i] != dad[y][i]) {
            x = dad[x][i];
            y = dad[y][i];
        }
    return dad[x][0];
}

node rev(node n) {
    swap(n.pref, n.suff);
    return n;
}

node up(int x, int y) {
    node res;
    while (1) {
        int curr = idx[x];
        if (curr == idx[y]) {
            res = merge(res, rev(query(1, 0, offset, pos[y] + 1, pos[x] + 1)));
            break;
        }
        res = merge(res, rev(query(1, 0, offset, pos[head[curr]], pos[x] + 1)));
        x = dad[head[curr]][0];
    }
    return res;
}

int get(int x, int y) {
    int l = lca(x, y);
    return merge(up(x, l), rev(up(y, l))).sum;
}

void solve() {
    dfs(1, 0);
    
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= N; i++)
            dad[i][j] = dad[dad[i][j - 1]][j - 1];
    
    hld(1, 0);
    
    for (int i = 0; i < N; i++) 
        t[i + offset] = node(0, 0, 0, 1);
    for (int i = offset - 1; i >= 0; i--)   
        t[i] = merge(t[2 * i], t[2 * i + 1]);
        
    
    sort(sweep.begin(), sweep.end());
    for (int i = 0; i < sweep.size(); i++) 
        if (sweep[i].id < N) 
            update(pos[who[sweep[i].id]]);
        else 
            sol[sweep[i].id - N] = get(sweep[i].a, sweep[i].b);
    
    for (int i = 0; i < Q; i++)
        printf("%d\n", sol[i]);    
}

int main() {
    load();
    solve();
    return 0;
}