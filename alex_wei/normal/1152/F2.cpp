#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 5;
const int mod = 1e9 + 7;
int n, k, m, sz;
struct mat {
	int a[N][N];
	mat operator * (mat x) {
		mat y; memset(y.a, 0, sizeof(y.a));
		for(int i = 0; i <= sz; i++)
			for(int j = 0; j <= sz; j++)
				for(int k = 0; k <= sz; k++)
					y.a[i][j] = (y.a[i][j] + 1ll * a[i][k] * x.a[k][j]) % mod;
		return y;
	}
} b, I;
int main() {
	cin >> n >> k >> m, sz = k << m;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < 1 << m; j++) {
			int msk = j << 1 & (1 << m) - 1;
			int coef = 1 + __builtin_popcount(j);
			b.a[(i << m) + j][(i << m) + msk] = 1;
			if(i == k - 1) b.a[(i << m) + j][sz] = coef;
			else b.a[(i << m) + j][(i + 1 << m) + msk + 1] = coef;
		}
	b.a[sz][sz] = I.a[0][0] = 1;
	while(n) {
		if(n & 1) I = I * b;
		b = b * b, n >>= 1;
	}
	cout << I.a[0][sz] << endl;
	return 0;
}

/*
stupid mistakes:
	 msk 
*/