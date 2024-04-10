#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 200005;
const int offset = 1 << 18;
const int LOG = 19;
const ll INF = (ll)5e18;

int N, M;
vector <pii> E[MAXN];
ll cost[MAXN];
int node[MAXN];
int dad[MAXN][LOG];
int depth[MAXN], sub[MAXN];
int head[MAXN], idx[MAXN], pos[MAXN];
int chain, ptr;
ll prod[2 * offset];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i < N; i++) {
        int u, v;        
        scanf("%d%d%I64d", &u, &v, cost + i);
        E[u].push_back(pii(v, i));
        E[v].push_back(pii(u, i));
    }
}

void dfs(int x, int p) {
    dad[x][0] = p;
    depth[x] = depth[p] + 1;
    sub[x] = 1;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        if (nxt == p) continue;
        node[E[x][i].second] = nxt;
        dfs(nxt, x);
        sub[x] += sub[nxt];
    }   
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

void hld(int x, int p, ll w) {
    if (!head[chain])
        head[chain] = x;
    idx[x] = chain;
    pos[x] = ptr;
    prod[ptr + offset] = w;
    ptr++;
    
    pii spec(0, 0);
    for (int i = 0; i < E[x].size(); i++) {
        pii nxt = E[x][i];
        if (nxt.first == p) continue;
        if (sub[nxt.first] > sub[spec.first])
            spec = nxt;
    }
    
    if (spec.first) 
        hld(spec.first, x, cost[spec.second]);
    
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        if (nxt == p || nxt == spec.first) continue;
        chain++;
        hld(nxt, x, cost[E[x][i].second]);
    }
}

ll mul(ll x, ll y) {
    return x > INF / y ? INF : x * y;
}

ll query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return 1;
    if (lo >= from && hi <= to) return prod[x];
    int mid = (lo + hi) / 2;
    return mul(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void update(int x, ll val) {
    x += offset;
    prod[x] = val;
    for (x /= 2; x; x /= 2)
        prod[x] = mul(prod[2 * x], prod[2 * x + 1]);
}

ll up(int x, int y) {
    if (x == y) return 1;
    ll res = 1;
    while (1) {
        int curr = idx[x];
        if (curr == idx[y]) {
            if (x == y) break;
            res = mul(res, query(1, 0, offset, pos[y] + 1, pos[x] + 1));
            break;
        }
        res = mul(res, query(1, 0, offset, pos[head[curr]], pos[x] + 1));
        x = dad[head[curr]][0];
    }
    return res;
}

ll get(int x, int y) {
    int l = lca(x, y);
    return mul(up(x, l), up(y, l));
}

void solve() {
    dfs(1, 0);
    
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= N; i++)
            dad[i][j] = dad[dad[i][j - 1]][j - 1];
    
    for (int i = 0; i < 2 * offset; i++)
        prod[i] = 1;
        
    hld(1, 0, 1);
    
    for (int i = offset - 1; i >= 0; i--)
        prod[i] = mul(prod[2 * i], prod[2 * i + 1]);
    
    while (M--) {
        int cmd, a, b;
        ll c;
        scanf("%d%d", &cmd, &a);
        if (cmd == 1) {
            scanf("%d%I64d", &b, &c);
            printf("%I64d\n", c / get(a, b)); 
        }
        else {
            scanf("%I64d", &c);
            update(pos[node[a]], c);
        }
    }
}

int main() {
    load();
    solve();
    return 0;
}