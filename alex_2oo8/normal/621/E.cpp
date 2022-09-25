#include<bits/stdc++.h>

using namespace std;

const int md = 1000000007;
const long long md2 = md * 1ll * md;

struct matrix {
	int n, m;
	int a[100][100];
	
	matrix(int _n, int _m) : n(_n), m(_m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = 0;
	}
	
	matrix operator * (const matrix& M) const {
		matrix res(n, M.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < M.m; j++) {
				long long f = 0;
				for (int k = 0; k < m; k++) {
					f += a[i][k] * 1ll * M.a[k][j];
					if (f >= md2) f -= md2;
				}
				
				res.a[i][j] = f % md;
			}
		
		return res;
	}
	
	void operator = (const matrix& M) {
		n = M.n;
		m = M.m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = M.a[i][j];
	}
	
	void operator *= (const matrix& M) {
		*this = (*this) * M;
	}

};

int cnt[10];

int main() {
	int n, b, k, x;
	scanf("%d %d %d %d", &n, &b, &k, &x);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		cnt[a]++;
	}
	
	matrix M(x, x);
	
	for (int i = 0; i < x; i++)
		for (int d = 0; d < 10; d++) {
			M.a[i][(10 * i + d) % x] += cnt[d];
			M.a[i][(10 * i + d) % x] %= md;
		}
	
	matrix v(1, x);
	v.a[0][0] = 1;
	
	while (b) {
		if (b % 2 == 1) v *= M;
		
		M *= M;
		b /= 2;
	}
	
	printf("%d\n", v.a[0][k]);
	
	return 0;
}