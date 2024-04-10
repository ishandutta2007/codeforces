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

const int maxn = 1e5 + 5;
map<pair<int,int>, int> dp;
vector<int> g[maxn];
vector<int> order;
int color[maxn];

void dfs(int v, int p) {
    order.pb(v);
    int res = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            if (!dp[mp(to, v)]) {
                res = 0;
            }
            if (color[to] != color[v]) {
                res = 0;
            }
        }
    }
    dp[mp(v, p)] = res;
}

int main() {
    srand(time(0));


#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", color + i);
    }
    dfs(1, -1);
    for (int v : order) {
        int cnt = 0;
        multiset<int> c;
        for (int to : g[v]) {
            cnt += !dp[mp(to, v)];
            c.insert(color[to]);
        }

        dp[mp(v, -1)] = !cnt && c.count(color[v]) == c.size();

        for (int to : g[v]) {
            cnt -= !dp[mp(to, v)];
            c.erase(c.find(color[to]));
            dp[mp(v, to)] = !cnt && c.count(color[v]) == c.size();
            c.insert(color[to]);
            cnt += !dp[mp(to, v)];
        }
    }

    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int to : g[i]) {
            good &= dp[mp(to, i)];
        }
        if (good) {
            cout << "YES" << endl;
            cout << i << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}