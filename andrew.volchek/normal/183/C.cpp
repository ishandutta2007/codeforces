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
vector<pair<int,int>> g[maxn];
int used[maxn];
int c[maxn];
int cu = 1;

int ub = -1;

void dfs(int v) {
    //cerr << v << endl;
    used[v] = cu;
    for (auto to : g[v]) {
        int nbal = c[v] + to.snd;
        if (used[to.fst] == cu) {
            if ((nbal - c[to.fst]) != 0) {
                ub = abs(nbal - c[to.fst]);
            }
        } else {
            c[to.fst] = nbal;
            dfs(to.fst);
        }
    }
}

bool bad = false;
int mod;

void dfs2(int v) {
    //cerr << v << endl;
    used[v] = cu;
    for (auto to : g[v]) {
        if (used[to.fst] == cu) {
            bad |= ((c[v] + to.snd + mod) % mod) != c[to.fst];
        } else {
            c[to.fst] = (c[v] + to.snd + mod) % mod;
            dfs2(to.fst);
        }
    }
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
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(mp(v, 1));
        g[v].pb(mp(u, -1));
    }

    cu++;
    for (int i = 1; i <= n; i++) {
        if (used[i] != cu) {
            dfs(i);
        }
    }


    if (ub == -1) {
        cout << n << endl;
        return 0;
    }

    for (int i = ub; i >= 1; i--) {
        if (ub % i == 0) {
            cu++;
            fill(c, c + maxn, 0);
            mod = i;
            bad = false;
            for (int j = 1; j <= n; j++) {
                if (used[j] != cu) {
                    dfs2(j);
                }
            }


            if (!bad) {
                cout << i << endl;
                return 0;
            }
        }
    }




    return 0;
}