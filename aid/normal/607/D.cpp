#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val, pr;
};

const int MAXN = 200 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int vv[MAXN], pv[MAXN], p[MAXN], heavy[MAXN], path[MAXN], pos[MAXN], n;
pair<int, int> qq[MAXN];
Node st[4 * MAXN];
vector<int> g[MAXN];

int dfs(int v) {
    int res = 1, maxSon = 0;
    heavy[v] = -1;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i], sz = dfs(u);
        if(sz > maxSon) {
            maxSon = sz;
            heavy[v] = u;
        }
        res += sz;
    }
    return res;
}

void buildst(int v, int tl, int tr) {
    st[v].pr = 0;
    if(tl == tr - 1) {
        st[v].val = pv[tl];
        return;
    }
    st[v].val = 0;
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
}

void push(int v) {
    if(!st[v].val)
        return;
    st[2 * v + 1].val += st[v].val;
    if(st[2 * v + 1].val >= MOD)
        st[2 * v + 1].val -= MOD;
    st[v].val = (long long)st[v].val * st[2 * v + 1].pr % MOD;
    st[2 * v].val += st[v].val;
    if(st[2 * v].val >= MOD)
        st[2 * v].val -= MOD;
    st[v].val = 0;
}

int update(int v, int tl, int tr, int pos) {
    if(tl == tr - 1) {
        st[v].pr++;
        return st[v].val;
    }
    push(v);
    int tm = (tl + tr) / 2, res;
    if(pos < tm)
        res = update(2 * v, tl, tm, pos);
    else
        res = update(2 * v + 1, tm, tr, pos);
    st[v].pr = (long long)st[2 * v].pr * st[2 * v + 1].pr % MOD;
    return res;
}

int add(int v, int tl, int tr, int l, int r, int val) {
    if(tl == l && tr == r) {
        st[v].val += val;
        if(st[v].val >= MOD)
            st[v].val -= MOD;
        return (long long)val * st[v].pr % MOD;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(r > tm)
        val = add(2 * v + 1, tm, tr, max(l, tm), r, val);
    if(l < tm)
        val = add(2 * v, tl, tm, l, min(r, tm), val);
    return val;
}

int get(int v, int tl, int tr, int pos) {
    if(tl == tr - 1)
        return (long long)st[v].val * st[v].pr % MOD;
    push(v);
    int tm = (tl + tr) / 2;
    if(pos < tm)
        return get(2 * v, tl, tm, pos);
    else
        return get(2 * v + 1, tm, tr, pos);
}

void updatePath(int v) {
    int val = update(1, 0, n, pos[v]);
    v = p[v];
    while(v >= 0) {
        val = add(1, 0, n, pos[path[v]], pos[v] + 1, val);
        v = p[path[v]];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> vv[0] >> q;
    p[0] = -1;
    n = 1;
    for(int i = 0; i < q; i++) {
        cin >> qq[i].first;
        if(qq[i].first == 1) {
            cin >> p[n] >> vv[n];
            p[n]--;
            g[p[n]].push_back(n);
            qq[i].second = n;
            n++;
        }
        else {
            cin >> qq[i].second;
            qq[i].second--;
        }
    }
    dfs(0);
    int curPos = 0;
    for(int i = 0; i < n; i++)
        if(p[i] == -1 || heavy[p[i]] != i) {
            for(int j = i; j >= 0; j = heavy[j]) {
                path[j] = i;
                pos[j] = curPos++;
            }
        }
    for(int i = 0; i < n; i++)
        pv[pos[i]] = vv[i];
    buildst(1, 0, n);
    updatePath(0);
    for(int i = 0; i < q; i++) {
        int v = qq[i].second;
        if(qq[i].first == 1) {
            updatePath(p[v]);
            updatePath(v);
        }
        else
            cout << get(1, 0, n, pos[v]) << '\n';
    }
    return 0;
}