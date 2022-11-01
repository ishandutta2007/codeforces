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

struct point { int x, y; } a[100500];
int n;

ll det(int a, int b, int c, int d) { return (ll)a * d - (ll)b * c; }

int gcd(int x, int y) {
    for (; y; swap(x %= y, y));
    return x;
}

ll F[200500];

int lgcd;

ll f(int i, int j) {
    lgcd = abs(gcd(a[j].x - a[i].x, a[j].y - a[i].y));
    return det(a[i].x, a[i].y, a[j].x, a[j].y) - lgcd;
}

double pw2[1024];

double prob(int k, int n) {
    if (n - k >= 1024 || k > n)
        return 0;
    double e = k < 1024 ? 1 / pw2[k] : 0;
    return (1 - e) / (pw2[n - k] - e * (1 + n + n * (n - 1) / 2));
}

int main() {
    pw2[0] = 1;
    FOR (k, 1, 1024) pw2[k] = pw2[k - 1] * 2;
    scanf("%d", &n);
    REP (i, n) scanf("%d%d", &a[i].x, &a[i].y);
    a[n] = a[0];
    REP (j, 2 * n) {
        int i = j < n ? j : j - n;
        F[j + 1] = F[j] + f(i, i + 1);
    }
    assert(F[n] % 2 == 0);
    double res = F[n] / 2 + 1;
    int m = min(n - 1, 100);
    REP (i, n) {
        FOR (k, 1, m) {
            int j = i + k;
            ll s = F[j] - F[i] + f(j < n ? j : j - n, i);
            assert(s % 2 == 0);
            s = s / 2 + lgcd;
            double pr = prob(n - 1 - k, n);
            res -= s * pr;
        }
    }
    printf("%.12lf\n", res);
    return 0;
}