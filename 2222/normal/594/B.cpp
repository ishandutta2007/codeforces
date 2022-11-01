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

int main() {
    const double pi2 = acos(-1.0) * 2;
    int n, r;
    double v;
    cin >> n >> r >> v;
    v /= r;
    for (; n --> 0; ) {
        int s, f;
        scanf("%d%d", &s, &f);
        double d = (double)(f - s) / r;
        double lo = d - 2, hi = d;
        for (int k = 0; k < 100; ++k) {
            double mid = (lo + hi) / 2;
            double l = mid;
            l -= (int)(l / pi2) * pi2;
            for (; l < 0; l += pi2);
            for (; l >= pi2; l -= pi2);
            l = std::min(l, pi2 - l);
            double w = cos(pi2 / 4 - l / 2) * 2;
            if (mid + w >= d)
                hi = mid;
            else
                lo = mid;
        }
        printf("%.9lf\n", (lo + hi) / (2 * v));
    }
    return 0;
}