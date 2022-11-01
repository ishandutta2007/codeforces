#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
struct problem {
	int a, t;
	long long mint, maxt;
}p[200001];
int n;
long long T;
bool operator<(const problem &a, const problem &b) {
	return 1ll * a.a * b.t > 1ll * a.t * b.a;
}
bool cmp(const problem &a, const problem &b) {
	return a.a > b.a;
}
bool check(double c) {
	double minb = 1e30, nowb = 1e30;
	for (int i = 1; i <= n; i++) {
		if (p[i].a*(1-c*p[i].mint/T) > minb) return 0;
		nowb = min(nowb, p[i].a*(1-c*p[i].maxt/T));
		if (i == n || p[i].a > p[i+1].a) {
			minb = min(minb, nowb);
			nowb = 1e30;
		}
	}
	return 1;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++) p[i].a = read();
	for (int i = 1; i <= n; i++) p[i].t = read();
	sort(p + 1, p + n + 1);
	long long sum = 0, tmp = 0;
	int last = 0;
	for (int i = 1; i <= n; i++) {
		tmp += p[i].t;
		p[i].mint = sum + p[i].t;
		if (i == n || 1ll*p[i].a*p[i+1].t>1ll*p[i+1].a*p[i].t) {
			sum = tmp; 
			while (last < i) p[++last].maxt = sum;
		}
	}
	T = sum;
	sort(p + 1, p + n + 1, cmp);
	double l = 0, r = 1;
	for (int i = 1; i <= 50; i++) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(11) << (l+r)/2 << endl;
}