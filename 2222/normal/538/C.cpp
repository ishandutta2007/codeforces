#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
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
    scanf("%d%d", &n, &m);
    vector<pii> h(m);
    REP (i, m) {
        scanf("%d%d", &h[i].X, &h[i].Y);
    }
    int res = max(h[0].Y + h[0].X - 1, h.back().Y + n - h.back().X);
    FOR (i, 1, m) {
        int d = h[i].X - h[i - 1].X - abs(h[i].Y - h[i - 1].Y);
        if (d < 0) {
            puts("IMPOSSIBLE");
            return 0;
        }
        res = max(res, max(h[i - 1].Y, h[i].Y) + d / 2);
    }
    cout << res << endl;
    return 0;
}