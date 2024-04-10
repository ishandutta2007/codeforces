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

vector<int> p;
int cnt;
map<pair<int, int>, int> mp;

int get(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    auto k = make_pair(x, y);
    if (mp.count(k)) {
        return mp[k];
    }

    ++cnt;
    int ret;
#ifdef LOCAL
    ret = p[x] | p[y];
#else
    cout << "? " << x + 1 << " " << y + 1 << endl;
    cout.flush();
    cin >> ret;
#endif
    mp[k] = ret;
    return ret;
}

int main(int /* argc */, char** /* argv */)
{
    // 44
    srand(time(NULL));
#ifdef LOCAL
    assert(freopen("inp", "r", stdin));
#endif

    int n;
    cin >> n;
    mp.clear();

#ifdef LOCAL
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        swap(p[i], p[rand() % (i + 1)]);
    }
#endif

    int m = n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    int k = 0;
    for (int b = 1; b < n; b *= 2) {
        ++k;
    }
    int msk = 0;

    int zero = -1;
    cnt = 0;
    for (; msk + 1 < (1 << k); a.resize(m)) {
        int popcount = __builtin_popcount(msk);
        if (popcount > k / 2) {
            break;
        }

        if (a.size() == 1) {
            break;
        }

        int x;
        int y;
        do {
            x = rand() % m;
            y = rand() % m;
        } while (x == y);

        if (x > y) {
            swap(x, y);
        }

        int r = get(a[x], a[y]);
        r |= msk;
        int d = ((1 << k) - 1) ^ r;

        if (d == 0) {
            continue;
        }

        if (msk == 0) {
            zero = x;
            msk = d;
            continue;
        }

        if (zero != a[y] && (get(zero, a[y]) & msk)) {
            swap(a[y], a[--m]);
        } else {
            zero = a[y];
            msk |= d;
            continue;
        }

        if (zero != a[x] && (get(zero, a[x]) & msk)) {
            swap(a[x], a[--m]);
        } else {
            zero = a[x];
            msk |= d;
            continue;
        }
    }

    vector<int> b;
    for (auto& x : a) {
        if (x == zero || (get(zero, x) & msk) == 0) {
            b.push_back(x);
        }
    }

    msk = (1 << k) - 1 - msk;
    a.swap(b);
    m = a.size();
    for (; a.size() > 1; a.resize(m)) {
        int x;
        int y;
        do {
            x = rand() % m;
            y = rand() % m;
        } while (x == y);

        if (x > y) {
            swap(x, y);
        }

        int z;
        do {
            z = rand() % n;
        } while (a[x] == z || a[y] == z);

        int rx = get(a[x], z) & msk;
        int ry = get(a[y], z) & msk;
        if (rx == ry) {
            continue;
        }
        if (rx > ry) {
            swap(x, y);
            swap(rx, ry);
        }
        swap(a[y], a[--m]);
    }

    zero = a[0];


#ifdef LOCAL
    assert(p[zero] == 0);
#endif

    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i != zero) {
            ans[i] = get(zero, i);
        }
    }

#ifndef LOCAL
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    cout.flush();
#endif
    dbg(cnt);

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}