#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAXN = 100 * 1000 + 5, MAXM = 1005;

struct Node {
    bitset<MAXM> bs;
    int sh;
};

int a[MAXN], tin[MAXN], tout[MAXN], m;
Node st[4 * MAXN];
bitset<MAXM> ans, bsm;
vector<int> g[MAXN], p, primes;

void dfs(int v, int par) {
    tin[v] = p.size();
    p.push_back(v);
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != par)
            dfs(g[v][i], v);
    tout[v] = p.size();
}

void rot(bitset<MAXM> &bs, int x) {
    bs = ((bs << x) | (bs >> (m - x))) & bsm;
}

void buildst(int v, int tl, int tr) {
    st[v].sh = 0;
    if(tl == tr - 1) {
        st[v].bs.reset();
        st[v].bs[a[p[tl]]] = true;
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    st[v].bs = (st[2 * v].bs | st[2 * v + 1].bs);
}

void push(int v) {
    if(!st[v].sh)
        return;
    rot(st[2 * v].bs, st[v].sh);
    st[2 * v].sh += st[v].sh;
    if(st[2 * v].sh >= m)
        st[2 * v].sh -= m;
    rot(st[2 * v + 1].bs, st[v].sh);
    st[2 * v + 1].sh += st[v].sh;
    if(st[2 * v + 1].sh >= m)
        st[2 * v + 1].sh -= m;
    st[v].sh = 0;
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if(tl == l && tr == r) {
        rot(st[v].bs, x);
        st[v].sh += x;
        if(st[v].sh >= m)
            st[v].sh -= m;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(l < tm)
        update(2 * v, tl, tm, l, min(r, tm), x);
    if(r > tm)
        update(2 * v + 1, tm, tr, max(l, tm), r, x);
    st[v].bs = (st[2 * v].bs | st[2 * v + 1].bs);
}

void get(int v, int tl, int tr, int l, int r) {
    if(tl == l && tr == r) {
        ans |= st[v].bs;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(l < tm)
        get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        get(2 * v + 1, tm, tr, max(l, tm), r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, -1);
    buildst(1, 0, n);
    for(int i = 2; i < m; i++) {
        bool ok = true;
        for(int j = 2; j * j <= i; j++)
            if(!(i % j)) {
                ok = false;
                break;
            }
        if(ok)
            primes.push_back(i);
    }
    bsm.reset();
    for(int i = 0; i < m; i++)
        bsm[i] = true;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int qt;
        cin >> qt;
        if(qt == 1) {
            int v, x;
            cin >> v >> x;
            v--;
            x %= m;
            update(1, 0, n, tin[v], tout[v], x);
        }
        else {
            int v;
            cin >> v;
            v--;
            ans.reset();
            get(1, 0, n, tin[v], tout[v]);
            int cnt = 0;
            for(size_t j = 0; j < primes.size(); j++)
                if(ans[primes[j]])
                    cnt++;
            cout << cnt << '\n';
        }
    }
    return 0;
}