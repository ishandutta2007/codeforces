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
#include <future>

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

const ld pi = acos(-1.0);

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


//--------------------------------------------------------------------------


const int maxn = 88;
ll dp[maxn][maxn][maxn][2];
vector<pair<int, int>> g[maxn];

ll rec(int l, int r, int need, int side) {
    ll& res = dp[need][l][r][side];
    if (res >= 0) {
        return res;
    }

    if (!need) {
        return 0;
    }

    res = 1e18;
    if (!side) {
        for (auto to : g[l]) {
            if (l < to.fst && to.fst < r) {
                chmin(res, rec(l, to.fst, need - 1, 1) + to.snd);
                chmin(res, rec(to.fst, r, need - 1, 0) + to.snd);
            }
        }
    } else {
        for (auto to : g[r]) {
            if (l < to.fst && to.fst < r) {
                chmin(res, rec(to.fst, r, need - 1, 0) + to.snd);
                chmin(res, rec(l, to.fst, need - 1, 1) + to.snd);
            }
        }
    }

    return res;
}

int main() {

    srand(0);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("brackets.in", "r", stdin);
    //freopen("brackets.out", "w", stdout);
#endif


    int n, k;
    cin >> n >> k;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(mp(v, w));
        //g[v].pb(mp(u, w));
    }

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            for (int h = 0; h < maxn; h++) {
                for (int u = 0; u < 2; u++) {
                    dp[i][j][h][u] = -1;
                }
            }
        }
    }

    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        chmin(ans, rec(0, i, k - 1, 1));
        chmin(ans, rec(i, n + 1, k - 1, 0));
    }

    if (ans > 1e17) {
        cout << -1 << endl;
    } else {
        cout << ans;
    }


    return 0;
}