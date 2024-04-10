#include<bits/stdc++.h>
using namespace std;
char s[200005];
int dp[200005][11],ss[200005],f[11][200005],tt[11];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++)ss[i]=s[i]-'0';
		for(int i=0;i<10;i++)f[i][0]=0;
		memset(dp[1],0,sizeof(dp[1]));
		f[ss[1]][++f[ss[1]][0]]=1;
		for(int i=2;i<=n;i++)
		{
			memset(dp[i],0,sizeof(dp[i]));
			for(int j=0;j<10;j++)
			{
				if(!f[j][0])
				{
					dp[i][j]=0;
					continue;
				}
				int wz=lower_bound(f[ss[i]]+1,f[ss[i]]+f[ss[i]][0]+1,f[j][f[j][0]])-f[ss[i]]-1;
				if(!wz)
				{
					dp[i][j]=2;
					continue;
				}
				dp[i][j]=dp[f[ss[i]][wz]][j]+2;
			}
			f[ss[i]][++f[ss[i]][0]]=i;
		}
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=0;j<10;j++)ans=max(ans,dp[i][j]);
		memset(tt,0,sizeof(tt));
		for(int i=1;i<=n;i++)tt[ss[i]]++;
		for(int i=0;i<10;i++)ans=max(ans,tt[i]);
		cout<<n-ans<<endl;
	}
	
	return 0;
}