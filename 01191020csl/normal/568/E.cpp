#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(c!='-'&&!isdigit(c)) c=getchar();
	int neg=0;if(c=='-') neg=1,c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return neg?-num:num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int a[100005], x[100005], vis[100005];
int f[100005], g[100005], l[100005], p[100005];
int main() {
	int n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	a[++n] = 0x3f3f3f3f;
	int m = read();
	for (int i = 1; i <= m; i++) x[i] = read();
	sort(x + 1, x + m + 1);
	int len = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] != -1) {
			int q = lower_bound(f, f + len + 1, a[i]) - f;
			f[q] = a[i], g[q] = i;
			l[i] = q, p[i] = g[q-1];
			len = max(len, q);
		}
		else {
			int q = len + 1;
			for (int j = m; j >= 1; j--) {
				while (q && f[q-1] >= x[j]) --q;
				if (q == len + 1) len = q;
				f[q] = x[j], g[q] = i;
			}
		}
	int q = n, last = 0x3f3f3f3f, x0 = m;
	while (l[q] < len) q--;
	for (int i = 1; i < len; i++) {
		if (a[q] != -1) last = a[q], q = p[q];
		else {
			while (x[x0] >= last) --x0;
			a[q] = x[x0], vis[x0] = 1, last = a[q];
			bool flag = 0;
			int r = q - 1;
			while (r) {
				if (l[r] == len-i && a[r] < a[q]) {
					flag = 1, q = r;
					break;
				}
				--r;
			}
			if (flag) continue;
			while (a[q] != -1) --q;
		}
	}
	x0 = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == -1) {
			while (vis[x0]) ++x0;
			vis[x0] = 1, a[i] = x[x0];
		}
		write(a[i]), putchar(' ');
	}
	putchar('\n');
}