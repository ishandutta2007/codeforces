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
    for (int n; cin >> n; ) {
        vector<vector<int>> a(n);
        REP (i, n) {
            int x;
            scanf("%d", &x);
            assert(0 <= x && x < n);
            a[x].pb(i);
        }
        vector<int> res;
        int c = 0;
        for (; c >= 0; ) {
            if (c < n && sz(a[c])) {
                res.push_back(a[c].back());
                a[c].pop_back();
                ++c;
            } else {
                c -= 3;
            }
        }
        if (sz(res) != n) {
            puts("Impossible");
            continue;
        }
        puts("Possible");
        REP (i, n) {
            if (i) putchar(' ');
            printf("%d", res[i] + 1);
        }
        puts("");
    }
    return 0;
}