#include<bits/stdc++.h>
using namespace std;
long long read() {
	char c=getchar();while(c!='-'&&!isdigit(c)) c=getchar();
	int neg=0;if(c=='-') neg=1,c=getchar();
	long long num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return neg?-num:num;
}
struct fix {
	long long t, x, y;
}f[200001];
int l;
bool operator<(const fix &a, const fix &b) {
	return a.t % l < b.t % l;
}
int ans1[2000001], ans2[2000001];
long long s1l, s1r, s2l, s2r;
int main() {
	int n = read();
	l = read();
	for (int i = 1; i <= n; i++) f[i].t = read(), f[i].x = read(), f[i].y = read();
	sort(f + 1, f + n + 1);
	for (int i = 1; i <= n; i++) {
		long long x0 = (f[i].x + f[i].y + f[i].t), y0 = (f[i].x - f[i].y + f[i].t);
		if ((x0 & 1) || (y0 & 1)) {
			puts("NO");
			return 0;
		}
		f[i].x = x0 / 2, f[i].y = y0 / 2;
	}
	s1l = s2l = 0, s1r = s2r = l;
	for (int i = 1; i <= n; i++) {
		long long pa = f[i-1].t / l, pb = f[i].t / l;
		int qa = f[i-1].t%l, qb = f[i].t%l;
		if (pa == pb)
			if (!(f[i].x>=f[i-1].x&&f[i].x-f[i-1].x<=qb-qa&&f[i].y>=f[i-1].y&&f[i].y-f[i-1].y<=qb-qa)) {
				puts("NO");
				return 0;
			}
		if (pb > pa) {
			if (f[i].x < f[i-1].x || f[i].y < f[i-1].y) {
				puts("NO");
				return 0;
			}
			if (f[i].x-f[i-1].x>qb-qa) s1l=max(s1l, (f[i].x-f[i-1].x-(qb-qa)-1)/(pb-pa)+1);
			s1r = min(s1r, (f[i].x-f[i-1].x)/(pb-pa));
			if (f[i].y-f[i-1].y>qb-qa) s2l=max(s2l, (f[i].y-f[i-1].y-(qb-qa)-1)/(pb-pa)+1);
			s2r = min(s2r, (f[i].y-f[i-1].y)/(pb-pa));
		}
		if (pb < pa) {
			if (qb-qa<f[i].x-f[i-1].x || qb-qa<f[i].y-f[i-1].y) {
				puts("NO");
				return 0;
			}
			if (f[i-1].x > f[i].x) s1l = max(s1l, (f[i-1].x-f[i].x-1)/(pa-pb)+1);
			s1r = min(s1r, (qb-qa+f[i-1].x-f[i].x)/(pa-pb));
			if (f[i-1].y > f[i].y) s2l = max(s2l, (f[i-1].y-f[i].y-1)/(pa-pb)+1);
			s2r = min(s2r, (qb-qa+f[i-1].y-f[i].y)/(pa-pb));
		}
	}
	if (l-f[n].t%l+f[n].x < 0) {
		puts("NO");
		return 0;
	}
	s1l = max(s1l, (f[n].x+f[n].t/l)/(f[n].t/l+1));
	s1r = min(s1r, (l-f[n].t%l+f[n].x)/(f[n].t/l+1));
	if (l-f[n].t%l+f[n].y < 0) {
		puts("NO");
		return 0;
	}
	s2l = max((long long)s2l, (f[n].y+f[n].t/l)/(f[n].t/l+1));
	s2r = min((long long)s2r, (l-f[n].t%l+f[n].y)/(f[n].t/l+1));
	if (s1l > s1r || s2l > s2r) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= l; i++) ans1[i] = ans2[i] = -1;
	int s1 = s1l, s2 = s2l;
	for (int i = 1; i <= n; i++)
		if (f[i].t % l > f[i-1].t % l) {
			int dx = (f[i].x-f[i-1].x)-(f[i].t/l-f[i-1].t/l)*s1;
			for (int j = f[i-1].t%l + 1; j <= f[i-1].t%l+dx; j++) ans1[j] = 1;
			int dy = (f[i].y-f[i-1].y)-(f[i].t/l-f[i-1].t/l)*s2;
			for (int j = f[i-1].t%l + 1; j <= f[i-1].t%l+dy; j++) ans2[j] = 1;
		}
	int dx = s1-(f[n].x-f[n].t/l*s1), dy = s2-(f[n].y-f[n].t/l*s2);
	for (int i = f[n].t%l+1; i <= f[n].t%l+dx; i++) ans1[i] = 1;
	for (int i = f[n].t%l+1; i <= f[n].t%l+dy; i++) ans2[i] = 1;
	for (int i = 1; i <= l; i++)
		if (ans1[i] == 1 && ans2[i] == 1) putchar('R');
		else if (ans1[i] == 1) putchar('U');
		else if (ans2[i] == 1) putchar('D');
		else putchar('L');
    putchar('\n');
}