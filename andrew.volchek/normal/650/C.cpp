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

const int maxn = 1e6 + 5;

vector<vector<int>> a;
vector<vector<int>> rows, cols;

int n, m;
int enc(int x, int y) {
    return m * x + y;
}

vector<int> g[maxn];
int deg[maxn];
int val[maxn];

int dsu[maxn];
int sz[maxn];

int find(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = find(dsu[v]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        dsu[u] = v;
        sz[v] += sz[u];
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

    scanf("%d %d", &n, &m);
    a.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n * m; i++) {
        sz[i] = 1;
        dsu[i] = i;
    }

    rows.resize(n);
    cols.resize(m);


    for (int i = 0; i < n; i++) {
        rows[i].resize(m);
        iota(rows[i].begin(), rows[i].end(), 0);
        sort(rows[i].begin(), rows[i].end(), [&](int u, int v) {
            return a[i][u] < a[i][v];
        });

        for (int j = 0; j < m; j++) {
            int h = j;
            while (h < m && a[i][rows[i][h]] == a[i][rows[i][j]]) {
                h++;
            }

            for (int k = j; k + 1 < h; k++) {
                unite(enc(i, rows[i][k]), enc(i, rows[i][k + 1]));
            }
            j = h - 1;
        }
    }

    for (int i = 0; i < m; i++) {
        cols[i].resize(n);
        iota(cols[i].begin(), cols[i].end(), 0);
        sort(cols[i].begin(), cols[i].end(), [&](int u, int v) {
            return a[u][i] < a[v][i];
        });

        for (int j = 0; j < n; j++) {
            int h = j;
            while (h < n && a[cols[i][h]][i] == a[cols[i][j]][i]) {
                h++;
            }

            for (int k = j; k + 1 < h; k++) {
                unite(enc(cols[i][k], i), enc(cols[i][k + 1], i));
            }
            j = h - 1;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int h = j;
            while (h < m && a[i][rows[i][j]] == a[i][rows[i][h]]) {
                h++;
            }

            if (j) {
                int u = find(enc(i, rows[i][j - 1]));
                int v = find(enc(i, rows[i][j]));
                g[u].pb(v);
                deg[v]++;
            }

            j = h - 1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int h = j;
            while (h < n && a[cols[i][h]][i] == a[cols[i][j]][i]) {
                h++;
            }

            if (j) {
                int u = find(enc(cols[i][j - 1], i));
                int v = find(enc(cols[i][j], i));
                g[u].pb(v);
                deg[v]++;
            }
            j = h - 1;
        }
    }

    queue<int> q;
    for (int i = 0; i < n * m; i++) {
        if (!deg[i]) {
            q.push(i);
            val[i] = 1;
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            chmax(val[to], val[v] + 1);
            deg[to]--;
            if (!deg[to]) {
                q.push(to);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) {
                printf(" ");
            }

            printf("%d", val[find(enc(i, j))]);
        }
        printf("\n");
    }


    return 0;
}