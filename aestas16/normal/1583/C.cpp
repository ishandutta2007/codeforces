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
     
    const int N = 1e6;
     
    int sum[N + 10];
    string str[N + 10];
    bool vis[N + 10];
     
    #define chk(i, j) (((i) >= 1) && ((j) >= 1) && str[(i)][(j)] == 'X')
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
        for (int _ = 1; _--;) {
        	int n = fr(), m = fr(), q;
        	for (int i = 1; i <= n; i++) cin >> str[i], str[i] = " " + str[i];
        	for (int j = 1; j <= m; j++) {
        		vis[j] = 1;
        		for (int i = 1; i <= n; i++) {
        			if (chk(i, j - 1) && chk(i - 1, j)) vis[j] = 0;
    			}
    			sum[j] = sum[j - 1] + (vis[j] ^ 1);
    		}
        	fr(q);
        	while (q--) {
        		int x = fr(), y = fr();
    			puts(sum[x] == sum[y] ? "YES" : "NO");
    		}
    	}
        return 0;
    }