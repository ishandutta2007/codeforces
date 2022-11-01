#include<bits/stdc++.h>
using namespace std;
long long read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	long long num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int mod;
int s[50001];
struct matrix {
	int a[2][2];
	matrix(int x=1,int y=0,int z=0,int t=1):a{x,y,z,t}{}
};
matrix operator*(matrix a, matrix b) {
	matrix ans;
	ans.a[0][0] = (1ll*a.a[0][0]*b.a[0][0]+1ll*a.a[0][1]*b.a[1][0])%mod;
	ans.a[0][1] = (1ll*a.a[0][0]*b.a[0][1]+1ll*a.a[0][1]*b.a[1][1])%mod;
	ans.a[1][0] = (1ll*a.a[1][0]*b.a[0][0]+1ll*a.a[1][1]*b.a[1][0])%mod;
	ans.a[1][1] = (1ll*a.a[1][0]*b.a[0][1]+1ll*a.a[1][1]*b.a[1][1])%mod;
	return ans;
}
matrix power(matrix a, long long n) {
	matrix ans;
	while (n) {
		if (n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}
matrix m[200001];
void build(int p, int l, int r) {
	if (l == r) {
		m[p].a[0][0] = s[l+1], m[p].a[0][1] = s[l];
		m[p].a[1][0] = 1, m[p].a[1][1] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2, l, mid), build(p * 2 + 1, mid + 1, r);
	m[p] = m[p*2+1] * m[p*2];
}
void modify(int p, int l, int r, int x, matrix mat) {
	if (l == r) {
		m[p] = mat;
		return;
	}
	int mid = (l + r) / 2;
	if (x <= mid) modify(p * 2, l, mid, x, mat);
	else modify(p * 2 + 1, mid + 1, r, x, mat);
	m[p] = m[p*2+1] * m[p*2];
}
struct change {
	long long j;
	int v;
}c[50001];
bool operator<(const change &a, const change &b) {
	return a.j < b.j;
}
int s0[50001], f[50001];
int main() {
	long long k;
	int n;
	k = read(), mod = read(), n = read();
	for (int i = 0; i < n; i++) s[i] = s0[i] = read();
	s[n] = s0[n] = s[0];
	build(1, 0, n - 1);
	int q = read();
	for (int i = 1; i <= q; i++) c[i].j = read(), c[i].v = read();
	sort(c + 1, c + q + 1);
	long long last = 0;
	matrix ans, tmp = m[1];
	int p = 1;
	while (last < k/n) {
		int p0 = p;
		while (c[p].j/n == last) {
			s[c[p].j%n] = c[p].v;
			modify(1, 0, n-1, c[p].j%n, matrix(s[c[p].j%n+1], s[c[p].j%n],1,0));
			if (c[p].j%n) modify(1, 0, n-1, c[p].j%n-1, matrix(s[c[p].j%n], s[c[p].j%n-1],1,0));
			++p;
		}
		if (p <= q && c[p].j / n == last + 1 && c[p].j%n == 0) {
			s[n] = c[p].v;
			modify(1, 0, n-1, n-1, matrix(s[n], s[n-1],1,0));
		}
		ans = m[1] * ans;
		while (p0 < p) {
			s[c[p0].j%n] = s0[c[p0].j%n];
			modify(1, 0, n-1, c[p0].j%n, matrix(s[c[p0].j%n+1], s[c[p0].j%n],1,0));
			if (c[p0].j%n) modify(1, 0, n-1, c[p0].j%n-1, matrix(s[c[p0].j%n], s[c[p0].j%n-1],1,0));
			++p0;
		}
		if (p0 <= q && c[p0].j / n == last + 1 && c[p0].j%n == 0) {
			s[n] = s0[n];
			modify(1, 0, n-1, n-1, matrix(s[n], s[n-1],1,0));
		}
		long long nl;
		if (p > q || last == k/n-1) {
			nl = k/n-1;
			ans = power(tmp, nl - last) * ans;
			break;
		}
		nl = c[p].j/n;
		if (nl > last + 1 && c[p].j % n == 0) --nl;
		if (nl >= k / n) nl = k/n-1;
		ans = power(tmp, nl - last - 1) * ans, last = nl;
	}
	while (p <= q && c[p].j <= k) s[c[p].j%n] = c[p].v, ++p;
	f[1] = ans.a[0][0], f[0] = ans.a[1][0];
	for (int i = 2; i < n; i++) f[i] = (1ll*s[i-1]*f[i-1]+1ll*s[i-2]*f[i-2])%mod;
	cout << f[k%n] << endl;
}