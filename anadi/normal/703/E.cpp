#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PLI pair <LL, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1007;
const int mxd = 7e3 + 7;
const int INF = 1e9 + 7;

int n;
LL k;
LL a[mxn];
LL sum[mxn][mxd];
int dp[mxn][mxd];
int par[mxn][mxd];
int how[mxn][107];
PLI primes[107];
int ile[107];
int divisors = 1;

int main(){
	scanf("%d %I64d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%I64d", &a[i]);
	
	if(k == 1){
		int number = 1;
		for(int i = 2; i <= n; ++i)
			if(a[i] < a[number])
				number = i;

		printf("1\n%d\n", number);
		return 0;
	}
	
	int c_primes = 0;
	for(LL i = 2LL; i * i <= k; ++i)
		if(k%i == 0){
			primes[++c_primes] = mp(i, 0);
			while(k%i == 0){
				k /= i;
				primes[c_primes].nd++;
			}
		}
	
	if(k != 1)
		primes[++c_primes] = mp(k, 1);
	
	for(int i = 1; i <= c_primes; ++i)
		divisors *= primes[i].nd + 1;
	
	ile[c_primes] = 1;
	for(int i = c_primes - 1; i >= 0; --i)
		ile[i] = ile[i + 1] * (primes[i + 1].nd + 1);
	
	for(int i = 1; i <= n; ++i){
		LL x = a[i];
		
		for(int j = 1; j <= c_primes; ++j){
			while(x%primes[j].st == 0){
				how[i][j]++;
				x /= primes[j].st;
			}
		}
	}
	
	for(int i = 1; i < divisors; ++i){
		dp[0][i] = INF;
		par[0][i] = i;
		sum[0][i] = INF;
	}
	
	int x;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < divisors; ++j){
			int last = 0, cur = j;
			for(int ii = 1; ii <= c_primes; ++ii){
				last += ile[ii] * (max(0, cur / ile[ii] - how[i][ii]));
				cur %= ile[ii];
			}
			
			dp[i][j] = dp[i - 1][last] + 1;
			par[i][j] = last;
			sum[i][j] = sum[i - 1][last] + a[i];
			
			if(dp[i - 1][j] < dp[i][j] || (dp[i - 1][j] == dp[i][j] && sum[i - 1][j] < sum[i][j])){
				dp[i][j] = dp[i - 1][j];
				par[i][j] = j;
				sum[i][j] = sum[i - 1][j];
			}
		}
	
	divisors--;
	if(dp[n][divisors] == INF){
		puts("-1");
		return 0;
	}
	
	printf("%d\n", dp[n][divisors]);
	for(int i = n; i >= 1; --i)
		if(par[i][divisors] != divisors){
			printf("%d ", i);
			divisors = par[i][divisors];
		}

	return 0;
}