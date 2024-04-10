#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,suma;
double sumb,gjr,tooler,res;
struct point
{
	int a,b;
}q[109];
int dp[109][10009];
double ans;
int main()
{
	memset(dp,-1,sizeof(dp));
	n=read();
	for(int i=1;i<=n;i++)q[i].a=read(),q[i].b=read(),suma+=q[i].a,sumb+=q[i].b;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
			for(int k=suma;k>=q[i].a;k--)
				{
					if(dp[j-1][k-q[i].a]+q[i].b>dp[j][k]&&dp[j-1][k-q[i].a]!=-1)
					{
						//cout<<j-1<<" "<<k-q[i].a<<" "<<dp[j-1][k-q[i].a]<<" "<<q[i].b<<endl;
						dp[j][k]=dp[j-1][k-q[i].a]+q[i].b;
					}
				}
	//for(int i=1;i<=n;i++)
		//for(int j=0;j<=suma;j++)
			//if(dp[i][j]!=-1)cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=0;j<=suma;j++)
		{
			gjr=j,tooler=dp[i][j];
			if(tooler!=-1)ans=max(ans,min(gjr,sumb/2*1.0+(double)dp[i][j]/2*1.0));
		}
		printf("%.12lf ",ans);
	}
	return 0;
}