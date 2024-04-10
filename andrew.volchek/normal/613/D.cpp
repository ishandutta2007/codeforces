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
#include <limits>
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;

vector<int> g[maxn];
int tin[maxn], tout[maxn], depth[maxn], pr[maxn][20];
int timer = 1;

void dfs(int v, int p) {
    tin[v] = timer++;

    pr[v][0] = p;
    for (int i = 1; i < 20; i++) {
        pr[v][i] = pr[pr[v][i - 1]][i - 1];
    }

    for (int to : g[v]) {
        if (to != p) {
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    }

    tout[v] = timer;
}

bool is_child(int v, int pr) {
    return tin[pr] <= tin[v] && tin[v] < tout[pr];
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int diff = depth[u] - depth[v];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
            u = pr[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    int res;

    for (int i = 19; i >= 0; i--) {
        if (pr[u][i] == pr[v][i]) {
            res = pr[u][i];
        } else {
            u = pr[u][i];
            v = pr[v][i];
        }
    }

    return res;
}

vector<int> gn[maxn];
int gnSz;
int used[maxn];
int corr[maxn], invCorr[maxn];
int currUsed = 1;
int imp[maxn];

int get(int v) {
    if (used[v] != currUsed) {
        corr[v] = gnSz++;
        invCorr[corr[v]] = v;
        used[v] = currUsed;
    }
    return corr[v];
}

void add(int u, int v) {
    gn[get(u)].pb(get(v));
    gn[get(v)].pb(get(u));
}


void clear() {
    for (int i = 0; i < gnSz; i++) {
        gn[i].clear();
    }

    gnSz = 0;
    currUsed++;
}

void build(vector<int> a) {
    clear();

    sort(a.begin(), a.end(), [&](int u, int v) {
        return tin[u] < tin[v];
    });

    int p = 0;
    get(0);

    function<void(int)> rec;
    rec = [&](int root) {
        if (p == a.size() || !is_child(a[p], root)) {
            return;
        }

        int v = a[p];
        p++;
        rec(v);

        while (true) {
            if (p == a.size() || !is_child(a[p], root)) {
                add(root, v);
                break;
            }

            int u = a[p];

            int z = lca(u, v);

            if (z == root) {
                add(root, v);
                rec(root);
                return;
            } else {
                add(z, v);
                rec(z);
                v = z;
            }
        }
    };

    rec(0);
}

int ans;
int solve(int v, int p) {
    int cnt = 0;
    for (int to : gn[v]) {
        if (to == p) {
            continue;
        }

        cnt += solve(to, v);
    }

    int real = invCorr[v];
    if (imp[real]) {
        ans += cnt;
        return 1;
    } else {
        if (cnt > 1) {
            ans++;
            return 0;
        } else {
            return cnt;
        }
    }
}


int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    g[0].pb(1);
    g[1].pb(0);

    dfs(0, 0);

    int q;
    scanf("%d", &q);

    while (q--) {
        int k;
        scanf("%d", &k);

        vector<int> a;
        while (k--) {
            int x;
            scanf("%d", &x);
            a.pb(x);
        }

        if (a.size() == 1) {
            printf("0\n");
            continue;
        }

        for (int x : a) {
            imp[x] = 1;
        }

        bool bad = false;
        for (int x : a) {
            if (imp[pr[x][0]]) {
                bad = true;
            }
        }

        if (bad) {
            printf("-1\n");
        } else {
            build(a);
            ans = 0;
            solve(0, -1);
            printf("%d\n", ans);
        }

        for (int x : a) {
            imp[x] = 0;
        }
    }

    return 0;
}