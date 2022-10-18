/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5, P = 1e9 + 7;

int n, a[N + 10], b[N + 10];

bool chk(int x) {
    int tmp1 = x * 100, tmp2 = 0, f = (n + x) >> 2;
    for (int i = f + 1; i <= n; i++) tmp1 += a[i];
    f = max(0, f - x);
    for (int i = f + 1; i <= n; i++) tmp2 += b[i];
    if (tmp1 >= tmp2) return 1;
    return 0;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        fr(n);
        for (int i = 1; i <= n; i++) fr(a[i]);
        for (int i = 1; i <= n; i++) fr(b[i]);
        sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
        int l = 0, r = 1e6, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (chk(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}