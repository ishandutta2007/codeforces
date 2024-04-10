#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int RT = 3;

const int MAXT = 19;
const int MAXL = 550000;

int fac[MAXL + 5], ifac[MAXL + 5], inv[MAXL + 5];
int rg[MAXT + 5];

int ub2(int n)
{
	int ret = 0;
	while((1 << ret) < n) ret ++;
	return ret;
}

int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1LL * ret * x % MOD;
		x = 1LL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int cr[MAXL + 5];
void dft(int arr[], int siz, int dir)
{
	if(dir == -1) reverse(arr + 1, arr + (1 << siz));
	int cur = 0;
	for(int i = 0; i < (1 << siz); i ++) {
		if(cur < i) swap(arr[cur], arr[i]);
		for(int j = siz - 1; j >= 0; j --) {
			cur ^= 1 << j;
			if(cur >> j & 1) break;
		}
	}
	rep1(d, siz) {
		int pr = rg[d];
		cr[0] = 1;
		for(int i = 1; i < (1 << (d - 1)); i ++) cr[i] = 1LL * cr[i - 1] * pr % MOD;
		for(int i = 0; i < (1 << siz); i += 1 << d) rep(j, 1 << (d - 1)) {
			int ev = arr[i + j], od = 1LL * arr[i + j + (1 << (d - 1))] * cr[j] % MOD;
			arr[i + j] = ev + od - (ev + od >= MOD ? MOD : 0);
			arr[i + j + (1 << (d - 1))] = ev - od + (ev - od < 0 ? MOD : 0);
		}
	}
	if(dir == -1) {
		int invn = inv[1 << siz];
		rep(i, 1 << siz) arr[i] = 1LL * arr[i] * invn % MOD;
	}
}

int tmp0[MAXL + 5], tmp1[MAXL + 5];
void poly_mul(int A[], int B[], int ret[], int siz)
{
	rep(i, 1 << (siz + 1)) tmp0[i] = i >> siz ? 0 : A[i];
	rep(i, 1 << (siz + 1)) tmp1[i] = i >> siz ? 0 : B[i];
	dft(tmp0, siz + 1, 1);
	dft(tmp1, siz + 1, 1);
	rep(i, 1 << (siz + 1)) ret[i] = 1LL * tmp0[i] * tmp1[i] % MOD;
	dft(ret, siz + 1, -1);
}

void poly_inv(int A[], int ret[], int siz)
{
	rep(i, 1 << siz) tmp1[i] = i == 0 ? power(A[0], MOD - 2) : 0;
	rep1(i, siz) {
		rep(j, 1 << (i + 1)) tmp0[j] = j >> i ? 0 : A[j];
		rep(j, 1 << (i + 1)) tmp1[j] = j >> (i - 1) ? 0 : tmp1[j];
		dft(tmp0, i + 1, 1);
		dft(tmp1, i + 1, 1);
		rep(j, 1 << (i + 1)) tmp1[j] = (2 + 1LL * (MOD - tmp0[j]) * tmp1[j] % MOD) * tmp1[j] % MOD;
		dft(tmp1, i + 1, -1);
	}
	rep(i, 1 << siz) ret[i] = tmp1[i];
}

int tmp2[MAXL + 5];
void poly_ln(int A[], int ret[], int siz)
{
	rep(i, 1 << siz) if(i > 0) tmp2[i - 1] = 1LL * A[i] * i % MOD;
	poly_inv(A, ret, siz);
	poly_mul(ret, tmp2, ret, siz);
	for(int i = (1 << siz) - 1; i >= 0; i --) ret[i] = i == 0 ? 0 : 1LL * inv[i] * ret[i - 1] % MOD;
}

int tmp3[MAXL + 5], tmp4[MAXL + 5];
void poly_exp(int A[], int ret[], int siz)
{
	rep(i, 1 << siz) tmp3[i] = i == 0;
	rep1(i, siz) {
		poly_ln(tmp3, tmp4, i);
		rep(j, 1 << i) tmp4[j] = ((j == 0) + A[j] - tmp4[j] + MOD) % MOD;
		poly_mul(tmp3, tmp4, tmp3, i);
	}
	rep(i, 1 << siz) ret[i] = tmp3[i];
}

void init()
{
	rg[0] = 1;
	rep1(i, MAXT) rg[i] = power(RT, (MOD - 1) >> i);
	fac[0] = 1;
	rep1(i, MAXL) fac[i] = 1LL * fac[i - 1] * i % MOD;
	ifac[MAXL] = power(fac[MAXL], MOD - 2);
	for(int i = MAXL; i >= 1; i --) ifac[i - 1] = 1LL * ifac[i] * i % MOD;
	rep1(i, MAXL) inv[i] = 1LL * ifac[i] * fac[i - 1] % MOD;
}

int n, m, dat[300005], A[300005], B[300005], C[300005], D[300005], E[300005], F[300005], G[300005];

int main()
{
	init();
	scanf("%d%d", &n, &m);
	int cur = 1;
	rep1(i, n) {
		int maxt = (m + i) / 2;
		if(maxt == (m + i - 1) / 2) cur = 1LL * cur * (maxt - i + 1) % MOD;
		else cur = 1LL * cur * maxt % MOD;
		cur = 1LL * cur * inv[i] % MOD;
		dat[i] = (cur + MOD) % MOD;
	}
	
	rep1(i, n) if(i % 4 == 0) A[i] = (MOD - dat[i]) % MOD;
	else if(i % 4 == 1) B[i] = dat[i];
	else if(i % 4 == 2) A[i] = dat[i];
	else B[i] = (MOD - dat[i]) % MOD;
	
	A[0] = 1;
	rep1(i, n) A[i] = (MOD - A[i]) % MOD;
	poly_inv(A, C, 16);
	poly_mul(B, C, D, 16);
	D[0] = 1;
	rep1(i, n) D[i] = (MOD - D[i]) % MOD;
	poly_inv(D, E, 16);
	poly_ln(C, F, 16);
	poly_ln(E, G, 16);
	int ans = 1LL * n * (F[n] + G[n]) % MOD;
	printf("%d\n", ans);
	return 0;
}