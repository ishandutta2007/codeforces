#include<bits/stdc++.h>
#define Q 1000000007
using namespace std;
int qp(int a,int x){
	int r=1;
	while(x){
		if(x&1) r=1LL*r*a%Q;
		a=1LL*a*a%Q;
		x>>=1;
	}
	return r;
}
int dp[2000][2000];
int main(){
	int k,a,b,pa,pb,ans=0;
	scanf("%d%d%d",&k,&a,&b);
	pa=1LL*a*qp(a+b,Q-2)%Q;
	pb=(Q+1)-pa;
	dp[1][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<k-i;j++){
			dp[i+1][j]=(dp[i+1][j]+1LL*dp[i][j]*pa%Q)%Q;
			if(j+i+i>=k){
				ans=(ans+1LL*dp[i][j]*pb%Q*(j+i+i-k)%Q)%Q;
			}
			else dp[i][j+i]=(dp[i][j+i]+1LL*dp[i][j]*pb%Q)%Q;
		}
	}
	ans=(ans+k+1LL*a*qp(b,Q-2)%Q)%Q;
	printf("%d\n",ans);
}