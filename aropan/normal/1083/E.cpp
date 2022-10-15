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
#include <deque>

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

typedef tuple<ll, ll, ll> tripl;


vector<tripl> p;


struct TPoint {
    ld x, y;
};

struct TLine {
    TPoint p, q;
    ld a, b, c;

    TLine(TPoint p = {0, 0}, TPoint q = {0, 0}) : p(p), q(q) {
        a = q.y - p.y;
        b = p.x - q.x;
        c = -(p.x * a + p.y * b);
    }

    ld operator()(ld y) const {
        return (y - p.y) / (q.y - p.y) * (q.x - p.x) + p.x;
    }

    TPoint intersect(const TLine& l) {
        ld d = a * l.b - b * l.a;

        ld x = -(c * l.b - b * l.c) / d;
        ld y = -(a * l.c - c * l.a) / d;

        return {x, y};
    }
};

struct TPair {
    TLine l;
    TPoint p;
};

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
        p.resize(n);
        for (int i = 0; i < n; ++i) {
            ll x, y, a;
            cin >> x >> y >> a;
            p[i] = make_tuple(x, y, a);
        }
        sort(all(p));

        deque<TPair> st;
        TLine last = TLine({0, 0}, {0, 1});

        ld ans = 0;
        for (int i = 0; i < n; ++i) {
            ld x, y, a;
            tie(x, y, a) = p[i];

            while (st.size() > 0 && st.front().p.y > y) {
                last = st.front().l;
                st.pop_front();
            }

            ld v = last(y);
            ld f = x * y - a + v;
            ans = max(ans, f);
            TLine l = TLine({f, 0}, {0, f / x});
            TPoint p;
            for (;;) {
                p = l.intersect(st.size()? st.back().l : last);
                if (st.size() && st.back().p.y < p.y) {
                    st.pop_back();
                } else {
                    break;
                }
            }
            // cout << f << " " << p.x << " " << p.y << " " << v << endl;
            // cout << l.p.x << " " << l.p.y << ", " << l.q.x << " " << l.q.y << endl;

            if (p.y > 0) {
                st.push_back({l, p});
            }

            // cout << x << " " << y << " " << a << endl;
            // cout << endl;
        }
        cout.precision(0);
        cout << fixed << ans << "\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}