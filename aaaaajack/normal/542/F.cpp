#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#define T 110
#define N 1010
using namespace std;
int dp[T][N],sz;
int sum[T][N],cnt[T];
int f(int t,int n){
	if(n>sz) n=sz;
	if(!n||!t) return 0; 
	if(dp[t][n]>=0) return dp[t][n];
	int i,r=0;
	for(i=0;i<=min(cnt[t],n);i++){
		r=max(r,f(t-1,(n-i)*2)+sum[t][i]);
	}
	return dp[t][n]=r;
}
int main(){
	int n,t,x,y,i,j;
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&t);
	sz=n;
	while(n--){
		scanf("%d%d",&x,&y);
		sum[x][++cnt[x]]=y;
	}
	for(i=1;i<=t;i++){
		sort(sum[i]+1,sum[i]+cnt[i]+1,greater<int>());
		for(j=1;j<=cnt[i];j++) sum[i][j]+=sum[i][j-1];
	}
	printf("%d\n",f(t,1));
	return 0;
}