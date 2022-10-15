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
    int n;
    while (cin >> n) {
        vector <int> e[n];
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        vector<int> f(n, 0);
        queue <set<int>> q;
        set<int> s;
        s.insert(0);
        f[0] = true;
        q.push(s);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            if (!q.front().count(x)) {
                ok = false;
                break;
            }
            q.front().erase(x);
            if (q.front().size() == 0) {
                q.pop();
            }

            set<int> s;
            for (auto& y : e[x]) {
                if (!f[y]) {
                    s.insert(y);
                    f[y] = true;
                }
            }
            if (s.size()) {
                q.push(s);
            }
        }
        cout << (ok? "Yes" : "No") << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}