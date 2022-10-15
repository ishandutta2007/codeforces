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
#include <iomanip>
#include <numeric>

using namespace std;

#define snd second
#define fst first

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

vector <int> nxt;
vector <int> xr;

int mfind(int x) {
    if (x == nxt[x]) {
        return x;
    }
    int res = mfind(nxt[x]);
    xr[x] = xr[nxt[x]] ^ xr[x];
    nxt[x] = res;
    return res;
}

int munion(int u, int v, int w = -1) {
    int U = mfind(u);
    int V = mfind(v);
    // cout << U << " " << V << " " << xr[u] << " " << xr[v] << endl;
    if (w == -1) {
        return (U == V)? xr[u] ^ xr[v] : 2;
    }
    if (U == V) {
        return (xr[u] ^ xr[v]) == w;
    }
    if (rand() & 1) {
        swap(U, V);
    }
    nxt[U] = V;
    xr[U] = w ^ xr[u] ^ xr[v];
    // cout << U << " -> " << V << " = " << w << endl;
    return true;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
#endif
    map <string, int> s;
    int n, m, q;
    while (cin >> n >> m >> q) {
        srand(42);
        // n = 100000;
        // m = 100000;
        // q = 100000;
        nxt.resize(n);
        xr.resize(n);
        for (int i = 0; i < n; ++i) {
            nxt[i] = i;
            xr[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            string c;
            cin >> c;
            // c = to_string(i);
            s[c] = i;
        }
        while (m--) {
            int x;
            string a, b;
            cin >> x >> a >> b;
            int u = s[a];
            int v = s[b];
            // u = rand() % n;
            // v = rand() % n;
            // x = (rand() & 1) + 1;
            // cout << u << " " << v << " " << x << endl;
            cout << (munion(u, v, x - 1)? "YES" : "NO") << "\n";
        }
        while (q--) {
            string a, b;
            cin >> a >> b;
            int u = s[a];
            int v = s[b];
            // u = rand() % n;
            // v = rand() % n;
            cout << munion(u, v) + 1 << "\n";
        }
        // break;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}