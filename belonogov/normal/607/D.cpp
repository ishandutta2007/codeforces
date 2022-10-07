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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

struct Query {
    int type, v, u, val;
    void read() {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d", &v, &val);
        }
        else
            scanf("%d", &v);
        v--;
    }
};

void mul(int & a, int b) {
    a = (a * 1ll * b) % MOD;
}

struct SegTree {
    vector < int > data;
    vector < int > upd;
    int sz;
    void init(int n) {
        sz = n;
        data.resize(sz * 4);
        upd.assign(sz * 4, 1);
    }
    void push(int v) {
        if (upd[v] != 1) {
            mul(upd[v * 2 + 1], upd[v]);
            mul(upd[v * 2 + 2], upd[v]);
            mul(data[v * 2 + 1], upd[v]);
            mul(data[v * 2 + 2], upd[v]);
            upd[v] = 1;
        }
    }

    int getSum(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return 0;
        if (l <= ll && rr <= r) return data[v];
        push(v);
        int res = (getSum(v * 2 + 1, ll, (ll + rr) / 2, l, r) +
                getSum(v * 2 + 2, (ll + rr) / 2, rr, l, r));
        if (res >= MOD) res -= MOD;
        return res;
    }

    void setPos(int v, int ll, int rr, int pos, int val) {
        if (ll + 1 == rr) {
            data[v] = val;
            return;
        }
        push(v);
        if (pos < (ll + rr) / 2)
            setPos(v * 2 + 1, ll, (ll + rr) / 2, pos, val);
        else
            setPos(v * 2 + 2, (ll + rr) / 2, rr, pos, val);
        data[v] = data[v * 2 + 1] + data[v * 2 + 2];
        if (data[v] >= MOD) data[v] -= MOD;
    }

    void mulSeg(int v, int ll, int rr, int l, int r, int val) {
        //if (l >= rr || ll >= r) return;
        if (l <= ll && rr <= r) {
            mul(data[v], val);
            mul(upd[v], val);
            return;
        }
        push(v);
        if (l < (ll + rr) / 2)
            mulSeg(v * 2 + 1, ll, (ll + rr) / 2, l, r, val);
        if ((ll + rr) / 2 < r)
            mulSeg(v * 2 + 2, (ll + rr) / 2, rr, l, r, val); 
        data[v] = data[v * 2 + 1] + data[v * 2 + 2];
        if (data[v] >= MOD) data[v] -= MOD;
    }
};

int val[N];
Query q[N];
vector < int > e[N];
int n;
int tin[N];
int tout[N];
int tmr;
int sz[N];
int par[N];
int cur = 1;


int rev(int a, int m) {
    if (a == 0) return 0;
    int x = (1 - rev(m % a, a) * 1ll * m) / a;
    if (x < 0) x += m;
    if (x >= m) x -= m;
    return x;
}

void read() {
    scanf("%d%d", &val[0], &n);
    for (int i = 0; i < n; i++) {
        q[i].read();
    }
}

void dfs(int v) {
    tin[v] = tmr++;
    for (auto u: e[v]) {
        par[u] = v;
        dfs(u);
    }

    tout[v] = tmr;
}

SegTree tree;

int getMulRoot(int v) {
    int tmp = tree.getSum(0, 0, cur, tin[v], tin[v] + 1);
    int rem = rev(val[v], MOD);
    mul(tmp, rem);
    return tmp;
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (q[i].type == 1) {
            e[q[i].v].pb(cur);
            q[i].u = cur;
            val[cur] = q[i].val;
            cur++;
        }
    }
    for (int i = 0; i < cur; i++)
        sz[i] = 1;
    dfs(0);
    tree.init(cur);
    tree.setPos(0, 0, cur, tin[0], val[0]); 
    for (int i = 0; i < n; i++) {
        if (q[i].type == 1) {
            int par = q[i].v;
            int v = q[i].u;
            int r = rev(sz[par], MOD);
            tree.mulSeg(0, 0, cur, tin[par], tout[par], r);
            tree.setPos(0, 0, cur, tin[v], val[v] * 1ll * getMulRoot(par) % MOD);
            sz[par]++;
            tree.mulSeg(0, 0, cur, tin[par], tout[par], sz[par]);
        }
        else {
            int v = q[i].v;
            int val = tree.getSum(0, 0, cur, tin[v], tout[v]);
            int tmp = 1;
            if (v != 0)
                tmp = getMulRoot(par[v]);
            int rem = rev(tmp, MOD);
            mul(val, rem);
            printf("%d\n", (int)val);
        }
    }

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
        }
    }
    else {
        stress();
    }

    return 0;
}