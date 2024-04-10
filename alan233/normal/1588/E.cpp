// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 3005;
const double PI = acos(-1.);

#define double long double

#define pdd pair<double, double>

vector<pdd> range[N];

int n, rr;
int x[N], y[N];

ll sqr(ll x) { return x * x; }

bool chk(double x, double y) {
    return x < y || fabs(x - y) < 1e-6;
} 

int main() {
    scanf("%d%d", &n, &rr);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        range[i].pb({0, 2 * PI});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll dist = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
            if (dist <= 1ll * rr * rr) continue;
            double aa = sqrt(dist);
            double ang = asin(rr / 1. / aa); // atan2(y, x)
            assert(ang >= 0.);
            double t = atan2(y[j] - y[i], x[j] - x[i]);
            double l = t - ang, r = t + ang;
            while (l < 0) l += 2 * PI;
            while (l > 2 * PI) l -= 2 * PI;
            while (r < 0) r += 2 * PI;
            while (r > 2 * PI) r -= 2 * PI;
            // printf("%d need (%.3f %.3f)  (by %d)\n", i, l, r, j);
            if (chk(l, r)) {
                vector<pdd> new_range;
                for (auto seg: range[i]) {
                    if (chk(seg.fir, seg.sec)) {
                        ckmax(seg.fir, l);
                        ckmin(seg.sec, r);
                        if (chk(seg.fir, seg.sec)) new_range.pb(seg); 
                    } else {
                        pdd seg1 = {seg.fir, 2 * PI};
                        pdd seg2 = {0, seg.sec};
                        ckmax(seg1.fir, l);
                        ckmin(seg1.sec, r);
                        ckmax(seg2.fir, l);
                        ckmin(seg2.sec, r);
                        if (chk(seg1.fir, seg1.sec)) new_range.pb(seg1);
                        if (chk(seg2.fir, seg2.sec)) new_range.pb(seg2);
                    }
                }
                range[i] = new_range;
            } else {
                vector<pdd> new_range;
                for (auto seg: range[i]) {
                    if (chk(seg.fir, seg.sec)) {
                        pdd seg1 = {l, 2 * PI};
                        pdd seg2 = {0, r};
                        ckmax(seg1.fir, seg.fir);
                        ckmin(seg1.sec, seg.sec);
                        ckmax(seg2.fir, seg.fir);
                        ckmin(seg2.sec, seg.sec);
                        if (chk(seg1.fir, seg1.sec)) new_range.pb(seg1);
                        if (chk(seg2.fir, seg2.sec)) new_range.pb(seg2);
                    } else {
                        pdd seg1 = {seg.fir, seg.sec + 2 * PI};
                        pdd seg2 = {l, r + 2 * PI};
                        ckmax(seg1.fir, seg2.fir);
                        ckmin(seg1.sec, seg2.sec);
                        if (chk(seg1.fir, seg1.sec)) {
                            new_range.pb({seg1.fir, seg1.sec - 2 * PI});
                        }
                    }
                }
                range[i] = new_range;
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        printf("for node %d\n", i);
        for (auto seg: range[i])
            printf("(%.5f %.5f)\n", seg.fir, seg.sec);
        puts("-----");
    }
    */
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bool ok = 0;
            double where = atan2(y[j] - y[i], x[j] - x[i]);
            while (where < 0) where += 2 * PI;
            for (auto seg: range[i]) {
                if (chk(seg.fir, seg.sec)) {
                    ok |= chk(seg.fir, where) && chk(where, seg.sec);
                } else {
                    ok |= chk(seg.fir, where) || chk(where, seg.sec);
                }
            }
            if (!ok) continue;
            ok = 0;
            where = atan2(y[i] - y[j], x[i] - x[j]);
            while (where < 0) where += 2 * PI;
            for (auto seg: range[j]) {
                if (chk(seg.fir, seg.sec)) {
                    ok |= chk(seg.fir, where) && chk(where, seg.sec);
                } else {
                    ok |= chk(seg.fir, where) || chk(where, seg.sec);
                }
            }
            if (!ok) continue;
            ans++;
            // fprintf(stderr, "[debug] %d %d ok!\n", i, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}