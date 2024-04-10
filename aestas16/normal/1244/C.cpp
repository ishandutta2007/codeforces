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
     
    void print(int a, int b, int c) {
        if (a >= 0 && b >= 0 && c >= 0) printf("%lld %lld %lld\n", a, b, c), exit(0);
    }
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
        int n = fr(), p = fr(), w = fr(), d = fr();
        for (int i = 0; i < w; i++)
            if ((p - i * d) % w == 0) print((p - i * d) / w, i, n - i - (p - i * d) / w);
        puts("-1");
        return 0;
    }