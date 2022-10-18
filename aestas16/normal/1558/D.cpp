// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef Aestas16
    #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 0
#endif

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e5, P = 998244353, S = 17;

int n, m, a[N + 10], fac[N + 10], ifac[N + 10], tmp[N + 10], x[N + 10], y[N + 10];
set<int> s;

void InitC() {
    fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= N; i++) ifac[i] = (P - P / i) * ifac[P % i] % P;
    for (int i = 2; i <= N; i++) fac[i] = fac[i - 1] * i % P, ifac[i] = ifac[i] * ifac[i - 1] % P;
}

int C(int x, int y) {
    if (y > x || x < 0 || y < 0) return 0;
    return fac[x] * ifac[y] % P * ifac[x - y] % P;
}

namespace BIT {
    int cval[N + 10];
    inline int lowbit(int x) { return x & -x; }
    void add(int pos, int val) {
        for (int i = pos; i <= N; i += lowbit(i)) cval[i] += val;
    }
    int query(int val) {
        int pos = 0;
        for (int i = S; ~i; i--)
            if ((pos + (1 << i)) <= N && cval[pos + (1 << i)] < val) pos += (1 << i), val -= cval[pos];
        return pos + 1;
    }
} // namespace BIT
using namespace BIT;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    InitC();
    for (int i = 1; i <= N / 2; i++) add(i, 1);
    for (int _ = fr(); _--;) {
        fr(n, m), s.clear();
        for (int i = 1; i <= m; i++) fr(x[i], y[i]);
        for (int i = m; i; i--) {
            int p = query(y[i]), q = query(y[i] + 1);
            tmp[i] = p, add(p, -1), s.insert(q);
        }
        for (int i = 1; i <= m; i++) add(tmp[i], 1);
        printf("%lld\n", C(n + n - 1 - s.size(), n));
    }
    return 0;
}