#include<bits/stdc++.h>
#define int long long 
#define N 1005
#define mod 1000000007
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,dp[N][N][2][2],f[N],inv[N],fac[N];
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res%mod;
}
int C(int a,int b){
	return (fac[b]*inv[a]%mod)%mod*inv[b-a]%mod;
}
void init(){
	fac[0] = inv[0] = 1;
	rep(i,1,n) fac[i] = fac[i-1]*i%mod;
	rep(i,1,n) inv[i] = qpow(fac[i],mod-2);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	init();
 	dp[1][0][0][0] = 1;
 	dp[1][1][0][1] = 1;
 	rep(i,2,n-1){
 		dp[i][0][0][0] = 1;
 		rep(j,1,i){
 			dp[i][j][1][0] = (dp[i-1][j-1][0][1] + dp[i-1][j][0][1] + dp[i-1][j][1][1])%mod;
 			dp[i][j][0][0] = (dp[i-1][j-1][0][0] + dp[i-1][j][0][0] + dp[i-1][j][1][0])%mod;
 			dp[i][j][0][1] = (dp[i-1][j-1][1][0] + dp[i-1][j-1][0][0])%mod;
 			dp[i][j][1][1] = (dp[i-1][j-1][1][1] + dp[i-1][j-1][0][1])%mod;
 			//printf("i j : %d %d\nA: %d \n0 1: %d\n",i,j,dp[i][j][0][0],dp[i][j][0][1]);
 		}
 	}
 	dp[n][0][0][0] = 1;
 	rep(j,1,n){
 		dp[n][j][0][0] = (dp[n-1][j-1][0][0] + dp[n-1][j][0][0] + dp[n-1][j][1][0])%mod;
 		dp[n][j][1][0] = (dp[n-1][j-1][0][1] + dp[n-1][j][0][1] + dp[n-1][j][1][1])%mod;
 	}
 	rep(i,0,n) f[i] = ((dp[n][i][0][0]+dp[n][i][1][0])%mod*fac[n-i]%mod)%mod;//,cout << i << ' ' << f[i] << endl;
 	int ans = 0;
 	rep(i,m,n){
 		int res = C(m,i)*f[i]%mod;
 		if((i+m)&1) res = mod-res;
 		ans = (ans+res)%mod;
 	}
 	printf("%lld\n",ans);
	return 0;
}