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

const int maxn = 200005;
vector<int> g[maxn];

pair<int,int> dfs(int v, int p = 0) {
    if (g[v].empty()) {
        return mp(1, 1);
    }

    int sz = 0;

    if (p == 0) {
        int m = 1e9;
        for (int to : g[v]) {
            auto r = dfs(to, 1 - p);
            sz += r.snd;
            m = min(m, r.snd - r.fst);
        }
        return mp(sz - m, sz);
    } else {
        int m = 0;
        for (int to : g[v]) {
            auto r = dfs(to, 1 - p);
            sz += r.snd;
            m += r.snd - r.fst;
        }
        return mp(sz - m - g[v].size() + 1, sz);
    }
}

pair<int,int> dfs2(int v, int p = 0) {
    if (g[v].empty()) {
        return mp(1, 1);
    }

    int sz = 0;

    if (p == 0) {
        int m = 0;
        for (int to : g[v]) {
            auto r = dfs2(to, 1 - p);
            sz += r.snd;
            m += r.fst;
        }
        return mp(m, sz);
    } else {
        int m = 1e9;
        for (int to : g[v]) {
            auto r = dfs2(to, 1 - p);
            sz += r.snd;
            m = min(m, r.fst);
        }
        return mp(m, sz);
    }
}

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
    }

    cout << dfs(1).fst << " " << dfs2(1).fst << endl;

    return 0;
}