#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
struct Complex {
	double a, b;
	Complex(double x=0, double y=0):a(x),b(y){}
};
Complex operator+(Complex a, Complex b) {
	return Complex(a.a+b.a, a.b+b.b);
};
Complex operator-(Complex a, Complex b) {
	return Complex(a.a-b.a, a.b-b.b);
}
Complex operator*(Complex a, Complex b) {
	return Complex(a.a*b.a-a.b*b.b, a.a*b.b+a.b*b.a);
}
Complex operator/(Complex a, double b) {
	return Complex(a.a/b, a.b/b);
}
const double pi = acos(-1);
int r[1<<16];
void FFT(vector<Complex> &a, int len, int op) {
	for (int i = 0; i < len; i++)
		if (i < r[i]) swap(a[i], a[r[i]]);
	for (int L = 2; L <= len; L <<= 1) {
		Complex g(cos(2*op*pi/L), sin(2*op*pi/L));
		int p = L >> 1;
		for (int i = 0; i < len; i += L) {
			Complex num = 1;
			for (int j = i; j < i + p; j++) {
				Complex tmp = num * a[j+p];
				a[j+p] = a[j] - tmp;
				a[j] = a[j] + tmp;
				num = num * g;
			}
		}
	}
	if (op == -1)
		for (int i = 0; i < len; i++) a[i] = a[i] / len;
}
double f[51][20001], g[101][20001], p[101][20001];
int n, m, u[101], v[101], c[101];
void solve(int l0, int r0) {
	if (l0 == r0) {
		for (int i = 1; i <= n; i++) f[i][l0] = 1e100;
		for (int i = 1; i <= m; i++)
			f[u[i]][l0] = min(f[u[i]][l0], g[i][l0]);
		f[n][l0] = 0;
		return;
	}
	int mid = (l0 + r0) / 2;
	solve(mid + 1, r0);
	int len = 1;
	for (; len < r0-mid+r0-l0; len <<= 1);
	for (int i = 1; i < len; i++) r[i] = (r[i>>1]>>1)|(i&1?len>>1:0);
	for (int i = 1; i <= m; i++) {
		vector<Complex> a, b;
		for (int j = mid + 1; j <= r0; j++) 
			a.push_back(f[v[i]][j]);
		for (int j = r0-l0; j >= 1; j--) b.push_back(p[i][j]);
		a.resize(len), b.resize(len);
		FFT(a, len, 1), FFT(b, len, 1);
		for (int j = 0; j < len; j++) a[j] = a[j]*b[j];
		FFT(a, len, -1);
		for (int j = mid; j >= l0; j--) g[i][j] = g[i][j] + a[j-mid+r0-l0-1].a;
	}
	solve(l0, mid);
}
int dis[51], vis[51];
int main() {
	int t, x;
	n = read(), m = read(), t = read(), x = read();
	for (int i = 1; i <= m; i++) {
		u[i] = read(), v[i] = read(), c[i] = read();
		for (int j = 1; j <= t; j++) p[i][j] = read()/1e5;
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[n] = 0;
	while (!vis[1]) {
		int w, maxn = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && dis[i] < maxn) maxn = dis[i], w = i;
		vis[w] = 1;
		for (int i = 1; i <= m; i++)
			if (v[i] == w && dis[u[i]] > dis[w] + c[i])
				dis[u[i]] = dis[w] + c[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1, pt = t; j <= t; j++, pt--) g[i][j] = g[i][j-1] + p[i][pt];
		for (int j = 0; j <= t; j++) g[i][j] = g[i][j]*(dis[v[i]]+x)+c[i];
	}
	solve(0, t);
	cout << fixed << setprecision(10) << f[1][0] << endl;
}