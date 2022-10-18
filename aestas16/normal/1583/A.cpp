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
     
    const int N = 1e2;
     
    int a[N + 10];
     
    bool chk(int x) {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return 1;
        return 0;
    }
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
        for (int _ = fr(); _--;) {
            int n = fr(), sum = 0;
            for (int i = 1; i <= n; i++) fr(a[i]), sum += a[i];
            if (chk(sum)) {
                printf("%d\n", n);
                for (int i = 1; i <= n; i++) printf("%d ", i);
                puts("");
                continue;
            }
            for (int i = 1; i <= n; i++) {
                int x = sum - a[i];
                if (chk(x)) {
                    printf("%d\n", n - 1);
                    for (int j = 1; j <= n; j++)
                        if (j != i) printf("%d ", j);
                    puts("");
                    goto cat;
                }
            }
            cat:;
        }
        return 0;
    }