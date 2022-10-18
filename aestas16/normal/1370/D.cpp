    #include <bits/stdc++.h>
     
    using namespace std;
     
    template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
        for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
        for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
        a = f ? -a : a;
    }
    template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
    int fr() { int a; return fr(a), a; }
     
    const int N = 2e5;
     
    int n, k, a[N + 10];
     
    bool chk(int x) {
        int tot1 = 0, tot2 = 0;
        for (int i = 1; i <= n; i++) {
            if (tot1 % 2 == 0) tot1++;
            else if (a[i] <= x) tot1++;
        }
        for (int i = 1; i <= n; i++) {
            if (tot2 % 2 == 1) tot2++;
            else if (a[i] <= x) tot2++;
        }
        return max(tot1, tot2) >= k;
    }
     
    struct OI { int RP, score; } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
        fr(n, k);
        for (int i = 1; i <= n; i++) fr(a[i]);
        int l = 1, r = 1e9, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (chk(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", ans);
        return 0;
    }