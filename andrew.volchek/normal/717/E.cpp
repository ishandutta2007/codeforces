#include <cstdio>
#include <set>
#include <ostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <assert.h>
#include <iomanip>
#include <map>

using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double


const ld pi = acos(-1);


template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
ostream& operator << (ostream &s, const vector<T> &x) {
    s << "[";
    for (typename vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
        s << *it << ", ";
    }
    s << "]";
    return s;
}

template<typename T>
ostream& operator << (ostream &s, const set<T> &x) {
    s << "{";
    for (typename set<T>::iterator it = x.begin(); it != x.end(); ++it) {
        s << *it << ", ";
    }
    s << "}";
    return s;
}


template<typename U, typename V>
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

//---------------------------------------------------------------------

const int maxn = 2e5 + 5;

vector<int> g[maxn];
int color[maxn];
vector<int> ans;

void dfs(int v, int p) {
    ans.pb(v);

    if (v != 1) {
        color[v] ^= 1;
    }

    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            ans.pb(v);
            color[v] ^= 1;
        }
    }


    for (int to : g[v]) {
        if (to == p) {
            continue;
        }

        if (color[to] == 0) {
            color[to] ^= 1;
            color[v] ^= 1;
            ans.pb(to);
            ans.pb(v);
        }
    }

    if (v == 1 && !color[v]) {
        ans.pop_back();
        color[v] ^= 1;
    }
}

int main() {

    retry:
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#else
    //freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        color[i] = x == 1;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 1);

    for (int i = 1; i <= n; i++) {
        assert(color[i]);
    }

    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");



    return 0;
}