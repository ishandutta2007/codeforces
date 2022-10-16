#include<cstdio>
typedef double db;
db dp[1111];
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(register int i=n,ii;i;i--)
		for(ii=1;ii<=1000;ii++)
		{
			int a=k*(ii+1);
			dp[ii]=(dp[ii]*(a-1)+(ii+1)*.5*ii+(dp[ii+1]+ii))/a;
		}
	printf("%.12lf\n",dp[1]*k);
}