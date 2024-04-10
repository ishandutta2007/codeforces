#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 1000000;
const int MOD = 1000000007;

int N;
int a[MAXN];
int cnt[MAXN], sum[MAXN], sq[MAXN];
int pot[MAXN];
int digit[MAXN][10];
int dp[MAXN];
int ten[10];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)	
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline void inc(int &x, int y) {
	x = add(x, y);
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

ll solve() {
	ten[0] = 1;
	for (int i = 1; i < 6; i++)
		ten[i] = ten[i - 1] * 10;
		
	pot[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pot[i] = mul(pot[i - 1], 2);
		
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < 6; j++)
			digit[i][j] = i / ten[j] % 10;
			
	for (int i = 0; i < N; i++) {
		cnt[a[i]]++;
		inc(sum[a[i]], a[i]);
		inc(sq[a[i]], mul(a[i], a[i]));
	}
	
	for (int i = MAXN - 1; i >= 0; i--) 
		for (int j = 1; j < 64; j++) {
			int num = i;
			bool ok = true;
			for (int k = 0; k < 6; k++) 
				if (j >> k & 1) {
					num += ten[k];
					ok &= digit[i][k] < 9;
				}
			if (ok) {
				int odd = __builtin_popcount(j) % 2;
				cnt[i] += odd ? cnt[num] : -cnt[num];
				inc(sum[i], odd ? sum[num] : -sum[num]);
				inc(sq[i], odd ? sq[num] : -sq[num]);
			}
		}
	
	for (int i = 0; i < MAXN; i++)
		if (cnt[i])
			dp[i] = cnt[i] > 1 ? mul(pot[cnt[i] - 2], add(mul(sum[i], sum[i]), sq[i])) : sq[i];
	
	ll sol = 0;
	for (int i = 0; i < MAXN; i++) {
		int g = 0;
		for (int j = 0; j < 64; j++) {
			int num = i;
			bool ok = true;
			for (int k = 0; k < 6; k++) 
				if (j >> k & 1) {
					num += ten[k];
					ok &= digit[i][k] < 9;
				}
			if (ok && cnt[num]) 
				inc(g, __builtin_popcount(j) % 2 ? -dp[num] : dp[num]);
		}
		sol ^= (ll)i * g;
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}