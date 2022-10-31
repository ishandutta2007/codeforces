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
#include <numeric>

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
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
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

const int maxn = 30005;
const int maxe = maxn * 5;
const int inf = 1e8;

int f[maxe], c[maxe];
vector<pair<int,int>> g[maxn];
int ecnt;
int s, t;
int lvl[maxn];
int ptr[maxn];

void add(int u, int v, int cc) {

    g[u].pb(mp(v, ecnt));
    g[v].pb(mp(u, ecnt + 1));
    c[ecnt] = cc;
    ecnt += 2;
}

void bfs() {
    fill(lvl, lvl + maxn, -1);
    lvl[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto tt : g[v]) {
            int ee = tt.snd, to = tt.fst;
            if (f[ee] == c[ee] || lvl[to] != -1) {
                continue;
            }
            lvl[to] = lvl[v] + 1;
            q.push(to);
        }
    }
}

int dfs(int v, int fl) {
    if (v == t || !fl) {
        return fl;
    }
    for (int &i = ptr[v]; i < g[v].size(); i++) {
        int to = g[v][i].fst, ee = g[v][i].snd;
        if (f[ee] == c[ee] || lvl[to] != lvl[v] + 1) {
            continue;
        }
        if (int res = dfs(to, min(fl, c[ee] - f[ee]))) {
            f[ee] += res;
            f[ee ^ 1] -= res;
            return res;
        }
    }

    return 0;
}

int flow() {
    int res = 0;
    while (true) {
        bfs();
        if (lvl[t] == -1) {
            break;
        }
        fill(ptr, ptr + maxn, 0);
        while (int r = dfs(s, inf)) {
            res += r;
        }
    }
    return res;
}


vector<pair<int,int>> g2[maxn];
int id[maxn];
int pr2[maxn];
int prE2[maxn];
int used[maxn];
int color[maxn];
int cnt = 0;

void dfs2(int v, int p) {
    used[v] = 1;
    for (auto tt : g2[v]) {
        int to = tt.fst, ee = tt.snd;
        if (ee == p) {
            continue;
        }
        if (id[ee] != -1) {
            continue;
        }

        if (used[to]) {
            int u = v;
            id[ee] = cnt;

            while (u != to) {
                id[prE2[u]] = cnt;
                u = pr2[u];
            }
            cnt++;
        } else {
            pr2[to] = v;
            prE2[to] = ee;
            dfs2(to, ee);
        }
    }
}


int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    //n = 10000, m = 9999 + 4999;


    vector<int> ccnt(m);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        c--;
        g2[u].pb(mp(v, i));
        g2[v].pb(mp(u, i));
        color[i] = c;
        ccnt[c]++;
    }

    /*for (int i = 0; i < 9999; i++) {
        int u, v, c;
        //scanf("%d %d %d", &u, &v, &c);
        u = i + 1, v = i + 2;
        c = i + 1;
        c--;
        g2[u].pb(mp(v, i));
        g2[v].pb(mp(u, i));
        color[i] = c;
        ccnt[c]++;
    }

    for (int i = 0; i < 4999; i++) {
        int u, v, c;
        //scanf("%d %d %d", &u, &v, &c);
        u = 2 * i + 1, v = 2 * i + 3;

        c = 9999 + 1 + i;
        c--;
        g2[u].pb(mp(v, i));
        g2[v].pb(mp(u, i));
        color[i] = c;
        ccnt[c]++;
    }*/



    fill(id, id + maxn, -1);
    dfs2(1, -1);



    for (int i = 0; i < m; i++) {
        if (id[i] != -1) {
            add(id[i], cnt + 1 + color[i], 1);
        }
    }

    s = maxn - 1, t = maxn - 2;
    for (int i = 0; i < cnt; i++) {
        add(s, i, 1);
    }


    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (ccnt[i]) {
            ans++;
            add(cnt + 1 + i, t, ccnt[i] - 1);
        }
    }

    cout << ans - (cnt - flow()) << endl;

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}