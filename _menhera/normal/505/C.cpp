#include<cstdio>
//#include<map>
#include<queue>
using namespace std;
//map<pair<int,int>,int> dp;
int dp[30010][2100];
priority_queue<pair<int,int> >Q;
int gems[40000];
int N,D;
int bktk(int a,int b)
{
	if(a>30000 || b==0) return 0;
	return gems[a]+max(max(bktk(a+b,b),bktk(a+b+1,b+1)),bktk(a+b-1,b-1));
}
int main()
{
	scanf("%d%d",&N,&D);
	for(int i=0;i<N;i++)
	{
		int t;
		scanf("%d",&t);
		gems[t]++;
	}
	if(D>2020)
	{
		printf("%d",bktk(D,D));
		return 0;
	}
	int maxv=gems[D]+1;
	dp[D][D]=gems[D]+1;
	for(int i=D+1;i<=30000;i++)
	{
		//if(i%10==0) printf("%d",i);
		for(int j=1;j<2050;j++)
		{
			if(i-j<0) break;
			dp[i][j]=0;
			if(dp[i-j][j-1]) dp[i][j]=dp[i-j][j-1];
			if(dp[i-j][j]) dp[i][j]=max(dp[i][j],dp[i-j][j]);
			if(dp[i-j][j+1]) dp[i][j]=max(dp[i][j],dp[i-j][j+1]);
			if(dp[i][j]>0) dp[i][j]+=gems[i];
			maxv=max(maxv,dp[i][j]);
			//printf("%d",dp[i][j]);
		}
	}
	printf("%d",maxv-1);
}