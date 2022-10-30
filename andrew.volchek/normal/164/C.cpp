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
#define ld double
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
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 3005, maxe = 20005;
const ll inf = 1e16;
ll f[maxe], c[maxe], p[maxe];
int pr[maxn], prE[maxn];
ll dist[maxn];
ll ph[maxn];
vector<pair<int,int>> g[maxn];
int ecnt = 0;
int s, t;

int add(int u, int v, int cc, int pp) {
    g[u].pb(mp(v, ecnt));
    g[v].pb(mp(u, ecnt + 1));
    c[ecnt] = cc;
    p[ecnt] = pp;
    p[ecnt + 1] = -pp;
    ecnt += 2;
    return ecnt - 2;
}

void djkstra() {
    fill(dist, dist + maxn, inf);
    dist[s] = 0;
    priority_queue<pair<ll, int>> q;
    q.push(mp(0, s));
    while (!q.empty()) {
        int v = q.top().snd;
        ll cd = -q.top().fst;

        q.pop();
        if (dist[v] != cd) {
            continue;
        }
        for (auto to : g[v]) {
            if (c[to.snd] == f[to.snd]) {
                continue;
            }
            ll nd = cd + ph[v] - ph[to.fst] + p[to.snd];
            //cerr << ph[v] - ph[to.fst] + p[to.snd] << endl;
            if (nd < dist[to.fst]) {
                dist[to.fst] = nd;
                pr[to.fst] = v;
                prE[to.fst] = to.snd;
                q.push(mp(-nd, to.fst));
            }
        }
    }
    for (int i = 0; i < maxn; i++) {
        ph[i] += dist[i] == inf ? 0 : dist[i];
    }
}

void flow() {
    while (true) {
        djkstra();

        if (dist[t] == inf) {
            break;
        }
        ll r = inf;
        int v = t;
        while (v != s) {
            r = min(r, c[prE[v]] - f[prE[v]]);
            v = pr[v];
        }
        v = t;
        while (v != s) {
            f[prE[v]] += r;
            f[prE[v] ^ 1] -= r;
            v = pr[v];
        }
    }
}

void bf() {
    for (int i = 0; i < maxn * 2; i++) {
        for (int j = 0; j < maxn; j++) {
            for (auto to : g[j]) {
                if ((to.snd % 2 == 0) && dist[to.fst] > dist[j] + p[to.snd]) {
                    dist[to.fst] = dist[j] + p[to.snd];
                }
            }
        }
    }


    for (int i = 0; i < maxn; i++) {
        ph[i] = dist[i];
    }

    for (int i = 0; i < maxn; i++) {
        for (auto to : g[i]) {
            //assert((to.snd & 1) || ph[i] - ph[to.fst] + p[to.snd] >= 0);
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

    int n, k;
    scanf("%d %d", &n, &k);
    //n = 1000, k = 50;
    vector<ll> cc;
    cc.pb(-inf);
    cc.pb(inf);
    vector<pair<pair<int,int>, int>> a;
    for (int i = 0; i < n; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        //s = rand() % 1000, t = rand() % 1000 + 1, c = rand() % 1000;
        a.pb(mp(mp(s, s + t), c));
        cc.pb(s);
        cc.pb(s + t);
    }

    s = maxn - 1, t = maxn - 2;
    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());

    add(s, 0, k, 0);
    add(cc.size() - 1, t, k, 0);


    for (int i = 0; i + 1 < cc.size(); i++) {
        add(i, i + 1, 1e9, 0);
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int u = lower_bound(cc.begin(), cc.end(), a[i].fst.fst) - cc.begin();
        int v = lower_bound(cc.begin(), cc.end(), a[i].fst.snd) - cc.begin();
        ans.pb(add(u, v, 1, -a[i].snd));
    }

    bf();
    flow();

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", (int)f[ans[i]]);
    }


    return 0;
}