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

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}


struct node {
    node *l, *r;
    int sum;
    int val;
    int key;
    int pr;
    node() {
        l = r = nullptr;
        pr = rand();
    }
    void update() {
        sum = val;
        if (l) {
            sum += l->sum;
        }
        if (r) {
            sum += r->sum;
        }
    }
};

typedef node* pnode;

pnode merge(pnode l, pnode r) {
    if (!l || !r) {
        return l ? l : r;
    }

    if (l->pr > r->pr) {
        l->r = merge(l->r, r);
        l->update();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->update();
        return r;
    }
}

void split(pnode v, pnode &l, pnode &r, int key) {
    if (!v) {
        l = r = nullptr;
        return;
    }

    if (v->key <= key) {
        l = v;
        split(v->r, l->r, r, key);
    } else {
        r = v;
        split(v->l, l, r->l, key);
    }

    if (l) {
        l->update();
    }

    if (r) {
        r->update();
    }
}

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int timer = 1;
int tin[maxn], tout[maxn];
int sz[maxn];
int tinInv[maxn];

void dfs(int v, int p = -1) {
    tin[v] = timer++;
    tinInv[tin[v]] = v;
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
    tout[v] = timer - 1;
}

vector<int> q[maxn];
pnode root = nullptr;
int ans[maxn];

void dfs2(int v, int p = -1) {
    vector<pair<int, pnode>> was;
    for (int x : q[v]) {
        pnode l, r;
        split(root, l, r, tin[x]);
        bool bad = false;
        if (l) {
            pnode v = l;
            while (true) {
                if (v->r == nullptr) {
                    break;
                }
                v = v->r;
            }
            int f = tinInv[v->key];
            if (tin[f] <= tin[x] && tin[x] <= tout[f]) {
                bad = true;
            }
        }
        root = merge(l, r);
        if (bad) {
            continue;
        }

        pnode c;
        split(root, l, r, tin[x] - 1);
        split(r, c, r, tout[x]);

        pnode nv = new node();
        nv->key = tin[x];
        nv->val = nv->sum = sz[x];
        root = merge(l, merge(nv, r));

        was.pb(mp(x, c));
    }

    ans[v] = (root ? root->sum - 1 : 0);

    for (int to : g[v]) {
        if (to != p) {
            dfs2(to, v);
        }
    }

    reverse(was.begin(), was.end());

    for (auto x : was) {
        pnode l, c, r;
        split(root, l, r, tin[x.fst] - 1);
        split(r, c, r, tout[x.fst]);
        root = merge(l, merge(x.snd, r));
    }
}


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
    scanf("%d %d", &n, &m);
    //n = 1e5, m = 1e5;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        //u = i + 2;
        //v = rand() % (i + 1) + 1;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        //u = rand() % n + 1;
        //v = rand() % n + 1;
        q[u].pb(v);
        q[u].pb(u);
        q[v].pb(u);
        q[v].pb(v);
    }

    for (int i = 1; i <= n; i++) {
        sort(q[i].begin(), q[i].end());
        q[i].resize(unique(q[i].begin(), q[i].end()) - q[i].begin());
    }

    dfs(1);
    dfs2(1);

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }


    return 0;
}