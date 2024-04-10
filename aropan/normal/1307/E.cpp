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
#define dbg(x) cout << #x " = " << x << endl;
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


const int MOD = (int)1e+9 + 7;

#define F first
#define H second


void addmod(int& x, int v) {
    x += v;
    if (x >= MOD) {
        x -= MOD;
    } else if (x < 0) {
        x += MOD;
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

    int n, m;
    while (cin >> n >> m && n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        set<pair<int, int>> s;
        vector<pair<int, int>> cows;
        for (int i = 0; i < m; ++i) {
            int f, h;
            cin >> f >> h;
            s.insert({f, h});
            cows.push_back({f, h});
        }
        sort(all(cows));

        vector<int> l(n + 1);
        vector<int> r(n + 1);

        for (int i = 0; i < n; ++i) {
            r[a[i]] += 1;
        }

        auto get= [&](int F, int H) -> pair<int, int> {
            int opt = 0;
            ll ans = 1;
            for (int i = 0, j = 0; i < m; i = j) {
                int lc = 0;
                int rc = 0;
                bool ok = false;

                while (j < m && cows[i].F == cows[j].F) {
                    int f = cows[j].F;
                    int h = cows[j].H;
                    ++j;

                    if (f == F && h == H) {
                        ok = true;
                        continue;
                    }
                    lc += l[f] >= h;
                    rc += r[f] >= h;
                }

                if (ok) {
                    if (rc) {
                        opt += 2;
                        ans = ans * rc % MOD;
                    } else {
                        opt += 1;
                    }
                } else {
                    if (lc > rc) {
                        swap(lc, rc);
                    }
                    if (lc) {
                        if (1 < rc) {
                            opt += 2;
                            ans = ans * lc * (rc - 1) % MOD;
                        } else {
                            opt += 1;
                            ans = ans * 2 % MOD;
                        }
                    } else {
                        if (rc) {
                            opt += 1;
                            ans = ans * rc % MOD;
                        }
                    }
                }
            }
            // cout << idbg(opt) << ", " << idbg(ans) << endl;
            return {opt, ans};
        };
        pair<int, int> ans = {0, 0};
        auto update = [&](pair<int, int>& ans, pair<int, int> res) {
            if (res.first > ans.first) {
                ans = res;
            } else if (res.first == ans.first) {
                addmod(ans.second, res.second);
            }
        };
        update(ans, get(-1, -1));
        for (int i = 0; i < n; ++i) {
            l[a[i]] += 1;
            r[a[i]] -= 1;
            if (s.count({a[i], l[a[i]]})) {
                update(ans, get(a[i], l[a[i]]));
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}