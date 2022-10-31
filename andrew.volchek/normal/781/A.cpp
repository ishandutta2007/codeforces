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

int color[maxn];
void dfs(int v, int p, int a = -1) {
    int d = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        while (d == a || d == color[v]) {
            d++;
        }
        color[to] = d++;
        dfs(to, v, color[v]);
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


    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1, -1);

    cout << *max_element(color + 1, color + 1 + n) + 1 << endl;
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << color[i] + 1;
    }
    cout << endl;




    return 0;
}