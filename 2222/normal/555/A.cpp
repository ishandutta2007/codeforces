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
    int n, k;
    scanf("%d%d", &n, &k);
    int res = 0;
    vector<int> b;
    REP (j, k) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);
        for (int &x : a) scanf("%d", &x);
        if (a[0] != 1) {
            res += sz(a) - 1;
        } else {
            b = a;
        }
    }
    int j = 0;
    for (; j < sz(b) && b[j] == j + 1; ++j);
    res += n - j + (sz(b) - j);
    cout << res << endl;
    return 0;
}