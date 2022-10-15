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

const int MOD = 998244353;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> mp;
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            mp[b[i]] = i;
        }

        vector<int> p(m, -1);
        for (int i = 0; i < n; ++i) {
            auto it = mp.find(a[i]);
            if (it == mp.end()) {
                continue;
            }
            p[it->second] = i;
        }

        vector<int> smin(n, 0);
        smin[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            smin[i] = min(smin[i + 1], a[i]);
        }


        bool ok = smin[0] == b[0];
        ll ans = 1;

        for (int i = 1; i < m; ++i) {
            if (p[i] == -1) {
                ok = false;
                break;
            }
            int j = p[i];
            while (j > p[i - 1] && smin[j] >= b[i]) {
                --j;
            }
            ans = ans * (p[i] - j) % MOD;
        }

        cout << (ok? ans : 0) << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}