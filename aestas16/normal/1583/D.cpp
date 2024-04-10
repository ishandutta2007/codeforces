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
     
    struct OI {
        int RP, score;
    } CSPS2021, NOIP2021, FJOI2022;
     
    signed main() {
        CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
        int n = fr(), tmp = 1;
        for (int i = 2; i <= n; i++) {
        	printf("? ");
        	for (int j = 1; j < n; j++) printf("1 ");
        	printf("%d\n", i), fflush(stdout);
        	int ret = fr();
        	if (ret) tmp = i;
        }
        a[n] = n + 1 - tmp;
        for (int i = 1; i <= n; i++) {
        	if (i == a[n]) continue;
        	if (i < a[n]) {
        		printf("? ");
        		for (int j = 1; j < n; j++) printf("%d ", a[n] - i + 1);
        		puts("1"), fflush(stdout);
        		a[fr()] = i;
    		} else {
    			printf("? ");
        		for (int j = 1; j < n; j++) printf("%d ", 1);
        		printf("%d\n", i - a[n] + 1), fflush(stdout);
        		a[fr()] = i;
    		}
    	}
    	printf("! ");
    	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    	puts(""), fflush(stdout); 
        return 0;
    }