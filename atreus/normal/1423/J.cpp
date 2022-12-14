#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int dp[8], a[62];
int par[8];

int solve(ll m){
	int q = log2(m);
	for (int i = 0; i < 60; i++){
		if (m & (1LL<<i))
			a[i] = 1;
		else
			a[i] = 0;
	}
	for (int i = 0; i < q+1; i++){
		for (int j = 0; j < 8; j++){
			dp[j] = 0;
			if (i == 0){
				if (2*j+a[i] < 8)
					dp[j] = 1;
				continue;
			}
			int l = max(0,a[i]+2*j-7), r = min(7,a[i]+2*j);
			if (l == 0)
				dp[j] = par[r];
			else{
				dp[j] = par[r] - par[l-1];
				if (dp[j] < 0)
					dp[j] += mod;
			}
		}
		par[0] = dp[0];
		for (int j = 1; j < 8; j++){
			par[j] = dp[j]+par[j-1];
			if (par[j] >= mod)
				par[j] -= mod;
		}
	}
	return dp[0];
}

int main(){
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++){
		ll x;
		scanf("%lld", &x);
		printf("%d\n", solve(x));
	}
}