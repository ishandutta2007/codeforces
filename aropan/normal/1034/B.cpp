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


vector <vector<int>> e;
vector <int> p;
int cnt;
vector<int> upd;

bool rec(int x) {
    if (upd[x] == cnt) {
        return false;
    }
    upd[x] = cnt;
    for (auto& y : e[x]) {
        if (p[y] == -1 || rec(p[y])) {
            p[y] = x;
            return true;
        }
    }
    return false;
}

ll get(ll n, ll m) {
    if (n > m) {
        swap(n, m);
    }
    if (n == 1) {
        m %= 6;
        return 3 - abs(m - 3);
    }

    if (n == 2) {
        if (m == 2) {
            return 4;
        }
        if (m == 1 || m == 3 || m == 7) {
            return 2;
        }
        return 0;
    }

    return (n * m) & 1;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    ll n, m;
    cin >> n >> m;
    cout << n * m - get(n, m) << endl;

/*
    for (int n = 1; n <= 50; ++n) {
        for (int m = 1; m <= 50; ++m) {
            int k = n * m;
            e.resize(k);
            for (int i = 0; i < k; ++i) {
                e[i].clear();
            }
            int ind1 = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int ind2 = 0;
                    if ((i + j) & 1) {
                        for (int x = 0; x < n; ++x) {
                            for (int y = 0; y < m; ++ y) {
                                if (abs(i - x) + abs(j - y) == 3) {
                                    e[ind1].push_back(ind2);
                                }
                                ++ind2;
                            }
                        }
                    }
                    ++ind1;
                }
            }
            int ans = 0;
            p = vector<int>(k, -1);
            upd = vector<int>(k, 0);
            cnt = 0;
            for (int i = 0; i < k; ++i) {
                ++cnt;
                if (rec(i)) {
                    ans += 2;
                }
            }
            cout << n * m - ans << " ";
            assert(n * m - ans == get(n, m));
        }
        cout << endl;
    }
*/

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}