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

int n;
int x[2222], y[2222];

int gcd(int x, int y) {
    for (; y; swap(x %= y, y));
    return x;
}

int det(int a, int b, int c, int d) { return a * d - b * c; }

ll C3(int n) { return n * ll(n - 1) * (n - 2) / 6; }

int main() {
    for (; cin >> n; ) {
        map<pii, vector<int>> f;
        REP (i, n)
            cin >> x[i] >> y[i];
        REP (i, n) REP (j, n) {
            int dx = x[j] - x[i], dy = y[j] - y[i];
            int g = gcd(dx, dy);
            if (g == 0) continue;
            dx /= g;
            dy /= g;
            if (dx < 0 || dx == 0 && dy < 0) {
                dx *= -1;
                dy *= -1;
            }
            f[pii(dx, dy)].pb(i);
        }
        ll res = C3(n);
        for (auto &p : f) {
            auto &v = p.Y;
            UN(v);
            int dx = p.X.X;
            int dy = p.X.Y;
            for (int &i : v)
                i = det(dx, dy, x[i], y[i]);
            sort(all(v));
            for (int i = 0, j = 0; i < sz(v); i = j) {
                for (; j < sz(v) && v[i] == v[j]; ++j);
                res -= C3(j - i);
            }
        }
        cout << res << endl;
    }
    return 0;
}