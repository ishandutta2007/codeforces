#include <bits/stdc++.h>

#define db long double

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e3;
const db eps = 1e-8;

int n, A, B;
db a[N + 10], b[N + 10], c[N + 10];
struct Node { int x, y; db z; };

Node solve(db mid1, db mid2) {
    int tot1 = 0, tot2 = 0; double ans = 0;
    for (int i = 1; i <= n; i++) {
        bool f1 = 0, f2 = 0; db tmp = 0;
        if (a[i] - mid1 > tmp + eps) tmp = a[i] - mid1, f1 = 1, f2 = 0;
        if (b[i] - mid2 > tmp + eps) tmp = b[i] - mid2, f1 = 0, f2 = 1;
        if (c[i] - mid1 - mid2 > tmp + eps) tmp = c[i] - mid1 - mid2, f1 = f2 = 1;
        tot1 += f1, tot2 += f2, ans += tmp;
    }
    return {tot1, tot2, ans};
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, A, B);
    for (int i = 1; i <= n; i++) scanf("%Lf", a + i);
    for (int i = 1; i <= n; i++) scanf("%Lf", b + i), c[i] = 1 - (1 - a[i]) * (1 - b[i]);
    db l1 = 0, r1 = 1, mid1, l2, r2, mid2; Node ret;
    while (r1 - l1 > eps) {
        mid1 = (l1 + r1) / 2, l2 = 0, r2 = 1, mid2;
        while (r2 - l2 > eps) {
            mid2 = (l2 + r2) / 2, ret = solve(mid1, mid2);
            if (ret.y == B) break;
            if (ret.y >= B) l2 = mid2;
            else r2 = mid2;
        }
        if (ret.x == A) break;
        if (ret.x >= A) l1 = mid1;
        else r1 = mid1;
    }
    printf("%.6Lf\n", ret.z + mid1 * A + mid2 * B);
    return 0;
}