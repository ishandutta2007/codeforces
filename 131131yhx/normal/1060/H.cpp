#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#define int long long

using namespace std;

int Cnt = 2, d, p, S[5001], C[15][15];

int add(int a, int b, int c) {
    printf("+ %lld %lld %lld\n", a, b, c);
    S[c] = (S[a] + S[b]) % p;
    fflush(stdout);
    return c;
}

int add(int a, int b) {
    printf("+ %lld %lld %lld\n", a, b, ++Cnt);
    S[Cnt] = (S[a] + S[b]) % p;
    fflush(stdout);
    return Cnt;
}

int pw(int a) {
    printf("^ %lld %lld\n", a, ++Cnt);
    S[Cnt] = 1;
    for(int i = 1; i <= d; i++) S[Cnt] = (long long) S[Cnt] * S[a] % p;
    fflush(stdout);
    return Cnt;
}

int _2(int a) {
    printf("+ %lld %lld %lld\n", a, a, a);
    S[a] = S[a] * 2 % p;
    fflush(stdout);
    return Cnt;
}

int _0 = 5000;

int mulx(int a, int x) {
    x = (x % p + p) % p;
    if(!x) return add(_0, _0, ++Cnt);
    int t = 30;
    while(!(x >> t)) t--;
    for(int i = t; i >= 0; i--) {
        _2(_0);
        if(x & (1 << i)) add(a, _0, _0);
    }
    add(_0, _0 - 1, ++Cnt);
    assert(S[Cnt] == (long long) S[a] * x % p);
    _0--;
    return Cnt;
}

int getx(int x) {
    x = (x % p + p) % p;
    int ans = mulx(4498, x);
    assert(S[ans] == x);
    add(4497, _0, 4498);
    return ans;
}

long long powmod(long long x, long long y) {
    long long ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

int pw2(int a) {
    int nw = ++Cnt;
    add(getx(0), getx(0), nw);
    int _0 = 0, __1 = 0, _1 = 0;
    for(int i = d - 2, s = 1; i >= 0; i--, s = -s) {
        add(mulx(pw(add(a, getx(i))), s * C[d - 2][i]), nw, nw);
        _0 = (_0 + powmod(0 + i, d) * s * C[d - 2][i]) % p;
        _1 = (_1 + powmod(1 + i, d) * s * C[d - 2][i]) % p;
        __1 = (__1 + powmod(-1 + i, d) * s * C[d - 2][i]) % p;
    }
    long long X0 = _0, X1 = (_1 - __1) * (p + 1) / 2 % p, X2 = _1 - X1 - X0;
    add(nw, getx(-X0), nw);
    add(nw, mulx(a, -X1), nw);
    return mulx(nw, powmod(X2, p - 2));
}

signed main() {
    scanf("%lld%lld", &d, &p);
    for(int i = 1; i <= 5000; i++) S[i] = 1;
    S[1] = 3, S[2] = 4;
    for(int i = 0; i < 12; i++)
        for(int j = 0; j <= i; j++)
            C[i][j] = !j ? 1 : C[i - 1][j - 1] + C[i - 1][j];
    int t = 30;
    while(!(p >> t)) t--;
    for(int i = t - 1; i >= 0; i--) {
        _2(5000);
        if(p & (1 << i)) add(5000, 4999, 5000);
    }
    for(int i = 5000; i >= 4500; i--) add(i, i, i - 1);
    add(4499, pw2(add(1, 2)), 4499);
    add(4499, mulx(pw2(1), -1), 4499);
    add(4499, mulx(pw2(2), -1), 4499);
    mulx(4499, (p + 1) / 2);
    //fprintf(stdout, "%lld\n", S[Cnt]);
    printf("f %lld\n", Cnt);
    return 0;
}