#include<cstdio>
#include<cstdlib>
int N;
long long dp[51];
int ans[51];
void bktk(int C,long long K)
{
	if(C==N+1)
	{
		//assert K==1LL
		for(int i=1;i<=N;i++)
			printf("%d ",ans[i]);
		exit(0);
	}
	if(C==N)
	{
		//assert K==1LL
		ans[C]=C;
		bktk(C+1,K);
		return;
	}
	if(C==N-1)
	{
		if(K==1LL)
		{
			ans[C]=C;
			ans[C+1]=C+1;
			bktk(C+2,K);
			return;
		}
		else
		{
			ans[C]=C+1;
			ans[C+1]=C;
			bktk(C+2,1);
			return;
		}
	}
	if(K<=dp[C+1])
	{
		ans[C]=C;
		bktk(C+1,K);
	}
	else
	{
		ans[C]=C+1;
		ans[C+1]=C;
		bktk(C+2,K-dp[C+1]);
	}
	return;
}
int main()
{
	long long K;
	scanf("%d%lld",&N,&K);
	dp[N]=1;
	dp[N-1]=2;
	for(int i=N-2;i>=1;i--)
	{
		dp[i]=dp[i+1]+dp[i+2];
	}
	bktk(1,K);
}