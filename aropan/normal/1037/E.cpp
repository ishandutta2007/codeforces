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
    int n, m, k;
    while (cin >> n >> m >> k) {
        set <int> a[n];
        int u[m];
        int v[m];
        for (int i = 0; i < m; ++i) {
            cin >> u[i] >> v[i];
            --u[i];
            --v[i];
            a[u[i]].insert(v[i]);
            a[v[i]].insert(u[i]);
        }


        queue<int> q;

        bool f[n];
        for (int i = 0; i < n; ++i) {
            f[i] = a[i].size() >= k;
            if (!f[i]) {
                q.push(i);
            }
        }

        int res = n;
        vector<int> ans;
        for (int i = m - 1; i >= 0; --i) {
            while (q.size()) {
                int x = q.front();
                --res;
                q.pop();
                for (auto& y : a[x]) {
                    if (f[y]) {
                        a[y].erase(x);
                        if (a[y].size() < k) {
                            f[y] = false;
                            q.push(y);
                        }
                    }
                }
            }
            ans.push_back(res);
            int x = u[i], y = v[i];
            if (f[x] && f[y]) {
                for (int iter = 0; iter < 2; ++iter) {
                    a[y].erase(x);
                    if (a[y].size() < k) {
                        f[y] = false;
                        q.push(y);
                    }
                    swap(x, y);
                }
            }
        }
        reverse(all(ans));
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << "\n";
        }
        cout << endl;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}