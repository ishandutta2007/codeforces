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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const int G = 1024;

int n, m;
vector < int > e[N];
int a[N];
int tin[N];
int tout[N];
int tmr;
bool use[N];
bitset < G > tree[N * 4];
int upd[N * 4];
int p[N];


void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs(int v) {
    use[v] = 1;
    tin[v] = tmr++;
    for (auto u: e[v])
        if (!use[u])
            dfs(u);
    tout[v] = tmr;
}

void build(int v, int ll, int rr) {
    if (ll + 1 == rr) {
        tree[v][a[p[ll]] % m] = 1;
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
}

bitset < G > tmp;
bitset < G > ones;

void makeShift(int v, int shift) {
    shift %= m;
    tmp.reset();
    tmp |= tree[v] << shift;
    tmp |= tree[v] >> (m - shift); 
    tmp &= ones;
    tree[v] = tmp;
}

void push(int v) {
    if (upd[v] != 0) {
        upd[v * 2 + 1] += upd[v];
        upd[v * 2 + 2] += upd[v];
        makeShift(v * 2 + 1, upd[v]);
        makeShift(v * 2 + 2, upd[v]);
        upd[v] = 0;
    }
}

void add(int v, int ll, int rr, int l, int r, int shift) {
    if (l >= rr || ll >= r) return;
    if (l <= ll && rr <= r) {
        makeShift(v, shift);
        upd[v] += shift;
        return;
    }
    push(v);
    add(v * 2 + 1, ll, (ll + rr) / 2, l, r, shift);
    add(v * 2 + 2, (ll + rr) / 2, rr, l, r, shift);
    tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
}

bitset < G > get(int v, int ll, int rr, int l, int r) {
    if (ll >= r || l >= rr) return bitset < G >();
    if (l <= ll && rr <= r) return tree[v];
    push(v);
    return get(v * 2 + 1, ll, (ll + rr) / 2, l, r) |
           get(v * 2 + 2, (ll + rr) / 2, rr, l, r);
}

void solve() {
    dfs(0);
    for (int i = 0; i < n; i++)
        p[tin[i]] = i;

    build(0, 0, n);

    vector < int > p;
    for (int i = 2; i < m; i++) {
        bool flag = 1;
        for (int j = 2; j * j <= i; j++)
            flag &= i % j != 0;
        if (flag)
            p.pb(i);
    }

    ones.reset();
    for (int i = 0; i < m; i++)
        ones[i] = 1;

    //for (int i = 0; i < n; i++)
        //cerr << i << ": " << tin[i] << " " << tout[i] << endl;
    int q;
    scanf("%d", &q);
    for (int t = 0; t < q; t++) {
        int type, v;
        scanf("%d%d", &type, &v); v--;
        if (type == 1) {
            int x;
            scanf("%d", &x);
            add(0, 0, n, tin[v], tout[v], x % m);
        }
        else {
            int cnt = 0;
            auto res = get(0, 0, n, tin[v], tout[v]);
            for (auto x: p)
                cnt += res[x];
            printf("%d\n", cnt);
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