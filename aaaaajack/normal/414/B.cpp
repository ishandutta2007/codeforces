#include<cstdio>
#include<cstring>
#define N 3000
#define Q 1000000007
using namespace std;
bool isprime[N];
int prime[N];
int dp[N][N]={0},cnt[N][N]={0};
int c(int n,int k){
	if(n<k||k<0) return 0;
	if(k==0||n==k) return 1;
	if(dp[n][k]) return dp[n][k];
	if(k<n-k) return c(n,n-k);
	return dp[n][k]=(c(n-1,k-1)+c(n-1,k))%Q;
}
int h(int r,int n){
	return c(n+r-1,r-1);
}
int pcnt=0;
int main(){
	memset(isprime,-1,sizeof(isprime));
	int i,j,l;
	for(i=2;i<N;i++){
		if(isprime[i]){
			prime[pcnt++]=i;
			for(j=2;i*j<N;j++){
				isprime[i*j]=false;
			}
		}
	}
	for(i=1;i<N;i++){
		l=i;
		for(j=0;j<pcnt;j++){
			while(l%prime[j]==0) l/=prime[j],cnt[i][j]++;
		}
	}
	int n,k,ans=0,tans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		tans=1;
		for(j=0;j<pcnt;j++){
			tans=1LL*h(k,cnt[i][j])*tans%Q;
		}
		ans=(ans+tans)%Q;
	}
	printf("%d\n",ans);
	return 0;
}