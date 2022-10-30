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
#define ld double
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

template<int sz>
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;
vector<int> g[maxn];
vector<int> gt[maxn];
int c[maxn];
int a[maxn];
int b[maxn];


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

    for (int i = 1; i <= n; i++) {
        scanf("%d", c + i);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        gt[v].pb(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1) {
            a[i] = 1;
            for (int to : g[i]) {
                if (c[to] != 1 && !a[to]) {
                    a[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (!a[to] && c[to] != 1) {
                a[to] = 1;
                q.push(to);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (c[i] == 2) {
            b[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : gt[v]) {
            if (!b[to] && c[to] != 1) {
                b[to] = 1;
                q.push(to);
            } else if (!b[to] && c[to] == 1) {
                b[to] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", (a[i] && b[i]));
    }

    return 0;
}