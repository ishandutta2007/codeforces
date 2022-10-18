// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e6;

int n, m, a[N + 10], arr[N + 10], lst[N + 10], ans[N + 10], sum[N + 10];

struct Query {
    int l, r, id;
    bool operator < (const Query &rhs) const { return r < rhs.r; }
} Q[N + 10];

namespace BIT {
    int cval[N + 10];
    int lowbit(int x) { return x & -x; }
    int qxsum(int pos) {
        int ret = 0;
        for (int i = pos; i; i -= lowbit(i)) ret ^= cval[i];
        return ret;
    }
    void update(int pos, int val) {
        val ^= qxsum(pos) ^ qxsum(pos - 1);
        for (int i = pos; i <= n; i += lowbit(i)) cval[i] ^= val;
    }
} // namespace BIT
using namespace BIT;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]), sum[i] = sum[i - 1] ^ a[i], update(i, a[i]), arr[i] = a[i];
    sort(arr + 1, arr + n + 1), arr[0] = unique(arr + 1, arr + n + 1) - arr - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(arr + 1, arr + arr[0] + 1, a[i]) - arr;
    fr(m);
    for (int i = 1; i <= m; i++) fr(Q[i].l, Q[i].r), Q[i].id = i;
    sort(Q + 1, Q + m + 1);
    for (int i = 1, u = 1; i <= n; i++) {
        if (lst[a[i]]) update(lst[a[i]], 0);
        lst[a[i]] = i;
        while (Q[u].r == i) {
            int l = Q[u].l, r = Q[u].r;
            ans[Q[u].id] = sum[r] ^ sum[l - 1] ^ qxsum(r) ^ qxsum(l - 1), u++;
        }
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}