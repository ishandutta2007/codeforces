#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long dp[2][2][1003][1003],fac[1003],inv[1003],n,m,ans[1003];
long long mypow(long long x,long long times){
	if(times==0)return 1;
	long long ret=mypow(x,times/2);
	ret=ret*ret%mod;if(times%2)ret=ret*x%mod;
	return ret;
}
long long C(long long x,long long y){
	if(x<y||y<0)return 0;
	return (fac[x]*inv[y]%mod)*inv[x-y]%mod;
}
int main(){cin>>n>>m;
	fac[0]=1;for(int i=1;i<1003;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=0;i<1003;i++)inv[i]=mypow(fac[i],mod-2);
	dp[0][0][1][0]=1;
	dp[0][1][1][1]=1;
	for(register int i=2;i<n;i++){
		dp[0][0][i][0]=1;
		for(register int j=1;j<=i;j++){
			dp[0][0][i][j]=(dp[0][0][i-1][j-1]+dp[0][0][i-1][j]+dp[1][0][i-1][j])%mod;
			dp[0][1][i][j]=(dp[0][0][i-1][j-1]+dp[1][0][i-1][j-1])%mod;
			dp[1][0][i][j]=(dp[0][1][i-1][j-1]+dp[0][1][i-1][j]+dp[1][1][i-1][j])%mod;
			dp[1][1][i][j]=(dp[0][1][i-1][j-1]+dp[1][1][i-1][j-1])%mod;
		}
	}
	dp[0][0][n][0]=1;
	for(register int j=1;j<=n;j++){
		dp[0][0][n][j]=(dp[0][0][n-1][j-1]+dp[0][0][n-1][j]+dp[1][0][n-1][j])%mod;
		dp[1][0][n][j]=(dp[0][1][n-1][j-1]+dp[0][1][n-1][j]+dp[1][1][n-1][j])%mod;
	}
	for(register int i=0;i<=n;i++)
		ans[i]=(dp[0][0][n][i]+dp[1][0][n][i])*fac[n-i]%mod;
	long long res=0;
	for(register int i=m;i<=n;i++){
		long long qaq=C(i,m)*ans[i]%mod;
		if((i-m)%2)qaq=mod-qaq;
		res+=qaq;
	}cout<<res%mod;
}