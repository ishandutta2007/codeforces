#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
typedef std :: vector<int> poly;
#define P 998244353
#define G 3
#define GI 332748118
namespace Polynomial{
	std :: vector<int> rev;
	void inc(int &a, int b){
		(a += b) >= P ? a -= P : 0;
	}
	int minus(int a, int b){
		return (a -= b) < 0 ? a + P : a;
	}
	int qpow(int a, int b){
		int s = 1;
		for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
		return s;
	}
	int get(int n){
		int res = 1;
		while (res < n) res <<= 1;
		return res;
	}
	void init(int n){
		register int k = 0;
		while ((1 << k) < n) ++k;
		--k, rev.resize(n), rev[0] = 0;
		for (register int i = 1; i < n; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
	}
	void NTT(poly &a, int n, int op){
		a.resize(n);
		for (register int i = 0; i < n; ++i) if (i < rev[i]) std :: swap(a[i], a[rev[i]]);
		for (register int m = 1; m < n; m <<= 1){
			std :: vector<int> omega(m);
			register int l = m << 1, _w = qpow(op == 1 ? G : GI, (P - 1) / l);
			omega[0] = 1;
			for (register int i = 1; i < m; ++i) omega[i] = 1ll * omega[i - 1] * _w % P;
			for (register int p = 0; p < n; p += l)
				for (register int i = 0; i < m; ++i){
					register int t = 1ll * omega[i] * a[p + m + i] % P;
					a[p + m + i] = minus(a[p + i], t), inc(a[p + i], t);
				}
		}
		if (op == -1){
			register int _n = qpow(n, P - 2);
			for (register int i = 0; i < n; ++i) a[i] = 1ll * a[i] * _n % P;
		}
	}
	poly multiply(poly a, poly b){
		int m = a.size() + b.size() - 1, n = get(m);
		init(n), NTT(a, n, 1), NTT(b, n, 1);
		for (register int i = 0; i < n; ++i) a[i] = 1ll * a[i] * b[i] % P;
		NTT(a, n, -1), a.resize(m);
		return a;
	}
}
using Polynomial :: multiply;
#define N 20005
int n, k, a[N], Q, b[N];
poly solve(int l, int r){
	if (l == r) return {1, b[l]};
	int md = (l + r) >> 1;
	return multiply(solve(l, md), solve(md + 1, r));
}
int main(){
	n = read(), k = read();
	for (register int i = 1; i <= n; ++i) a[i] = read() % P;
	Q = read();
	while (Q--){
		int opt = read(), q = read(), l, r, d;
		for (register int i = 1; i <= n; ++i) b[i] = a[i];
		if (opt == 1) l = read(), d = read() % P, b[l] = d;
		else{
			l = read(), r = read(), d = read();
			for (register int i = l; i <= r; ++i) b[i] = (b[i] + d) % P;
		}
		for (register int i = 1; i <= n; ++i) b[i] = (q - b[i] + P) % P;
		printf("%d\n", solve(1, n)[k]);
	}
}