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

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 505;
int used[maxn];
int g[maxn][maxn];

int color[maxn];
int n;

void dfs(int v, int c) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == v) {
            continue;
        }
        cnt += !g[v][i];
    }

    if (cnt == 0) {
        color[v] = 1;
        return;
    }

    color[v] = c;
    for (int i = 0; i < n; i++) {
        if (i == v) {
            continue;
        }
        if (!g[v][i] && color[i] == -1) {
            dfs(i, 2 - c);
        }
    }
}

int main() {
    //srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }

    fill(color, color + maxn, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            dfs(i, 0);
        }
    }

    bool good = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(color[i] - color[j]) <= 1) {
                good &= g[i][j];
            } else {
                good &= !g[i][j];
            }
        }
    }

    if (good) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << char('a' + color[i]);
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}