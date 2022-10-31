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
const int maxn = 3e5 + 5;
vector<pair<int, int>> g[maxn];
int go[maxn][26];

int mcnt = 0;
void foo(vector<int> s) {
    for (int i = 0; i < 26; i++) {
        vector<int> ns;
        for (int x : s) {
            if (go[x][i] != -1) {
                ns.pb(go[x][i]);
            }
        }
        if (ns.size() > 1) {
            mcnt += ns.size() - 1;
            foo(ns);
        }
    }
}

int ans[maxn];
int was[maxn];
int sz[maxn];

void dfs(int v) {
    sz[v] = g[v].size();
    for (auto to : g[v]) {
        dfs(to.fst);
        sz[v] += sz[to.fst];
    }
}

void dfs2(int v, int d) {
    if (g[v].size()) {
        was[d] = 1;
    }

    ans[d] -= g[v].size();

    vector<int> s;
    for (int i = 0; i < 26; i++) {
        if (go[v][i] != -1) {
            s.pb(go[v][i]);
        }
    }
    mcnt = 0;
    foo(s);
    ans[d] -= mcnt;

    for (auto to : g[v]) {
        dfs2(to.fst, d + 1);
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
    for (int i = 0; i < maxn; i++) {
        fill(go[i], go[i] + 26, -1);
    }

    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        scanf("%d %d %c\n", &u, &v, &c);
        go[u][c - 'a'] = v;
        g[u].pb(mp(v, c - 'a'));
    }

    dfs(1);



    dfs2(1, 1);
    pair<int, int> bst(1e9, 1e9);
    for (int i = 1; i < maxn; i++) {
        if (was[i]) {
            chmin(bst, mp(ans[i], i));
        }
    }

    cout << sz[1] + bst.fst + 1 << endl;
    cout << bst.snd << endl;



    return 0;
}