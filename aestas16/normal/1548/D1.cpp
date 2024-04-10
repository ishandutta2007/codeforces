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
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int sta[][3] = {{1, 1, 2}, {1, 1, 3}, {1, 2, 2}, {1, 3, 3}, {2, 2, 2}, {2, 2, 3}, {2, 3, 3}, {3, 3, 3},
                     {0, 0, 0}, {0, 0, 1}, {0, 0, 2}, {0, 0, 3}, {0, 1, 1}, {0, 2, 2}, {0, 3, 3}, {1, 1, 1}};

int cnt[50];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    int n = fr(), ans = 0;
    for (int i = 1, x, y; i <= n; i++) fr(x, y), x >>= 1, y >>= 1, cnt[((x & 1) << 1) + (y & 1)]++;
    for (int i = 0; i < 16; i++)
        if (sta[i][0] == sta[i][1] && sta[i][0] == sta[i][2]) ans += (cnt[sta[i][2]] - 2) * (cnt[sta[i][2]] - 1) * cnt[sta[i][2]] / 6;
        else if (sta[i][0] == sta[i][1]) ans += (cnt[sta[i][1]] - 1) * cnt[sta[i][1]] / 2 * cnt[sta[i][2]];
        else if (sta[i][1] == sta[i][2]) ans += (cnt[sta[i][2]] - 1) * cnt[sta[i][2]] / 2 * cnt[sta[i][0]];
    return printf("%lld\n", ans), 0;
}