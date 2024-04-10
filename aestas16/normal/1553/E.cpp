// 392699

#include <bits/stdc++.h>

using namespace std;

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

const int N = 3e5;

int a[N + 10], cnt[N + 10], ans[N + 10];
bool vis[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr();
        ans[0] = 0;
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), cnt[(a[i] - i + n - 1) % n + 1]++;
        for (int i = n; i; i--)
            if ((n - m) / 2 <= cnt[i]) {
                int tot = n;
                for (int j = 1; j <= n; j++) vis[j] = 0;
                for (int j = 1; j <= n; j++)
                    if (vis[j] == 0) {
                        bool flag = 0;
                        for (int k = j;; k = (a[k] - i + n - 1) % n + 1) {
                            vis[k] = 1;
                            if (k == j && flag) break;
                            flag = 1;
                        }
                        tot--;
                    }
                if (tot <= m) ans[++ans[0]] = n - i;
            }
        for (int i = 0; i <= ans[0]; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}