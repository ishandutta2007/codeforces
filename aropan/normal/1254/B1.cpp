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

    int n;
    while (cin >> n) {
        vector<int> a(n);
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s += a[i];
        }

        vector<ll> c;
        {
            ll m = s;
            for (ll i = 2; i * i <= m; ++i) {
                if (m % i == 0) {
                    c.push_back(i);
                    do { m /= i; } while (m % i == 0);
                }
            }
            if (m > 1) {
                c.push_back(m);
            }
        }
        dbg(c);

        vector<ll> b, p;
        ll t;

        ll ans = -1;
        for (auto& d : c) {
            ll res = 0;
            b.clear();
            p.clear();
            t = 0;
            for (int i = 0; i < n; ++i) {
                ll x = a[i] % d;
                if (t + x >= d) {
                    b.push_back(d - t);
                    p.push_back(i);

                    int tind = 0;
                    {
                        ll left = (d + 1) / 2;
                        for (int i = 0; i < (int)b.size(); ++i) {
                            left -= b[i];
                            if (left <= 0) {
                                tind = p[i];
                                break;
                            }
                        }
                    }

                    for (int i = 0; i < (int)b.size(); ++i) {
                        res += b[i] * abs(p[i] - tind);
                    }

                    x -= d - t;
                    t = 0;
                    b.clear();
                    p.clear();
                }

                if (x) {
                    t += x;
                    b.push_back(x);
                    p.push_back(i);
                }
            }

            if (ans == -1 || res < ans) {
                ans = res;
            }
        }
        cout << ans << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}