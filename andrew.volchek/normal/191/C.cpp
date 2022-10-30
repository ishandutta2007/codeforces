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


//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;

int dp[maxn];
int ans[maxn];
vector<pair<int,int>> g[maxn];

int dfs(int v, int pr) {
    int res = dp[v];
    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;
        }
        int r = dfs(to.fst, v);
        res += r;
        ans[to.snd] = r;
    }
    return res;
}

int p[20][maxn];
int d[maxn];

void dfs2(int v, int pr) {
    p[0][v] = pr;
    for (int i = 1; i < 20; i++) {
        p[i][v] = p[i - 1][p[i - 1][v]];
    }
    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;;
        }
        d[to.fst] = d[v] + 1;
        dfs2(to.fst, v);
    }
}

int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }

    int diff = d[a] - d[b];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) {
            a = p[i][a];
        }
    }

    if (a == b) {
        return a;
    }

    int ans;
    for (int i = 19; i >= 0; i--) {
        if (p[i][a] == p[i][b]) {
            ans = p[i][a];
        } else {
            a = p[i][a];
            b = p[i][b];
        }
    }

    return ans;
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


    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(mp(v, i));
        g[v].pb(mp(u, i));
    }

    dfs2(1, 1);
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int w = lca(u, v);
        dp[u]++;
        dp[w]--;
        dp[v]++;
        dp[w]--;
    }

    dfs(1, 1);

    for (int i = 0; i < n - 1; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }


    return 0;
}