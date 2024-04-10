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
     
    const int N = 1e5;
     
    bool vis[N + 10];
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
        for (int _ = fr(); _--;) {
        	int n = fr(), m = fr();
    		for (int i = 1; i <= n; i++) vis[i] = 0;
    		for (int i = 1; i <= m; i++) {
    			int a = fr(), b = fr(), c = fr();
    			vis[b] = 1;
    		} 
    		for (int i = 1; i <= n; i++)	
    			if (vis[i] == 0) {
    				for (int j = 1; j <= n; j++)
    					if (i != j) printf("%d %d\n", i, j);
    				break;
    			}
    	}
        return 0;
    }