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

const int maxn = (2e5 + 5) * 4 * 4;
const int maxv = 2e5 + 12345;

int f[maxn], c[maxn];
int lvl[maxv], ptr[maxv];
int ecnt;
vector<pair<int,int>> g[maxv];

int s, t;

int add(int u, int v, int cc) {
    g[u].pb(mp(v, ecnt));
    g[v].pb(mp(u, ecnt + 1));
    c[ecnt] = cc;
    ecnt += 2;
    return ecnt - 2;
}

void bfs() {
    fill(lvl, lvl + maxv, -1);
    lvl[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : g[v]) {
            int ee = e.snd;
            int to = e.fst;

            if (lvl[to] != -1 || f[ee] == c[ee]) {
                continue;
            }

            lvl[to] = lvl[v] + 1;
            q.push(to);
        }
    }
}

int dfs(int v, int flow) {
    if (v == t || !flow) {
        return flow;
    }

    for (int &i = ptr[v]; i < g[v].size(); i++) {
        int to = g[v][i].fst;
        int ee = g[v][i].snd;
        if (lvl[to] != lvl[v] + 1 || f[ee] == c[ee]) {
            continue;
        }
        if (int res = dfs(to, min(flow, c[ee] - f[ee]))) {
            f[ee] += res;
            f[ee ^ 1] -= res;
            return res;
        }
    }

    return 0;
}

void flow() {
    while (true) {
        bfs();
        if (lvl[t] == -1) {
            break;
        }
        fill(ptr, ptr + maxv, 0);
        while (dfs(s, 1e9)) {
        }
    }
}

int oldS, oldT;
vector<pair<int,int>> ensure;

int addLR(int u, int v, int l, int r) {
    ensure.pb(mp(add(s, v, l), l));
    ensure.pb(mp(add(u, t, l), l));
    return add(u, v, r - l);
}


int main() {
    //srand(time(NULL));

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

    int costR, costB;
    scanf("%d %d", &costR, &costB);

    map<int, int> hor, vert;
    map<int, int> horDeg, vertDeg;
    vector<pair<int,int>> a(n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].fst, &a[i].snd);
        if (!hor.count(a[i].fst)) {
            int sz = hor.size();
            hor[a[i].fst] = sz;
        }
        if (!vert.count(a[i].snd)) {
            int sz = vert.size();
            vert[a[i].snd] = sz;
        }
        a[i].fst = hor[a[i].fst];
        a[i].snd = vert[a[i].snd];
        horDeg[a[i].fst]++;
        vertDeg[a[i].snd]++;
    }


    map<int, int> horRestr, vertRestr;
    for (int i = 0; i < m; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        if (type == 1) {
            if (hor.count(x)) {
                x = hor[x];
                if (horRestr.count(x)) {
                    chmin(horRestr[x], y);
                } else {
                    horRestr[x] = y;
                }
            }
        } else {
            if (vert.count(x)) {
                x = vert[x];
                if (vertRestr.count(x)) {
                    chmin(vertRestr[x], y);
                } else {
                    vertRestr[x] = y;
                }
            }
        }
    }

    s = maxv - 1, t = maxv - 2;
    oldS = maxv - 3, oldT = maxv - 4;

    int k = hor.size();
    for (int i = 0; i < k; i++) {
        if (!horRestr.count(i)) {
            horRestr[i] = 1e9;
        }

        int l = 1e9, r = -1e9;
        for (int j = 0; j <= horDeg[i]; j++) {
            if (abs(j - (horDeg[i] - j)) <= horRestr[i]) {
                chmin(l, j);
                chmax(r, j);
            }
        }

        if (l > r) {
            cout << -1 << endl;
            return 0;
        }

        addLR(oldS, i, l, r);
    }

    for (int i = 0; i < vert.size(); i++) {
        if (!vertRestr.count(i)) {
            vertRestr[i] = 1e9;
        }

        int l = 1e9, r = -1e9;
        for (int j = 0; j <= vertDeg[i]; j++) {
            if (abs(j - (vertDeg[i] - j)) <= vertRestr[i]) {
                chmin(l, j);
                chmax(r, j);
            }
        }

        if (l > r) {
            cout << -1 << endl;
            return 0;
        }

        addLR(k + i, oldT, l, r);
    }

    vector<int> fi;
    for (int i = 0; i < n; i++) {
        fi.pb(addLR(a[i].fst, k + a[i].snd, 0, 1));
    }

    int id = add(oldT, oldS, 1e9);

    flow();

    for (auto p : ensure) {
        if (f[p.fst] != p.snd) {
            cout << -1 << endl;
            return 0;
        }
    }

    s = oldS, t = oldT;
    c[id] = 0;

    flow();

    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cost += f[fi[i]] ? min(costR, costB) : max(costR, costB);
    }

    cout << cost << endl;

    for (int i = 0; i < n; i++) {
        if (costR < costB) {
            printf("%c", f[fi[i]] ? 'r' : 'b');
        } else {
            printf("%c", f[fi[i]] ? 'b' : 'r');
        }
    }
    printf("\n");

    return 0;
}