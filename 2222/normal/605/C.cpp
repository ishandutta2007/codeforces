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

double det(double a, double b, double c, double d) { return a * d - b * c; }

int main() {
    ios::sync_with_stdio(false);
    int n;
    double p, q;
    cin >> n >> p >> q;
    vector<double> a(n + 2), b(n + 2);
    double res = 1e111;
    REP (i, n) {
        cin >> a[i + 2] >> b[i + 2];
    }
    a[0] = *max_element(2 + all(a));
    b[1] = *max_element(2 + all(b));
    n += 2;
    int u = 0, v = 1;
    auto solve = [&](int i, int j) {
        double d = det(a[i], a[j], b[i], b[j]);
        if (fabs(d) < 1e-12)
            return 1e111;
        double x = -det(a[j], p, b[j], q) / d;
        double y = det(a[i], p, b[i], q) / d;
        return max(x, 0.) + max(y, 0.);
    };
    for (; ; ) {
        double c = solve(u, v);
        int i = -1, j = -1;
        REP (k, n) {
            if (k == u || k == v) continue;
            double d = solve(k, v);
            if (d < c)
                tie(c, i, j) = tie(d, k, v);
            d = solve(k, u);
            if (d < c)
                tie(c, i, j) = tie(d, k, u);
        }
        res = min(res, c);
        if (i < 0) break;
        u = i;
        v = j;
    }
    printf("%.8lf\n", res);
    return 0;
}