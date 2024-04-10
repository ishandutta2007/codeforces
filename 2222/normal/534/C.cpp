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
    int n;
    long sum;
    for (; cin >> n >> sum; ) {
        vector<int> d(n);
        long s = 0;
        REP (i, n) {
            scanf("%d", &d[i]);
            s += d[i];
        }
        REP (i, n) {
            if (i)
                putchar(' ');
            s -= d[i];
            long d0 = max(sum - s, 1ll);
            long d1 = min(sum - n + 1, long(d[i]));
            printf("%d", int(d[i] - max(d1 - d0 + 1, 0ll)));
            s += d[i];
        }
        puts("");
    }
    return 0;
}