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

const int mod = 1e9 + 7;

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
int mul(int x, int y) { return (ll)x * y % mod; }

int n;
int a[202];

int F[202][202][1010];

int f(int i, int k, int m) {
    if (m < 0) return 0;
    if (i == n) return k == 0;
    int &res = F[i][k][m];
    if (res < 0) {
        int w = m - (k > 0 ? (a[i] - a[i - 1]) * k : 0);
        res = add(f(i + 1, k, w), f(i + 1, k + 1, w));
        if (k > 0) {
            res = add(res, mul(k, f(i + 1, k, w)));
            res = add(res, mul(k, f(i + 1, k - 1, w)));
        }
    }
    return res;
}

int main() {
    int m;
    cin >> n >> m;
    REP (i, n) cin >> a[i];
    sort(a, a + n);
    CL(F, -1);
    cout << f(0, 0, m) << endl;
    return 0;
}