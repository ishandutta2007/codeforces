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
     
    const int N = 1e3;
     
    int n, k, a[N + 10];
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
        fr(n, k);
        int tmpn = n - 1, tmp = 0;
        while (tmpn) tmpn /= k, tmp++;
        printf("%d\n", tmp);
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++) {
            	int a = i - 1, b = j - 1;
    			int ans = 0;
            	while (a != b) a /= k, b /= k, ans++;
            	printf("%d ", ans);
    		}
        return 0;
    }