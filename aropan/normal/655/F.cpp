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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MOD = 1e+9 + 7;

const int MAXN = 2e+5 + 1;
const int MAXX = 1e+6 + 1;

int f[MAXN];
int f_[MAXN];
int p[MAXX];
int g[MAXX];
vector <int> d[MAXX];

typedef map <int, int>::iterator miter;

void addmod(int &x, const int& d) {
    x += d;
    if (x >= MOD) {
        x -= MOD;
    } else
    if (x < 0) {
        x += MOD;
    }
}

int powmod(int a, int b)
{
    if (b == 0) {
        return 1;
    }
    ll res = powmod(a, b >> 1);
    (res *= res) %= MOD;
    return b & 1? res * a % MOD : res;
}

int divmod(int a, int b) {
    return a * (ll)powmod(b, MOD - 2) % MOD;
}

int C(int n, int k)
{
    if (n < k) {
        return 0;
    }
    int result = f[n] * (ll)f_[n - k] % MOD * (ll)f_[k] % MOD;
    return result;
}

void gen(int x, int k, const vector < pair <int, int> >& d, vector <int>& result)
{
    if (k == (int)d.size()) {
        result.push_back(x);
        return;
    }

    for (int i = 0; i <= d[k].second; ++i) {
        gen(x, k + 1, d, result);
        x *= d[k].first;
    }
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        f[i] = f[i - 1] * (ll)i % MOD;
    }
    for (int i = 0; i < MAXN; ++i) {
        f_[i] = powmod(f[i], MOD - 2);
    }

    memset(p, 0, sizeof(p));
    for (int i = 1; i < MAXX; ++i) {
        for (int j = i; j < MAXX; j += i) {
            d[j].push_back(i);
        }
    }

    int n, k, q;
    while (cin >> n >> k >> q && n) {
        //n = 100000;
        //k = 1;
        //q = 100000;
        int c[MAXX];
        memset(c, 0, sizeof(c));
        int ans = 0;
        for (int i = 0; i < n + q; ++i) {
            int v;
            cin >> v;
            //v = rand() % (int)1e+6 + 1;
            //v = 997920;
            vector <int> a = d[v];
            int t = a.size();
            for (int j = t - 1; j >= 0; --j) {
                int x = a[j];
                addmod(g[x], C(c[x]++, k - 1));
                addmod(ans, g[x] * (ll)x % MOD);
                for (auto& l : d[x]) {
                    addmod(g[l], -g[x]);
                }
            }
            if (n <= i) {
                cout << ans << "\n";
            }
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}