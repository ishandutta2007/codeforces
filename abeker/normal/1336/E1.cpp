#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MAXM = 36;
const int LARGE = 20;
const int SMALL = 15;
const int MOD = 998244353;

int N, M;
ll a[MAXN];
vector <ll> basis;
vector <int> lft, frei;
int dp[MAXM][MAXM][1 << SMALL];
int byBitcount[MAXM];
int cols[MAXM];
int rnk;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

void compute_image() {
	for (int j = 0; j < M; j++) {
		for (int i = rnk; i < N; i++)
			if (a[i] >> j & 1ll) {
				swap(a[i], a[rnk]);
				break;
			}
		if (a[rnk] >> j & 1ll) {
			for (int i = rnk + 1; i < N; i++)
				if (a[i] >> j & 1ll)
					a[i] ^= a[rnk];
			basis.push_back(a[rnk++]);
			lft.push_back(j);
		}
		else
			frei.push_back(j);
	}
}

void compute_kernel() {
	for (int k = 0; k < M - rnk; k++) {
		ll tmp = 1ll << frei[k];
		for (int i = rnk - 1; i >= 0; i--)
			for (int j = lft[i] + 1; j < M; j++)
				if ((tmp & basis[i]) >> j & 1ll)
					tmp ^= 1ll << lft[i];
		for (int j = 0; j < M; j++)
			if (tmp >> j & 1ll)
				cols[j] ^= 1 << k;
	}
}

void naive() {
	for (int i = 0; i < 1 << rnk; i++) {
		ll tmp = 0;
		for (int j = 0; j < rnk; j++)
			if (i >> j & 1)
				tmp ^= basis[j];
		byBitcount[__builtin_popcountll(tmp)]++;
	}
}

int rec(int pos, int cnt, int mask) {
	int &ref = dp[pos][cnt][mask];
	if (ref != -1)
		return ref;
	return ref = add(rec(pos + 1, cnt, mask), cnt ? rec(pos + 1, cnt - 1, mask ^ cols[pos]) : 0);
}

void clever() {
	compute_kernel();
	memset(dp, -1, sizeof dp);
	for (int i = 0; i <= M; i++) 
		for (int j = 0; j < 1 << SMALL; j++)
			dp[M][i][j] = !i && !j;
	for (int i = 0; i <= M; i++)
		byBitcount[i] = rec(0, i, 0);
}

void solve() {
	compute_image();
	if (rnk <= LARGE)
		naive();
	else
		clever();
	int pot = 1;
	for (int nullity = N - rnk; nullity; nullity--)
		pot = mul(pot, 2);
	for (int i = 0; i <= M; i++)
		printf("%d ", mul(byBitcount[i], pot));
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}