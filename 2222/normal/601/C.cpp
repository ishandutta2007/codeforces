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
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        puts("1");
        return 0;
    }
    vector<int> x(n);
    REP (i, n) cin >> x[i];
    vector<long double> f(accumulate(all(x), 0), 0);
    f[0] = 1;
    REP (i, n) {
        REP (j, sz(f)) f[j] /= m - 1;
        vector<long double> g(sz(f));
        FOR (j, x[i], sz(g)) {
            g[j] = -f[j - x[i]];
        }
        FOR (j, 1, sz(g)) {
            f[j] += f[j - 1];
            g[j] += f[j - 1];
            if (j - m - 1 >= 0)
                g[j] -= f[j - m - 1];
        }
        f.swap(g);
    }
    long double p = accumulate(all(f), (long double)0);
    printf("%.12lf\n", (double)(p * (m - 1) + 1));
    return 0;
}