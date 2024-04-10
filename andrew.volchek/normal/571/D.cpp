#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 5e5 + 5;

vector<int> g[maxn];
int bad[maxn];
int tl[maxn], tr[maxn];
int timer = 1;

void dfs(int v) {
    tl[v] = tr[v] = timer++;
    for (int to : g[v]) {
        dfs(to);
    }
}

int ft[maxn * 4];

void modify(int v, int l, int r, int i, int j, int val) {
    if (i <= l && r <= j) {
        ft[v] = max(ft[v], val);
        return;
    }

    int c = (l + r) >> 1;
    if (i <= c) {
        modify(2 * v, l, c, i, j, val);
    }

    if (c < j) {
        modify(2 * v + 1, c + 1, r, i, j, val);
    }
}

int get(int v, int l, int r, int i) {
    if (l == r) {
        return ft[v];
    }

    int res = ft[v];
    int c = (l + r) >> 1;

    if (i <= c) {
        res = max(res, get(2 * v, l, c, i));
    } else {
        res = max(res, get(2 * v + 1, c + 1, r, i));
    }

    return res;
}


int dsuU[maxn], szU[maxn];
ll valU[maxn];

int compressU(int v) {
    if (dsuU[v] == v) {
        return v;
    }

    if (dsuU[v] == dsuU[dsuU[v]]) {
        return dsuU[v];
    }

    int t = compressU(dsuU[v]);
    valU[v] += valU[dsuU[v]];
    dsuU[v] = t;

    return t;
}

ll getU(int v) {
    compressU(v);

    if (dsuU[v] == v) {
        return valU[v];
    }

    return valU[v] + valU[dsuU[v]];
}


void uniteU(int u, int v) {
    valU[v] -= valU[u];
    dsuU[v] = u;
    szU[u] += szU[v];
}

struct ev {
    int type;
    int u, v;
};

int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= n; i++) {
        dsuU[i] = i;
        szU[i] = 1;
    }

    fill(ft, ft + maxn * 4, -1);

    vector<ev> e;

    for (int i = 0; i < m; i++) {
        char c;
        scanf("%c", &c);

        if (c == 'U') {
            int u, v;
            scanf("%d %d\n", &u, &v);
            e.pb({1, u, v});
        } else if (c == 'M') {
            int u, v;
            scanf("%d %d\n", &u, &v);
            e.pb({2, u, v});
            g[u].pb(v);
            bad[v] = 1;
        } else if (c == 'A') {
            int u;
            scanf("%d\n", &u);
            e.pb({3, u, 0});
        } else if (c == 'Z') {
            int u;
            scanf("%d\n", &u);
            e.pb({4, u, 0});
        } else if (c == 'Q') {
            int u;
            scanf("%d\n", &u);
            e.pb({5, u, 0});
        } else {
            assert(0);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            dfs(i);
        }
    }

    vector<ll> ans(m, 0);
    vector<vector<pair<int,int>>> sub(m);

    for (int i = 0; i < m; i++) {
        auto x = e[i];
        if (x.type == 2) {
            tr[x.u] = tr[x.v];
        } else if (x.type == 4) {
            modify(1, 1, n, tl[x.u], tr[x.u], i);
        } else if (x.type == 5) {
            int f = get(1, 1, n, tl[x.u]);
            if (f != -1) {
                sub[f].pb(mp(x.u, i));
            }
        }
    }

    for (int i = 0; i < m; i++) {
        auto x = e[i];

        for (auto p : sub[i]) {
            ans[p.snd] -= getU(p.fst);
        }

        if (x.type == 1) {
            uniteU(x.u, x.v);
        } else if (x.type == 3) {
            valU[x.u] += szU[x.u];
        } else if (x.type == 5) {
            ans[i] += getU(x.u);
            printf("%lld\n", ans[i]);
        }
    }

    return 0;
}