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
    for (int n; cin >> n; ) {
        ll res = 0;
        for (int x = 1000000000, k = 10; x > 0; x /= 10, --k) {
            res += max(n - x + 1, 0) * ll(k);
            n = min(n, x - 1);
        }
        cout << res << endl;
    }
    return 0;
}