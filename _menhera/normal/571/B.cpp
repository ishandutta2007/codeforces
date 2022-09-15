






#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int A[303030];
int dp[5050][5050];
int N,K;
int bktk(int a,int b)
{
	if(dp[a][b]!=-1) return dp[a][b];
	int ans=0x7ffffff0;
	if(a>0) ans= bktk(a-1,b) + A[a*(N/K+1)+b*(N/K)-1]-A[(a-1)*(N/K+1)+b*(N/K)];
	if(b>0) ans= min(ans,bktk(a,b-1)+A[a*(N/K+1)+b*(N/K)-1]-A[a*(N/K+1)+(b-1)*(N/K)]);
	return dp[a][b]=ans;
}
int main()
{
	scanf("%d%d",&N,&K );
	for(int i=0;i<N;i++) scanf("%d",A+i);
	sort(A,A+N);
	//dp[i][j] first one N/K+1, second one N/K ( N%K, K-N%K) each get maxv
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	printf("%d",bktk(N%K,K-N%K) );
}