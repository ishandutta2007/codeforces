#include<bits/stdc++.h>
#define Q 1000000007
#define K 210
using namespace std;
long long dp[K][K][K]; //dp[n-#cycle][#(size>1-cycle)][upper bound for cycle size]
long long calc_inv(long long x){
	long long r=1,y=Q-2;
	while(y){
		if(y&1) r=r*x%Q;
		x=x*x%Q;
		y>>=1;
	}
	return r;
}
int main(){
	int n,k;
	long long inv[K],ifac[K]={1};
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k+1;i++){
		inv[i]=calc_inv(i);
		ifac[i]=ifac[i-1]*inv[i]%Q;
		dp[0][0][i]=1;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i && i+j<=n;j++){
			long long nom[K*2];
			nom[0]=1;
			for(int l=1;l<=i+j;l++){
				nom[l]=nom[l-1]*(n-i-j+l)%Q;
			}
			for(int sz=2;sz<=k+1;sz++){
				dp[i][j][sz]=dp[i][j][sz-1];
				long long pre=1;
				for(int cnt=1;cnt<=j && cnt*(sz-1)<=i;cnt++){
					pre=pre*inv[sz]%Q;
					dp[i][j][sz]+=dp[i-cnt*(sz-1)][j-cnt][sz-1] *nom[cnt*sz]%Q *pre%Q *ifac[cnt]%Q;
				}
				dp[i][j][sz]%=Q;
			}
		}
	}
	long long s[2]={1,0};
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			s[i&1]+=dp[i][j][i+1];
			//printf("%d %d %lld\n",i,j,dp[i][j][i+1]);
		}
		s[i&1]%=Q;
		printf("%lld ",s[i&1]);
	}
	puts("");
	return 0;
}