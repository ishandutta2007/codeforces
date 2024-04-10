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
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1e3 + 5;

int g[maxn][maxn];
ld dist[maxn];
ld sum[maxn], q[maxn];
int used[maxn];

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

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        dist[i] = 1e18;
        sum[i] = 0;
        q[i] = 1;
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    dist[n - 1] = 0;
    const ld eps = 1e-18;

    for (int i = 0; i < n; i++) {
        int j = -1;
        for (int h = 0; h < n; h++) {
            if (used[h]) {
                continue;
            }

            if (j == -1 || dist[h] < dist[j]) {
                j = h;
            }
        }

        used[j] = 1;

        for (int h = 0; h < n; h++) {
            if (dist[h] > dist[j]) {
                sum[h] += q[h] * (dist[j] + 1) * (g[h][j] / 100.0);
                q[h] *= 1.0 - g[h][j] / 100.0;

                if (abs(q[h] - 1.0) < eps) {
                    dist[h] = 1e18;
                } else {
                    dist[h] = (sum[h] + q[h]) / (1.0 - q[h]);
                }
            }
        }
    }

    cout.precision(20);
    cout << fixed << dist[0] << endl;

    return 0;
}