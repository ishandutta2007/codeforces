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

struct TPoint {
    ll x, y;
};

TPoint operator-(const TPoint& a, const TPoint& b) {
    return {a.x - b.x, a.y - b.y};
}

vector<TPoint> p;
vector<int> perm;

ll get(int t, int i, int j, int k) {
    #ifdef LOCAL
    --i;
    --j;
    --k;
    if (t == 1) {
        vector<int> a = {i, j, k, i};
        ll s = 0;
        for (int i = 0; i < 3; ++i) {
            s +=
                (p[perm[a[i]]].x - p[perm[a[i + 1]]].x) *
                (p[perm[a[i]]].y + p[perm[a[i + 1]]].y);

        }
        return abs(s);
    }

    if (t == 2) {
        TPoint a = p[perm[j]] - p[perm[i]];
        TPoint b = p[perm[k]] - p[perm[i]];
        return a.x * b.y - a.y * b.x;
    }
    exit(1);
    #endif

    cout << t << " " << i << " " << j << " " << k << endl;
    cout.flush();

    ll ret;
    cin >> ret;
    return ret;
}

void psort(vector<int>& a, int scnd, int sign) {
    ll n = a.size();
    if (n == 0) {
        return;
    }
    vector<pair<ll, ll>> d;
    for (ll i = 0; i < n; ++i) {
        d.push_back({get(1, 1, scnd, a[i]), a[i]});
    }

    sort(all(d));
    reverse(all(d));

    vector<pair<ll, ll>> l, r;
    for (ll i = 1; i < n; ++i) {
        ll s = get(2, 1, d[0].second, d[i].second);
        if (s * sign > 0) {
            l.push_back(d[i]);
        } else {
            r.push_back(d[i]);
        }
    }
    sort(all(l));
    sort(all(r));
    reverse(all(r));

    a.clear();
    for (auto x : l) {
        a.push_back(x.second);
    }
    a.push_back(d[0].second);
    for (auto x : r) {
        a.push_back(x.second);
    }
};


int main(int /* argc */, char** /* argv */)
{
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n;
    cin >> n;

    #ifdef LOCAL
    {
        ll x = 0;
        ll y = 0;
        ll dx = n;
        ll dy = 0;
        p.clear();
        for (int i = 0; i < n; ++i) {
            p.push_back({x, y});
            x += dx;
            y += dy;
            --dx;
            ++dy;
        }
    }

    perm.resize(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        swap(perm[i], perm[rand() % (i + 1)]);
    }
    dbg(perm);
    #endif

    int scnd = 2;

    vector<int> left, right;
    for (int i = 2; i <= n; ++i) {
        if (i == scnd) {
            continue;
        }
        int s = get(2, 1, scnd, i);
        if (s > 0) {
            left.push_back(i);
        } else {
            right.push_back(i);
        }
    }

    psort(left, scnd, 1);
    reverse(all(left));
    psort(right, scnd, -1);

    vector<int> ans = {1};
    for (auto x : right) {
        ans.push_back(x);
    }
    ans.push_back(scnd);
    for (auto x : left) {
        ans.push_back(x);
    }

    // for (int i = 0; i < n; ++i) {
    //     cerr << perm[ans[i] - 1] << " ";
    // }
    // cerr << endl;

    cout << 0;
    for (int i = 0; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;
    cout.flush();

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}