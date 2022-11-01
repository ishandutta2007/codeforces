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

int f(int n, int m) {
    int a = 2 * n;
    int b = 6 * m;
    int c = min(a, b) / 6;
    if (c == 0)
        return max(a, b);
    return c * 6 + f(n - c * 2, m - c);
}

int main() {
    int n, m;
    cin >> n >> m;
    int res = f(n, m);
    FOR (k, 1, m + 1) {
        res = min(res, max(f(n, m - k), 6 * k - 3));
    }
    cout << res << endl;
    return 0;
}