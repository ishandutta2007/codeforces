#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int MX = 998244353;

LL l, r;
int pt[20], k;
int dp[20][10][1200];
int cnt[20][10][1200];

void add(int &a, int b){
	a += b;
	if(a >= MX)
		a -= MX;
}

int ask(LL t){
	if(t == 0)
		return 0;

	LL pot = 1LL;
	int licz = 0;
	
	while(10 * pot <= t)
		pot *= 10, ++licz;
	
	int ret = ask(pot - 1), mask = 0, up = 0;
	for(int b = licz + 1; b > 0; --b){
		int from = b == licz + 1 ? 1 : 0;
		for(int i = from; i < t / pot; ++i)
			for(int j = 0; j < 1024; ++j)
				if(__builtin_popcount(j | mask) <= k){
					add(ret, dp[b][i][j]);
//					if(dp[b][i][j] > 0)
//						printf("%d %d %d :: %d\n", b, i, j, dp[b][i][j]);
					add(ret, (1LL * cnt[b][i][j] * up)%MX);
				}
		
//		printf("MAM %d\n", ret);
		up = (up + t / pot * pot)%MX;
		mask |= 1 << (t / pot);
		t %= pot;
		pot /= 10;
	}
	
//	printf("%d\n", up);
	if(__builtin_popcount(mask) <= k)
		add(ret, up);
	return ret;
}

int main(){
	pt[0] = 1;
	for(int i = 1; i < 19; ++i)
		pt[i] = (10LL * pt[i - 1])%MX;

	dp[0][0][0] = 0;
	cnt[0][0][0] = 1;
	for(int i = 0; i < 10; ++i)
		dp[1][i][1 << i] = i,
		cnt[1][i][1 << i] = 1;

	for(int i = 2; i < 19; ++i){
		for(int j = 0; j < 1024; ++j){
			for(int ii = 0; ii < 10; ++ii)
				if(j & (1 << ii))
					for(int k = 0; k < 10; ++k)
						if(j & (1 << k)){
							add(cnt[i][ii][j], cnt[i - 1][k][j]);
							add(cnt[i][ii][j], cnt[i - 1][k][j - (1 << ii)]);
							
							add(dp[i][ii][j], (1LL * cnt[i - 1][k][j] * ((1LL * pt[i - 1] * ii)%MX) + dp[i - 1][k][j])%MX);
							add(dp[i][ii][j], (1LL * cnt[i - 1][k][j - (1 << ii)] * ((1LL * pt[i - 1] * ii)%MX) + dp[i - 1][k][j - (1 << ii)])%MX);
						}
		}
	}
	
//	printf("%d %d\n", cnt[2][0][3], cnt[2][1][3]);
	scanf("%lld %lld %d", &l, &r, &k);
//	printf("%d\n", ask(r));
	printf("%d\n", (ask(r) - ask(l - 1) + MX)%MX);
	return 0;
}