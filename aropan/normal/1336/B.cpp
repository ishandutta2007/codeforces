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

vector<vector<int>> e;
vector<ll> f;
vector<ll> s;


void dfs(int x, int p, ll d) {
    s[x] = 0;
    for (auto& y : e[x]) {
        if (y == p) {
            continue;
        }
        dfs(y, x, d + 1);
        s[x] += s[y] + 1;
    }
    f[x] = d - s[x];
}


ll get(ll x, ll y, ll z) {
    return sqr(x - y) + sqr(x - z) + sqr(y - z);
}


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n[3];
        cin >> n[0] >> n[1] >> n[2];
        vector<ll> a[3];
        for (int i = 0; i < 3; ++i) {
            a[i].resize(n[i]);
            for (int j = 0; j < n[i]; ++j) {
                cin >> a[i][j];
            }
            sort(all(a[i]));
        }
        vector<int> p = {0, 1, 2};
        ll ans = (ll)9e+18;
        do {
            vector<ll> b[3];
            vector<ll> s(3);
            for (int i = 0; i < 3; ++i) {
                b[i] = a[p[i]];
                s[i] = b[i].size();
            }

            for (int i = 0, j = 0, k = 0; i < s[0]; ++i) {
                while (j < s[1] && b[0][i] > b[1][j]) {
                    ++j;
                }
                if (j == s[1]) {
                    break;
                }
                while (k + 1 < s[2] && get(b[0][i], b[1][j], b[2][k]) >= get(b[0][i], b[1][j], b[2][k + 1])) {
                    ++k;
                }
                chmin(ans, get(b[0][i], b[1][j], b[2][k]));
            }
        } while (next_permutation(all(p)));
        cout << ans << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}