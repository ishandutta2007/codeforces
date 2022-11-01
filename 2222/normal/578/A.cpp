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
    ll a, b;
    cin >> a >> b;
    ll k = (a + b) / (2 * b);
    double x = 1e100;
    if (k > 0) x = double(a + b) / (2 * k);
    if (a > b) {
        k = (a - b) / (2 * b);
        if (k > 0) x = min(x, double(a - b) / (2 * k));
    }
    if (x < 1e100)
        printf("%.10lf\n", x);
    else
        puts("-1");
    return 0;
}