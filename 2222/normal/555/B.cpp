#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <set>
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
ll l[200500], r[200500];
pair<ll, int> a[200500];
pair<pii, int> b[200500];
int ans[200500];

int main() {
    scanf("%d%d", &n, &m);
    REP (i, n) scanf("%I64d%I64d", l + i, r + i);
    set<int> f;
    REP (i, m) {
        scanf("%I64d", &a[i].X);
        a[i].Y = i;
        f.insert(i);
    }
    sort(a, a + m);
    REP (i, n - 1) {
        int lo = lower_bound(a, a + m, make_pair(l[i + 1] - r[i], -1)) - a;
        int hi = lower_bound(a, a + m, make_pair(r[i + 1] - l[i], m)) - a - 1;
        b[i] = make_pair(pii(lo, hi), i);
    }
    sort(b, b + n - 1);
    for (int i = n - 2; i >= 0; --i) {
        auto j = f.upper_bound(b[i].X.Y);
        if (j != f.begin()) --j;
        if (sz(f) == 0 || *j < b[i].X.X || *j > b[i].X.Y) {
            puts("No");
            return 0;
        }
        ans[b[i].Y] = a[*j].Y;
        f.erase(j);
    }
    puts("Yes");
    REP (i, n - 1) {
        if (i) putchar(' ');
        printf("%d", ans[i] + 1);
    }
    puts("");
    return 0;
}