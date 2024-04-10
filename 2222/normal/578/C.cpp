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
int a[200222];

double solve(double x) {
    vector<double> f(n + 1);
    REP (i, n) {
        f[i + 1] = f[i] + a[i] - x;
    }
    return *max_element(all(f)) - *min_element(all(f));
}

int main() {
    scanf("%d", &n);
    REP (i, n) scanf("%d", a + i);
    double lo = -2002220000.0, hi = -lo;
    REP (kk, 200) {
        double l = (lo * 2 + hi) / 3;
        double h = (lo + hi * 2) / 3;
        if (solve(l) < solve(h))
            hi = h;
        else
            lo = l;
    }
    printf("%.9lf\n", solve((lo + hi) / 2));
    return 0;
}