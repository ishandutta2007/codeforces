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

const int mod = 1000000007;

inline int mul(int x, int y) { return (ll)x * y % mod; }
inline int add(int x, int y) { return (x += y) < mod ? x : x - mod; }

int F[2][4444];
int C[4444][4444];

int f(int n, bool good) {
    if (n == 0)
        return good;
    int &res = F[good][n];
    if (res < 0) {
        res = add(f(n - 1, good), f(n - 1, true));
        for (int k = 2; k <= n; ++k) {
            res = add(res, mul(f(n - k, good), C[n - 1][k - 1]));
        }
    }
    return res;
}

int main() {
    REP (m, 4444) {
        C[m][0] = 1;
        REP (k, m)
            C[m][k + 1] = add(C[m - 1][k], C[m - 1][k + 1]);
    }
    int n;
    cin >> n;
    CL(F, -1);
    cout << f(n, 0) << endl;
    return 0;
}