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
    int n;
    cin >> n;
    vector<int> h(n);
    REP (i, n)
        scanf("%d", &h[i]);
    vector<int> l(n, -1u/2), r(n, -1u/2);
    int d = 0;
    REP (i, n) {
        l[i] = min(d + 1, h[i]);
        d = l[i];
    }
    d = 0;
    for (int i = n; i --> 0; ) {
        r[i] = min(d + 1, h[i]);
        d = r[i];
    }
    int res = 0;
    REP (i, n) {
        res = max(res, min(l[i], r[i]));
    }
    cout << res << endl;
    return 0;
}