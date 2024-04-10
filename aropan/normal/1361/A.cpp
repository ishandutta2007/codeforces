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


const int MOD = 1000000007;

ll powmod(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll r = powmod(a, b >> 1);
    r = r * r % MOD;
    return (b & 1)? r * a % MOD : r;
}


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
        vector<vector<int>> e(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        vector<int> t(n);
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first;
            v[i].second = i;
            t[i] = v[i].first;
        }
        vector<int> ans;
        sort(all(v));
        bool ok = true;
        for (auto& [val, x] : v) {
            set<int> st;
            for (auto& y : e[x]) {
                if (t[y] <= val) {
                    st.insert(t[y]);
                }
            }
            if ((int)st.size() != val - 1 || st.count(val)) {
                ok = false;
                break;
            }
            ans.push_back(x);
        }
        if (!ok) {
            cout << "-1" << "\n";
        } else {
            for (int i = 0; i < n; ++i) {
                if (i) {
                    cout << " ";
                }
                cout << ans[i] + 1;
            }
            cout << "\n";
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}