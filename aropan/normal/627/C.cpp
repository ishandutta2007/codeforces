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

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }


#define X first
#define P second

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int d, n, m;
    scanf("%d %d %d", &d, &n, &m);
    vector < pair <int, int> > a;
    for (int i = 0; i < m; ++i) {
        int x, p;
        scanf("%d %d", &x, &p);
        a.emplace_back(x, p);
    }
    a.emplace_back(d, 0);
    sort(a.begin(), a.end());
    map <int, int> mp;
    mp[0] = n;
    int x = 0;
    ll ans = 0;
    ll t = n;
    for (size_t i = 0; i < a.size(); ++i) {
        int l = a[i].X - x;
        if (l > n) {
            ans = -1;
            break;
        }
        while (l) {
            auto it = mp.begin();
            int v = min(l, it->second);
            ans += it->first * (ll)v;
            l -= v;
            it->second -= v;
            t -= v;
            if (it->second == 0) {
                mp.erase(it);
            }
        }
        while (t) {
            auto it = mp.end();
            --it;
            if (it->first < a[i].P) {
                break;
            }
            t -= it->second;
            mp.erase(it);
        }
        mp[a[i].P] = n - t;
        t = n;

        x = a[i].X;
    }
    cout << ans << endl;
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}