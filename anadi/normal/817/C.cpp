#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second

LL n, s;
int ile = 0;
int ile2 = 0;
LL res = 0LL;
LL dp[20][10][250];

LL solve(LL limit, int sum){
//	printf("%lld %d\n", limit, sum);
	
	vector <int> C;
	while(limit > 0){
		C.pb(limit%10);
		limit /= 10;
	}
	
	LL result = 0LL;
	for(int i = C.size() - 1; i >= 0; --i){
		if(sum < 0)
			break;
		for(int j = 0; j < C[i]; ++j)
			result += dp[i][j][sum];
		sum -= C[i];
	}
	
	if(sum >= 0 && C.size() > 0)
		result += dp[0][C[0]][sum + C[0]];
//	printf("%lld\n", result);
	return result;
}

int main(){
	scanf("%lld %lld", &n, &s);
	
	for(int j = 0; j < 10; ++j)
		dp[0][j][j] = 1;
	
	for(int i = 1; i < 19; ++i){
		for(int j = 0; j < 10; ++j)
			for(int k = 0; k < 10; ++k)
				for(int s = j + k; s < 200; ++s)
					dp[i][j][s] += dp[i - 1][k][s - j];
	}
	
	for(int i = 1; i <= 200; ++i)
		if(s + i - 1 <= n)
			res += solve(n, i) - solve(s + i - 1, i);
	printf("%lld\n", res);
	return 0;
}