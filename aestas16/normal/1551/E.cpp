// 392699

#include <bits/stdc++.h>

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e3;

int qwq[N + 10], a[N + 10], f[N + 10][N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), k = fr(), ans = 0x7f7f7f7f;
        for (int i = 1; i <= n; i++) fr(a[i]), qwq[i] = i - a[i];
        for (int i = 1; i <= n; i++) {
            int I = qwq[i];
            for (int j = 0; j <= n; j++) f[i][j] = f[i - 1][j];
            if (i >= a[i]) {
                for (int k = 0; k <= I; k++) f[i][I] = max(f[i][I], f[a[i] - 1][k] + 1);
                for (int k = i - 1; ~k; k--) {
                    int tmp = k - a[i] + 1;
                    if (tmp <= 0) break;
                    if (qwq[k] >= tmp)
                        if (qwq[k] <= I)
                            f[i][I] = max(f[i][I], f[k][qwq[k]] + 1);
                }
                if (f[i][I] < k) continue;
                ans = min(ans, I);
            }
        }
        printf("%d\n", ans == 0x7f7f7f7f ? -1 : ans);
    }
    return 0;
}