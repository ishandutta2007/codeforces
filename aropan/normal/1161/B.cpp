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


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, k;
    while (cin >> n >> k) {
        vector<pair<int, int>> a(k);
        set<pair<int, int>> st;
        for (int i = 0; i < k; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            if (u > v) {
                swap(u, v);
            }
            st.insert(make_pair(u, v));
            a[i] = make_pair(u, v);
        }
        bool ok = false;
        for (int d = 1; d < n; ++d) {
            if (n % d == 0) {
                auto s = st;
                ok = true;
                for (auto p : a) {
                    int u = (p.first + d) % n;
                    int v = (p.second + d) % n;
                    if (u > v) {
                        swap(u, v);
                    }
                    auto it = s.find(make_pair(u, v));
                    if (it == s.end()) {
                        ok = false;
                        break;
                    }
                    s.erase(it);
                }
                if (ok) {
                    break;
                }
            }
        }
        cout << (ok? "Yes" : "No") << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}