#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node *l, *r;

    Node(int val): val(val), l(0), r(0) {}

    Node(Node *l, Node *r): val(l->val + r->val), l(l), r(r) {}
};

const int MAXN = 100 * 1000 + 5;
int path[MAXN], tin[MAXN], tout[MAXN], t, n, pos;
long long d[MAXN];
Node *st[MAXN];
pair<long long, int> srt[MAXN];
vector< pair<int, int> > g[MAXN];
bool b;

void dfs(int v, int p) {
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, w = g[v][i].second;
        if(u == p)
            continue;
        d[u] = d[v] + w;
        dfs(u, v);
    }
}

void getPath(int v, int p) {
    tin[v] = t;
    path[t] = v;
    t++;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, w = g[v][i].second;
        if(u == p)
            continue;
        d[u] = d[v] + w;
        getPath(u, v);
    }
    tout[v] = t;
}

Node *buildst() {
    Node *root = new Node(0);
    for(int i = 0; i < 20; i++)
        root = new Node(root, root);
    return root;
}

Node *add(Node *v, int tl, int tr, int pos, int val) {
    if(tl == tr - 1)
        return new Node(v->val + val);
    int tm = (tl + tr) / 2;
    if(pos < tm)
        return new Node(add(v->l, tl, tm, pos, val), v->r);
    else
        return new Node(v->l, add(v->r, tm, tr, pos, val));
}

int get(Node *v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r)
        return v->val;
    int tm = (tl + tr) / 2, res = 0;
    if(l < tm)
        res += get(v->l, tl, tm, l, min(r, tm));
    if(r > tm)
        res += get(v->r, tm, tr, max(l, tm), r);
    return res;
}

int getAns(long long l) {
    int rr = 0, res = 0;
    for(int i = 0; i < n; i++) {
        int v = path[srt[i].second];
        while(rr < n && srt[rr].first < d[v] + l + 1)
            rr++;
        res = max(res, ((v == pos && b)? -1 : 0) +
                  get(st[rr], 0, n, tin[v], tout[v]));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        g[x].push_back(make_pair(y, w));
        g[y].push_back(make_pair(x, w));
    }
    dfs(0, -1);
    int v = 0;
    for(int i = 1; i < n; i++)
        if(d[v] < d[i])
            v = i;
    d[v] = 0;
    dfs(v, -1);
    int u = 0;
    for(int i = 1; i < n; i++)
        if(d[u] < d[i])
            u = i;
    pos = u;
    int pr = -1;
    while(2 * d[pos] > d[u]) {
        int to;
        for(size_t i = 0; i < g[pos].size(); i++) {
            int x = g[pos][i].first, w = g[pos][i].second;
            if(d[x] + w == d[pos]) {
                to = x;
                break;
            }
        }
        pr = pos;
        pos = to;
    }
    if(2 * d[pos] < d[u]) {
        b = true;
        for(size_t i = 0; i < g[pos].size(); i++)
            if(g[pos][i].first == pr) {
                swap(g[pos][i], g[pos].back());
                g[pos].pop_back();
                break;
            }
        for(size_t i = 0; i < g[pr].size(); i++)
            if(g[pr][i].first == pos) {
                swap(g[pr][i], g[pr].back());
                g[pr].pop_back();
                break;
            }
        int dpos = d[u] / 2 - d[pos], dpr = d[pr] - (d[u] + 1) / 2,
            dd = min(dpr, dpos);
        dpos -= dd;
        dpr -= dd;
        g[pos].push_back(make_pair(n, dpos));
        g[n].push_back(make_pair(pos, dpos));
        g[pr].push_back(make_pair(n, dpr));
        g[n].push_back(make_pair(pr, dpr));
        pos = n;
        n++;
    }
    d[pos] = 0;
    getPath(pos, -1);
    for(int i = 0; i < n; i++)
        srt[i] = make_pair(d[path[i]], i);
    sort(srt, srt + n);
    st[0] = buildst();
    for(int i = 0; i < n; i++)
        st[i + 1] = add(st[i], 0, n, srt[i].second, 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        long long l;
        cin >> l;
        cout << getAns(l) << '\n';
    }
    return 0;
}