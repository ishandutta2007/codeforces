#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 5e5, INF = 1e18;

int n, m, q, sum, a[N + 10], b[N + 10], B[N + 10], arr[N + 10];

int query() {
    auto p = lower_bound(arr + 1, arr + m - n + 1 + 1, sum);
    int x = *p, y = *(p - 1);
    if (p == arr + m - n + 1 + 1) return sum - y;
    if (p == arr + 1) return x - sum;
    return min(x - sum, sum - y);
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n, m, q), arr[0] = arr[n + 2] = INF;
    for (int i = 1; i <= n; i++) {
        fr(a[i]);
        if ((i & 1) == 0) a[i] = -a[i];
        sum += a[i];
    }
    for (int i = 1; i <= m; i++) {
        fr(b[i]), B[i] = b[i];
        if (i & 1) B[i] = -B[i];
        else b[i] = -b[i];
        B[i] += B[i - 1], b[i] += b[i - 1];
    }
    for (int i = 1; i <= m - n + 1; i++)
        if (i & 1) arr[i] = b[i + n - 1] - b[i - 1];
        else arr[i] = B[i + n - 1] - B[i - 1];
    sort(arr + 1, arr + m - n + 1 + 1), printf("%lld\n", query());
    for (int i = 1, l, r, val; i <= q; i++) {
        fr(l, r, val);
        int f = ((l & 1) + (r & 1));
        if (f == 2) sum += val;
        else if (f == 0) sum -= val;
        printf("%lld\n", query());
    }
    return 0;
}