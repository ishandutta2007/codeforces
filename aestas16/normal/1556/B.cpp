// 392699

#include <bits/stdc++.h>

using namespace std;

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

const int N = 1e5;

int n, a[N + 10], arr[N + 10];

set<int> s[2];

int chk(int f) {
    int ret = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == f) arr[++arr[0]] = i;
    for (int i = 1; i <= ((n + 1) >> 1); i++) ret += abs(i + i - arr[i] - 1);
    return ret;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    for (int _ = fr(); _--;) {
        n = fr();
        int tot = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), a[i] &= 1, tot += a[i];
        if (n & 1) {
            if (tot == (n >> 1)) printf("%d\n", chk(0));
            else if (tot == (n >> 1) + 1) printf("%d\n", chk(1));
            else puts("-1");
        } else {
            if (tot == (n >> 1)) printf("%d\n", min(chk(0), chk(1)));
            else puts("-1");
        }
    }
    return 0;
}