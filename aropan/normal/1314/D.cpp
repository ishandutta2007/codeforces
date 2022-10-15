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

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#define idbg(x) #x " = " << x
#include "pretty_print.h"
#else
#define dbg(x)
#define idbg(x) ""
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


const ll INF = (ll)1e+18 + 42;

int n, k;
vector<vector<ll>> a;
vector<vector<ll>> d;
vector<int> c;
vector<int> t;
ll ans;


void rec(int x, ll s, int b, int k) {
    if (c[x] && t[x] != b) {
        return;
    }

    if (k == 1) {
        ans = min(ans, s + a[x][0]);
        return;
    }

    if (s + d[k][x] >= ans) {
        return;
    }

    c[x] += 1;
    t[x] = b;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    sort(all(p), [&](const int fs, const int sc) { return a[x][fs] + d[k - 1][fs] < a[x][sc] + d[k - 1][sc]; });
    for (auto& i : p) {
        rec(i, s + a[x][i], b ^ 1, k - 1);
    }

    c[x] -= 1;
    return;
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    srand(42);

    cin >> n >> k;
    // n = 80;
    // k = 10;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            // a[i][j] = rand() % 1000 + 100000000;
        }
    }

    d = vector<vector<ll>>(k + 1, vector<ll>(n, INF));
    d[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (x != y) {
                    chmin(d[i][x], a[x][y] + d[i - 1][y]);
                }
            }
        }
    }

    ans = INF;
    c = vector<int>(n, 0);
    t = vector<int>(n, 0);
    rec(0, 0, 0, k);

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}