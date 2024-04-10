#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;
int cnt[N]={};
long long dp[N]={};
int main(){
	int n,i,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		cnt[x]++;
	}
	dp[0]=0;
	dp[1]=0;
	for(i=2;i<N;i++){
		dp[i]=max(dp[i-2]+1LL*(i-1)*cnt[i-1],dp[i-1]);
	}
	printf("%I64d\n",dp[N-1]);
	return 0;
}