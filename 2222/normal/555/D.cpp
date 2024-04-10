#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int n, m;
int cx[200500], sx[200500];
map<int, int> f;

int gor(int x, int r) {
    return upper_bound(sx, sx + n, x + r)[-1];
}

int gol(int x, int r) {
    return lower_bound(sx, sx + n, x - r)[0];
}

int main() {
    scanf("%d%d", &n, &m);
    REP (i, n) {
        scanf("%d", cx + i);
        sx[i] = cx[i];
        f[cx[i]] = i;
    }
    sort(sx, sx + n);
    REP (k, m) {
        int x, r;
        scanf("%d%d", &x, &r);
        x = cx[x - 1];
        int pxl = +1, pxr = -1;
        for (; ; ) {
            int xr = gor(x, r);
            assert(xr >= x);
            r -= xr - x;
            assert(r >= 0);
            int xl = gol(xr, r);
            assert(xl <= xr);
            r -= xr - xl;
            assert(r >= 0);
            if (x == xl && x == xr)
                break;
            x = xl;
            if (pxl == xl && pxr == xr) {
                r %= (xr - xl) * 2;
            }
            pxl = xl;
            pxr = xr;
        }
        printf("%d\n", f[x] + 1);
    }
    return 0;
}