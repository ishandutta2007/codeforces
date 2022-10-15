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
#include "pretty_print.h"
#else
#define dbg(x)
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

#define X first
#define Y second

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int INF = 1e+9 + 42;
const int MOD = 1000000007;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n) {
        int ans = 1;
        set<int> l;
        set<int> r;
        l.insert(-INF);
        r.insert(INF);
        vector <int> v;

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            string c;
            int p;
            cin >> c >> p;
            if (c == "ADD") {
                v.push_back(p);
            } else {
                int pmin = *l.rbegin();
                int pmax = *r.begin();
                if (pmin < p && p < pmax) {
                    ans += ans;
                    if (ans >= MOD) {
                        ans -= MOD;
                    }
                } else if (p <= pmin) {
                    auto it = l.find(p);
                    if (it != l.end()) {
                        l.erase(it);
                    }
                } else if (pmax <= p) {
                    auto it = r.find(p);
                    if (it != r.end()) {
                        r.erase(it);
                    }
                }

                ok &= pmin <= p && p <= pmax;

                for (auto& x : v) {
                    if (x < p) {
                        l.insert(x);
                    } else if (p < x) {
                        r.insert(x);
                    }
                }
                v.clear();
            }
        }
        {
            int pmin = *l.rbegin();
            int pmax = *r.begin();
            int c = 0;
            for (auto&x : v) {
                c += (pmin < x && x < pmax);
            }
            ans = ans * (ll)(c + 1) % MOD;
        }
        cout << (ok? ans : 0) << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}