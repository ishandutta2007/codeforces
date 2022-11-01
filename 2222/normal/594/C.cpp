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
ll x[100500], y[100500];

ll area(ll x0, ll y0, ll x1, ll y1) {
    ll w = max(1ll, (x1 - x0 + 1) / 2);
    ll h = max(1ll, (y1 - y0 + 1) / 2);
    return w * h;
}

int tim[100500], now;

int mark(int i) {
    if (tim[i] == now) return 0;
    tim[i] = now;
    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    vector<pair<ll, int>> ox, oy;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x[i] = (ll)x1 + x2;
        y[i] = (ll)y1 + y2;
        //cout << x[i] << ' ' << y[i] << endl;
        ox.emplace_back(x[i], i);
        oy.emplace_back(y[i], i);
    }
    sort(all(ox));
    sort(all(oy));
    ll res = area(ox.front().X, oy.front().X, ox.back().X, oy.back().X);
    REP (kl, m + 1)
        REP (kr, m + 1 - kl)
            REP (ku, m + 1)
                REP (kd, m + 1 - ku) {
                    ++now;
                    int cnt = 0;
                    REP (i, kl) cnt += mark(ox[i].Y);
                    REP (i, kr) cnt += mark(ox[n - 1 - i].Y);
                    REP (i, ku) cnt += mark(oy[i].Y);
                    REP (i, kd) cnt += mark(oy[n - 1 - i].Y);
                    if (cnt <= m) {
                        res = min(res, area(ox[kl].X, oy[ku].X, ox[n - 1 - kr].X, oy[n - 1 - kd].X));
                    }
                }
    cout << res << endl;
    return 0;
}