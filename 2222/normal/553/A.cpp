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

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
int mul(int x, int y) { return (ll)x * y % mod; }

int C[1111][1111];

int main() {
    REP (n, 1111) {
        C[n][0] = 1;
        REP (k, n)
            C[n][k + 1] = add(C[n - 1][k], C[n - 1][k + 1]);
    }
    int k;
    cin >> k;
    vector<int> a(k);
    for (int &x : a) cin >> x;
    int n = accumulate(all(a), 0);
    int res = 1;
    for (; n > 0; ) {
        --k;
        res = mul(res, C[n - 1][a[k] - 1]);
        n -= a[k];
    }
    cout << res << endl;
    return 0;
}