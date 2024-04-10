#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 207;
const int MX = 998244353;

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = 1LL * ret * a % MX;
		
		b >>= 1;
		a = 1LL * a * a % MX;
	}
	
	return ret;
}

int n, m;
int Left[N], Right[N];

int dp[N][N];
int from[N], to[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &Left[i], &Right[i]);
	
	for(int i = 1; i + i <= n; ++i){
		swap(Left[i], Left[n - i + 1]);
		swap(Right[i], Right[n - i + 1]);
	}
	
	set <int> Intrvs;
	for(int i = 1; i <= n; ++i){
		Intrvs.insert(Left[i]);
		Intrvs.insert(Right[i]);
	}
	
	int last = 0;
	from[0] = to[0] = 0;
	while(Intrvs.size()){
		auto it = *Intrvs.begin();
		Intrvs.erase(Intrvs.begin());
		
		if(last + 1 < it){
			++m;
			from[m] = last + 1;
			to[m] = it - 1;
		}
		
		++m;
		from[m] = to[m] = it;
		last = it;
	}
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(to[j] < Left[i] || Right[i] < from[j])
				continue;
			
			int cur = to[j] - from[j] + 1;
			for(int prv = i - 1; prv >= 0; --prv){
//				printf("update %d %d -> %d %d\n", i, j, prv, cur);
				for(int k = 0; k < j; ++k)
					dp[i][j] = (dp[i][j] + 1LL * cur * dp[prv][k]) % MX;
				
				cur = (((1LL * cur * fast(i - prv + 1, MX - 2)) % MX) * (to[j] - from[j] + 1 + i - prv)) % MX;
				if(to[j] < Left[prv] || Right[prv] < from[j])
					break;
			}
			
//			printf("%d %d -> %d\n", i, j, dp[i][j]);
		}
	}
	
	LL ans = 0;
	for(int i = 1; i <= m; ++i)
		ans += dp[n][i];
	ans %= MX;

//	printf("%lld\n", ans);
	for(int i = 1; i <= n; ++i)
		ans = ans * fast(Right[i] - Left[i] + 1, MX - 2) % MX;
	printf("%lld\n", ans);
	return 0;
}