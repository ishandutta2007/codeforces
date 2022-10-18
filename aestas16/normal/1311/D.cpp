    #include <bits/stdc++.h>
     
    using namespace std;
     
    template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
        for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
        for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
        a = f ? -a : a;
    }
    template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
    int fr() { int a; return fr(a), a; }
     
    const int N = 2e4;
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
        for (int _ = fr(); _--;) {
            int a = fr(), b = fr(), c = fr(), ans = 1e9, ansa, ansb, ansc;
            for (int i = 1; i <= N; i++)
                for (int j = i; j <= N; j += i)
                    for (int k = j; k <= N; k += j) {
                        int tmp = abs(i - a) + abs(j - b) + abs(k - c);
                        if (tmp < ans) ans = tmp, ansa = i, ansb = j, ansc = k;
                    }
            printf("%d\n%d %d %d\n", ans, ansa, ansb, ansc);
        }
        return 0;
    }