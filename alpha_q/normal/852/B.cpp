#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

struct matrix {
	long long m[101][101];
	int R, C;
	matrix (int R, int C) : R(R), C(C) {
		memset(m, 0, sizeof m);
	}
	matrix operator * (matrix x) const {
		matrix ans (R, x.C);
		for(int i = 0; i < ans.R; i++) {
			for(int j = 0; j < ans.C; j++) {
				for(int k = 0; k < C; k++) {
					ans.m[i][j] += m[i][k] * x.m[k][j];
					ans.m[i][j] %= mod;
				}
			}
		}
		return ans;
	}
	void out() {
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				printf("%lld ", m[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
};
matrix modpow(matrix p, int e) {
	if (e == 0) {
		matrix id (p.R, p.R);
		for(int i = 0; i < p.R; i++) {
			id.m[i][i] = 1;
		}
		return id;
	}
	if(e & 1) return modpow(p, e-1) * p;
	matrix m = modpow(p, e >> 1);
	return m * m;
}
int cost[1000010];

int main() {
	int n, l, m;
	scanf("%d %d %d", &n, &l, &m);
	matrix vec (m, 1);
	
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		++vec.m[x % m][0];
	}
	int cnt[200];
	memset(cnt, 0, sizeof cnt);
	
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x % m] += 1;
		cost[i] = x % m;
	}
	
	matrix res (m, m);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < m; j++) {
			res.m[i][j] = cnt[(m + i - j) % m];
		}
	}
	matrix ans = modpow(res, l - 2) * vec;
	int ret = 0;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int req = (m - (x + cost[i])) % m;		
		if(req < 0) req += m;
		ret += ans.m[req][0];
		ret %= mod;
	}
	printf("%d\n", ret);
	return 0;
}