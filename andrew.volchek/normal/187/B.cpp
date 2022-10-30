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


const int maxn = 67;
const int inf = 1e9;

int a[maxn][maxn];
int b[maxn][maxn];
int d[maxn][maxn][maxn];

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

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        fill(a[i], a[i] + maxn, inf);
        a[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &b[j][k]);
            }
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int h = 0; h < n; h++) {
                    chmin(b[k][h], b[k][j] + b[j][h]);
                }
            }
        }



        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                chmin(a[j][k], b[j][k]);
            }
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                d[i][j][k] = inf;
            }
            d[i][j][j] = 0;
        }
    }


    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                d[i][j][k] = d[i - 1][j][k];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int h = 0; h < n; h++) {
                    chmin(d[i][k][h], d[i - 1][k][j] + a[j][h]);
                    chmin(d[i][k][h], a[k][j] + d[i - 1][j][h]);
                }
            }
        }
    }

    for (int i = 0; i < r; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        w = min(w, maxn - 2);
        cout << d[w + 1][u][v] << endl;
    }



    return 0;
}