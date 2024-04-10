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
int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
int mul(int x, int y) { return (ll)x * y % mod; }

int qpow(int x, int n) {
    int y = 1;
    for (; n; n /= 2) {
        if (n & 1) y = mul(x, y);
        x = mul(x, x);
    }
    return y;
}

int h, w, n;
pii p[2222];
int F[2222];

int fact[200500], ifact[200500];

int g(int dx, int dy) {
    if (dx < 0 || dy < 0)
        return 0;
    return mul(fact[dx + dy], mul(ifact[dx], ifact[dy]));
}

int f(int i) {
    int &res = F[i];
    if (res < 0) {
        res = g(w - p[i].X, h - p[i].Y);
        for (int j = i + 1; j < n; ++j) {
            res = sub(res, mul(g(p[j].X - p[i].X, p[j].Y - p[i].Y), f(j)));
        }
    }
    return res;
}

int main() {
    fact[0] = ifact[0] = 1;
    FOR (k, 1, 200500) {
        fact[k] = mul(fact[k - 1], k);
        ifact[k] = qpow(fact[k], mod - 2);
        assert(mul(fact[k], ifact[k]) == 1);
    }
    cin >> w >> h >> n;
    p[0] = pii(1, 1);
    ++n;
    FOR (i, 1, n) {
        cin >> p[i].X >> p[i].Y;
        assert(p[i].X <= w);
        assert(p[i].Y <= h);
    }
    sort(p, p + n, [](const pii &l, const pii &r) { return l.X + l.Y < r.X + r.Y; });
    CL(F, -1);
    cout << f(0) << endl;
    return 0;
}