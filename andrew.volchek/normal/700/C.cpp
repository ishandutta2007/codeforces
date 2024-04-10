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
#include <tuple>
#include <complex>

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

const int maxn = 3e4 + 5;

int dsu[maxn];
int find(int v) {
    if (v == dsu[v]) {
        return v;
    }
    return dsu[v] = find(dsu[v]);
}


int u[maxn], v[maxn], w[maxn];
vector<int> a[maxn];
int b[maxn];

int s, t;

struct graph {
    vector<pair<int,pair<ll,int>>> g[maxn];
    void clear() {
        for (int i = 0; i < maxn; i++) {
            g[i].clear();
            can[i] = 0;
            used[i] = false;
        }
        timer = 0;
        ans = mp(1e18, -1);
        can[t] = 1;
    }
    bool used[maxn];
    int timer, tin[maxn], fup[maxn];
    int can[maxn];
    pair<ll, int> ans;

    void dfs (int v, int p = -1) {

        used[v] = true;
        tin[v] = fup[v] = timer++;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i].fst;
            if (g[v][i].snd.snd == p)  continue;
            if (used[to]) {
                fup[v] = min(fup[v], tin[to]);
                can[v] |= can[to];
            }
            else {
                dfs (to, g[v][i].snd.snd );
                can[v] |= can[to];
                fup[v] = min (fup[v], fup[to]);
                if (fup[to] > tin[v] && can[to])
                    ans = min(ans, mp((ll)g[v][i].snd.fst, g[v][i].snd.snd));
            }
        }

        if (v == s && !can[v]) {
            ans.fst = 0;
            ans.snd = -1;
           // cout << 1 << endl;
        }
    }
    void add(int u, int v, ll w, int id = 0) {
        g[u].pb(mp(v, mp(w, id)));
        g[v].pb(mp(u, mp(w, id)));
    }
};
graph g;


int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif


    int n, m;
    scanf("%d %d", &n, &m);
    cin >> s >> t;
    g.clear();
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", u + i, v + i, w + i);
        a[i].reserve(n);
        g.add(u[i], v[i], w[i], i);
    }



    ll ans = 1e18;
    g.dfs(s, -1);
    chmin(ans, g.ans.fst);
    vector<int> va;
    ans = g.ans.fst;

    if (g.ans.fst < 1e13) {
        if (g.ans.snd == -1) {
            cout << 0 << endl;
            cout << 0 << endl;
            return 0;
        } else {
            va = {g.ans.snd};
        }
    }

    iota(dsu, dsu + maxn, 0);
    for (int i = m - 1; i >= 0; i--) {

        int x = find(u[i]);
        int y = find(v[i]);

        if (x != y) {
            b[i] = 1;
            dsu[x] = y;
        }
    }



    iota(dsu, dsu + maxn, 0);

    for (int i = 0; i < m; i++) {
        int x = find(u[i]);
        int y = find(v[i]);

        if (x != y) {
            b[i] = 1;
            dsu[x] = y;
        }
    }

    iota(dsu, dsu + maxn, 0);

    for (int i = 0; i < m; i++) {
        if (b[i]) {
            continue;
        }
        int x = find(u[i]);
        int y = find(v[i]);

        if (x != y) {
            b[i] = 1;
            dsu[x] = y;
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        if (i + 1 < m) {
            for (int j = 0; j < a[i + 1].size(); j++) {
                a[i].pb(a[i + 1][j]);
            }
        }


        if (b[i]) {
            a[i].pb(i);
        }
    }

    for (int i = 0; i + 1 < m; i++) {
        int x = find(u[i]);
        int y = find(v[i]);

        if (x != y) {
            g.clear();
            for (int j = 1; j <= n; j++) {
                if (j != find(j)) {
                    g.add(j, find(j), 1e18, maxn + j);
                }
            }


            for (int x : a[i + 1]) {
                g.add(u[x], v[x], w[x], x);
            }

            g.dfs(s, -1);
            if (g.ans.snd != -1) {
                g.ans.fst += w[i];
                if (ans > g.ans.fst) {
                    ans = g.ans.fst;
                    va = {i, g.ans.snd};
                }
            }

            dsu[x] = y;

        }
    }

    if (ans > 1e13) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
        cout << va.size() << endl;
        for (int x : va) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }



    return 0;
}