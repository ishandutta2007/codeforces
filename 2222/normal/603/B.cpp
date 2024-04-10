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

int mul(int x, int y, int p) { return (ll)x * y % p; }

int qpow(int x, int n, int p) {
    int y = 1;
    for (; n; n /= 2) {
        if (n & 1) y = mul(x, y, p);
        x = mul(x, x, p);
    }
    return y;
}

int main() {
    int p, k;
    cin >> p >> k;
    if (k == 0) {
        cout << qpow(p, p - 1, mod) << endl;
        return 0;
    }
    if (k == 1) {
        cout << qpow(p, p, mod) << endl;
        return 0;
    }
    int m = p - 1;
    for (int x = 2; x <= m; ++x)
        while (m % x == 0 && qpow(k, m / x, p) == 1)
            m /= x;
    cout << qpow(p, (p - 1) / m, mod) << endl;
    return 0;
}