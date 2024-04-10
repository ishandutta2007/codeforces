#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long uint64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int mod;

int mul(int x, int y) { return (long)x * y % mod; }

int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }

int pow(int x, long n) {
    int y = 1 % mod;
    for (; n; n /= 2) {
        if (n & 1) y = mul(x, y);
        x = mul(x, x);
    }
    return y;
}

struct mat {
    int a[2][2];
    mat(int b, int c, int d, int e) {
        a[0][0] = b;
        a[0][1] = c;
        a[1][0] = d;
        a[1][1] = e;
    }
};

mat operator * (const mat &a, const mat &b) {
    mat c(0, 0, 0, 0);
    REP (i, 2) REP (j, 2)
        c.a[i][j] = add(mul(a.a[i][0], b.a[0][j]), mul(a.a[i][1], b.a[1][j]));
    return c;
}

mat pow(mat x, long n) {
    mat y(1 % mod, 0, 0, 1 % mod);
    for (; n; n /= 2) {
        if (n & 1) y = x * y;
        x = x * x;
    }
    return y;
}

int solve0(long n) {
    mat a = pow(mat(0, 1 % mod, 1 % mod, 1 % mod), n);
    return add(a.a[0][1], a.a[1][1]);
}

int solve1(long n) {
    return sub(pow(2, n), solve0(n));
}

int main() {
    long n, k;
    int l;
    cin >> n >> k >> l >> mod;
    if (l < 64 && (k >> l)) {
        puts("0");
        return 0;
    }
    int res = 1 % mod;
    REP (i, l) {
        if ((k >> i) & 1) {
            res = mul(res, solve1(n));
        } else {
            res = mul(res, solve0(n));
        }
    }
    cout << res << endl;
    return 0;
}