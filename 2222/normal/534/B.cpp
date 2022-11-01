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
    for (int v1, v2, t, d; cin >> v1 >> v2 >> t >> d; ) {
        if (v1 > v2)
            swap(v1, v2);
        long res = 0;
        for (; t --> 0; ) {
            v1 = min(v1, v2 + t * d);
            res += v1;
            v1 += d;
        }
        cout << res << endl;
    }
    return 0;
}