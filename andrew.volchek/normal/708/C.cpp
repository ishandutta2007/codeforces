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

const int maxn = 4e5 + 5;

vector<int> g[maxn];
int dp[maxn];
int n;
int ans[maxn];

int sz[maxn];

void dfs(int v, int p) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
}

void dfs2(int v, int p) {
    dp[v] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }

        dfs2(to, v);
        chmax(dp[v], dp[to]);
        if (sz[to] <= n / 2) {
            chmax(dp[v], sz[to]);
        }
    }

    if (sz[v] <= n / 2) {
        chmax(dp[v], sz[v]);
    }
}

void dfs3(int v, int p, int up) {
    int upper = n - sz[v];
    bool bad = false;
    int cnt = 0;

    if (upper <= n / 2) {

    } else if (upper - up <= n / 2) {
        cnt++;
    } else {
        bad = true;
    }

    for (int to : g[v]) {
        if (to != p) {
            if (sz[to] <= n / 2) {

            } else if (sz[to] - dp[to] <= n / 2) {
                cnt++;
            } else {
                bad = true;
            }
        }
    }

    ans[v] = !bad && cnt <= 1;

    int down = up;
    if (n - sz[v] <= n / 2) {
        down = max(down, n - sz[v]);
    }

    int m1 = 0, m2 = 0;

    for (int to : g[v]) {
        if (to == p) {
            continue;
        }

        if (m1 < dp[to]) {
            m2 = m1;
            m1 = dp[to];
        } else if (m2 < dp[to]) {
            m2 = dp[to];
        }
    }

    for (int to : g[v]) {
        if (to == p) {
            continue;
        }

        int cd = down;
        if (n - sz[to] <= n / 2) {
            cd = n - sz[to];
        }

        if (dp[to] == m1) {
            dfs3(to, v, max(m2, cd));
        } else {
            dfs3(to, v, max(m1, cd));
        }
    }
}

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

    scanf("%d", &n);
   //n = 400000;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

       // u = i + 2;
       // v = rand() % (i + 1) + 1;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 1);
    dfs2(1, 1);
    dfs3(1, 1, 0);


    bool any = false;

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", ans[i]);
        any |= ans[i];
    }
    printf("\n");

    //assert(any);


    return 0;
}