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

const int maxn = 2e5 + 5;
vector<int> g[maxn];
vector<int> order;
int used[maxn];
void dfs(int v) {
    order.pb(v);
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
            order.pb(v);
        }
    }
}

int main(int argc, char* argv[]) {

    srand(134);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //gen();
    //return 0;

#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    int blk = 2 * n / k;
    if ((2 * n) % k) {
        blk++;
    }
    dfs(1);

    vector<vector<int>> ans(k);
    int p = 0;
    for (int i = 0; i < k; i++) {
        int pp = p;
        for (int j = p; j < min((int)order.size(), p + blk); j++) {
            ans[i].pb(order[j]);
            pp++;
        }
        p = pp;


        if (ans[i].empty()) {
            ans[i].pb(1);
        }

        printf("%d", ans[i].size());
        for (int x : ans[i]) {
            printf(" %d", x);
        }
        printf("\n");
    }




    return 0;
}