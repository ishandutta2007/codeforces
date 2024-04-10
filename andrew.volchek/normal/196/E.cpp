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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair <U, V> &x) {
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

//-----------------------------------------------------------------------------


const int maxn = 1e5 + 5;
const ll inf = 1e18;

vector<pair<int, ll>> g[maxn];
ll d[maxn];
int pr[maxn];

int f[maxn];

int find(int v) {
    if (v == f[v]) {
        return v;
    }

    return f[v] = find(f[v]);
}

int main() {
    srand(time(NULL));

    retry:

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

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }


    for (int i = 1; i <= n; i++) {
        random_shuffle(g[i].begin(), g[i].end());
    }

    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    fill(d, d + maxn, inf);

    int k;
    scanf("%d", &k);
    queue<int> q;
    vector<int> inq(n + 1, 0);

    while (k--) {
        int x;
        scanf("%d", &x);
        d[x] = 0;
        q.push(x);
        inq[x] = 1;
        pr[x] = x;
    }

    while (!q.empty()) {
        int v = q.front();
        ll c = d[v];
        q.pop();
        inq[v] = 0;
        for (auto to : g[v]) {
            ll nd = c + to.snd;
            if (d[to.fst] > nd) {
                d[to.fst] = nd;
                pr[to.fst] = v;
                if (!inq[to.fst]) {
                    inq[to.fst] = 1;
                    q.push(to.fst);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        f[find(i)] = f[find(pr[i])];
    }

    vector<pair<ll, pair<int,int>>> e;
    for (int i = 1; i <= n; i++) {
        for (auto to : g[i]) {
            e.pb(mp(d[i] + d[to.fst] + to.snd, mp(i, to.fst)));
        }
    }

    sort(e.begin(), e.end());

    ll ans = d[1];

    for (auto x : e) {
        int u = find(x.snd.fst);
        int v = find(x.snd.snd);

        if (u != v) {
            ans += x.fst;
            if (rand() & 1) {
                swap(u, v);
            }
            f[u] = v;
        }
    }

    cout << ans << endl;

    return 0;
}