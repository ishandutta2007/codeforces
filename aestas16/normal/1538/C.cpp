/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 6e5;

int n, l, r, a[N + 10], b[N + 10];

namespace BIT {
    int c[N + 10];
    int lowbit(int x) { return x & (-x); }
    void update(int pos, int val) {
        for (int i = pos; i <= N; i += lowbit(i)) c[i] += val;
    }
    int qsum(int pos) {
        int ret = 0;
        for (int i = pos; i; i -= lowbit(i)) ret += c[i];
        return ret;
    }
} // namespace BIT
using namespace BIT;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int ans = 0;
        fr(n), fr(l), fr(r);
        for (int i = 1; i <= n; i++) fr(a[i]), b[i] = a[i], b[i + n] = r - a[i], b[i + n + n] = l - a[i], c[i] = c[i + n] = c[i + n + n] = 0;
        sort(b + 1, b + 1 + n * 3);
        int m = unique(b + 1, b + 1 + 3 * n) - b - 1;
        for (int i = n; i; i--) {
            int R = lower_bound(b + 1, b + 1 + m, r - a[i]) - b, L = lower_bound(b + 1, b + 1 + m, l - a[i]) - b;
            ans += qsum(R) - qsum(L - 1);
            // printf("L = %lld R = %lld a[i] = %lld ans = %lld\n", L, R, lower_bound(b + 1, b + 1 + m, a[i]) - b, ans);
            update(lower_bound(b + 1, b + 1 + m, a[i]) - b, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
l - ai <= aj <= r - ai
5 8
6 2 3 5 4
1 5 4 2 3
4 8 7 5 6

0 1 2 3 4 5 6 7
*/