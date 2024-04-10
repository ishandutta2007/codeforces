#include<bits/stdc++.h>
using namespace std;
int a[105],dp[105][105][2],p[105][105][2];
void vist(int n,int hf,int f)
{
	if(n==1)
	{
		if(f)printf("%d",-a[1]);
		else printf("%d",a[1]);
		return;
	}
	int pf=p[n][hf][f];
	int ppf,pppf;
	if(f==0)ppf=1;
	else ppf=-1;
	if(pf==0)pppf=1;
	else pppf=-1;
	int cz=a[n]*ppf-a[n-1]*pppf;
	if(cz>=0&&dp[n-1][hf-1][pf])vist(n-1,hf-1,pf);
	else vist(n-1,hf,pf);
	if(f)printf(" %d",-a[n]);
	else printf(" %d",a[n]);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(p,0,sizeof(p));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		dp[1][0][0]=dp[1][0][1]=1;
		for(int i=2;i<=n;i++)for(int j=0;j<i;j++)
		{
			if(j==0)
			{
				int cz1=a[i]-a[i-1],cz2=a[i]+a[i-1];
				if(cz1<=0&&dp[i-1][j][0])
					dp[i][j][0]=1,p[i][j][0]=0;
				else if(cz2<=0&&dp[i-1][j][1])
					dp[i][j][0]=1,p[i][j][0]=1;
				cz1=-a[i]-a[i-1],cz2=a[i-1]-a[i];
				if(cz1<=0&&dp[i-1][j][0])
					dp[i][j][1]=1,p[i][j][1]=0;
				else if(cz2<=0&&dp[i-1][j][1])
					dp[i][j][1]=1,p[i][j][1]=1;
				continue;
			}
			int cz1=a[i]-a[i-1],cz2=a[i]+a[i-1];
			if((cz1>=0&&dp[i-1][j-1][0])||(cz1<=0&&dp[i-1][j][0]))
				dp[i][j][0]=1,p[i][j][0]=0;
			else if((cz2>=0&&dp[i-1][j-1][1])||(cz2<=0&&dp[i-1][j][1]))
				dp[i][j][0]=1,p[i][j][0]=1;
			cz1=-a[i]-a[i-1],cz2=a[i-1]-a[i];
			if((cz1>=0&&dp[i-1][j-1][0])||(cz1<=0&&dp[i-1][j][0]))
				dp[i][j][1]=1,p[i][j][1]=0;
			else if((cz2>=0&&dp[i-1][j-1][1])||(cz2<=0&&dp[i-1][j][1]))
				dp[i][j][1]=1,p[i][j][1]=1;
		}
		int hf=n>>1;
		if(dp[n][hf][0])vist(n,hf,0);
		else vist(n,hf,1);
		puts("");
	}
	return 0;
}