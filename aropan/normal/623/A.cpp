#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> void chmin(T &x, const T y) { if (x > y) { x = y; } }
template <typename T> void chmax(T &x, const T y) { if (x < y) { x = y; } }

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

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n, m;
    while (cin >> n >> m) {
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u -= 1;
            v -= 1;
            f[u][v] = f[v][u] = 1;
        }
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        int x = -1, y = -1;
        for (int i = 0; i < n && x == -1; ++i) {
            for (int j = i + 1; j < n && y == -1; ++j) {
                if (f[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        bool ok = true;
        string s;
        s.resize(n, 'a');
        if (x != -1) {
            for (int i = 0; i < n; ++i) {
                if (!f[x][i] && !f[y][i]) {
                    ok = false;
                    break;
                }
                if (f[x][i] && f[y][i]) {
                    s[i] = 'b';
                } else
                if (f[x][i]) {
                    s[i] = 'a';
                } else
                if (f[y][i]) {
                    s[i] = 'c';
                }
            }
        }
        for (int i = 0; i < n && ok; ++i) {
            for (int j = 0; j < n && ok; ++j) {
                if ((abs(s[i] - s[j]) < 2) ^ f[i][j]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            cout << s << endl;
        } else {
            cout << "No" << endl;
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}