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

typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
	long c, h1, h2, w1, w2;
    cin >> c >> h1 >> h2 >> w1 >> w2;
    if (w1 > w2) {
        swap(w1, w2);
        swap(h1, h2);
    }
    assert(w1 <= w2);
    long res = 0;
    if (w2 > 10000) {
        for (long w = 0, h = 0; w <= c; w += w2, h += h2) {
            res = max(res, h + ((c - w) / w1) * h1);
        }
    } else {
        if (h1 * w2 > h2 * w1) {
            swap(w1, w2);
            swap(h1, h2);
        }
        long w = (c / w2) * w2, h = (c / w2) * h2;
        REP (i, 10000000) {
            res = max(res, h + ((c - w) / w1) * h1);
            w -= w2;
            h -= h2;
            if (w < 0)
                break;
        }
    }
    cout << res << endl;
	return 0;
}