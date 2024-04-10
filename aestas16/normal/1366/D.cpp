    #include <bits/stdc++.h>
     
    using namespace std;
     
    template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
        for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
        for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
        a = f ? -a : a;
    }
    template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
    int fr() { int a; return fr(a), a; }
     
    const int N = 5e5, A = 1e7;
     
    int n, a[N + 10], tot[N + 10], ans[N + 10];
    int ptot, pnum[A + 10];
    bool isnp[A + 10];
     
    void InitP() {
        isnp[1] = 1;
        for (int i = 2; i <= A; i++) {
            if (isnp[i] == 0) pnum[++ptot] = i;
            for (int j = 1; j <= ptot && i * pnum[j] <= A; j++) {
                isnp[i * pnum[j]] = 1;
                if (i % pnum[j] == 0) break;
            }
        }
    }
     
    struct OI { int RP, score; } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
        InitP(), fr(n);
        for (int i = 1; i <= n; i++) fr(a[i]), ans[i] = 1;
        for (int i = 1; i <= n; i++) {
            if (isnp[a[i]]) {
                for (int j = 1; j <= ptot && pnum[j] <= a[i]; j++)
                    if (a[i] % pnum[j] == 0) {
                        while (a[i] % pnum[j] == 0) a[i] /= pnum[j], ans[i] *= pnum[j];
                        break;
                    }
            } else ans[i] = a[i] = -1;
            if (a[i] == 1) ans[i] = a[i] = -1;
        }
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
        return 0;
    }