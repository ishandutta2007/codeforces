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

const int maxn = 5005;
vector<int> g[maxn];
vector<pair<int,int>> a[maxn];

int dist[maxn];


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

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    int w;
    scanf("%d", &w);
    for (int i = 0; i < w; i++) {
        int c, k, p;
        scanf("%d %d %d", &c, &k, &p);
        a[c].pb(mp(p, k));
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int v, cnt, cost;
        cin >> v >> cnt >> cost;

        fill(dist, dist + maxn, 1e9);
        dist[v] = 0;
        queue<int> q;
        q.push(v);
        vector<pair<pair<int,int>, int>> was;
        while (!q.empty()) {
            int v = q.front();
            //cout << i << " " << v << endl;
            q.pop();
            for (auto x : a[v]) {
                was.pb(mp(x, dist[v]));
            }
            for (int to : g[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        sort(was.begin(), was.end());
        //cout << cnt << " " << was << endl;
        int lo = -1, hi = maxn;
        while (hi - lo > 1) {
            int mid = (lo + hi) >> 1;

            int need = cnt;
            int cc = cost;
            for (auto x : was) {
                if (x.snd <= mid) {
                    int f = min(need, x.fst.snd);
                    if (f * 1LL * x.fst.fst <= cc) {
                        cc -= f * 1LL * x.fst.fst;
                        need -= f;
                    }
                }
            }

            if (!need) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        if (hi == maxn) {
            cout << -1 << endl;
        } else {
            cout << hi << endl;
        }
    }


    return 0;
}