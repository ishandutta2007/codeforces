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
        int res = 0;
        REP (i, n) { 
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            res += (x2 - x1 + 1) * (y2 - y1 + 1);
        }
        cout << res << endl;
    }
    return 0;
}