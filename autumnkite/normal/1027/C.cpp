#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
    int x = 0, f = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
    return f ? x : -x;
}
#define N 1000005
int T, n, a[N], cnt, b[N];
int main(){
	scanf("%d", &T);
	while (T--){
		n = read(), cnt = 0;
		for (register int i = 1; i <= n; ++i) a[i] = read();
		std :: sort(a + 1, a + 1 + n);
		int s = 1;
		for (register int i = 2; i <= n; ++i)
			if (a[i] != a[i - 1]){
				if (s >= 2) b[++cnt] = a[i - 1];
				if (s >= 4) b[++cnt] = a[i - 1];
				s = 1;
			}
			else ++s;
		if (s >= 2) b[++cnt] = a[n];
		if (s >= 4) b[++cnt] = a[n];
		// printf("%d\n", cnt);
		// for (register int i = 1; i <= cnt; ++i) printf("%d ", b[i]); putchar('\n');
		double Ans = 1e100;
		int Ansx, Ansy;
		for (register int x = 1; x <= cnt; ++x, b[x] == b[x - 1] ? ++x : 0){
			int l = 1, r = x - 1;
			while (l < r){
				int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
				double s1 = 4.0 * (b[x] + b[m1]) * (b[x] + b[m1]) / (b[x] * b[m1]); 
				double s2 = 4.0 * (b[x] + b[m2]) * (b[x] + b[m2]) / (b[x] * b[m2]); 
				if (s1 < s2) r = m2 - 1; else l = m1 + 1;
			}
			double s = 4.0 * (b[x] + b[l]) * (b[x] + b[l]) / (b[x] * b[l]);
			if (l == r && s < Ans) Ans = s, Ansx = b[x], Ansy = b[l];
			l = x + 1, r = cnt;
			while (l < r){
				int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
				double s1 = 4.0 * (b[x] + b[m1]) * (b[x] + b[m1]) / (b[x] * b[m1]); 
				double s2 = 4.0 * (b[x] + b[m2]) * (b[x] + b[m2]) / (b[x] * b[m2]); 
				if (s1 < s2) r = m2 - 1; else l = m1 + 1;
			}
			s = 4.0 * (b[x] + b[l]) * (b[x] + b[l]) / (b[x] * b[l]);
			if (l == r && s < Ans) Ans = s, Ansx = b[x], Ansy = b[l];
		}
		printf("%d %d %d %d\n", Ansx, Ansx, Ansy, Ansy);
	}
}