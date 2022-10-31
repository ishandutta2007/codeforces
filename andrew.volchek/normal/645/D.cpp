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

const int maxn = 1e5 + 5;
int dp[maxn];
int used[maxn];
vector<int> g[maxn];

void dfs(int v) {
    used[v] = 1;
    dp[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
        chmax(dp[v], dp[to] + 1);
    }
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    vector<pair<int,int>> a;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a.pb(mp(u, v));
    }

    int lo = 0, hi = m + 1;
    while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 0; i < mid; i++) {
            g[a[i].fst].pb(a[i].snd);
        }
        fill(used, used + maxn, 0);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(i);
            }
            chmax(res, dp[i]);
        }

        if (res == n) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (hi == m + 1) {
        cout << -1 << endl;
    } else {
        cout << hi << endl;
    }

    return 0;
}