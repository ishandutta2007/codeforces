#include <bits/stdc++.h>
using namespace std;
int dp[60][200005],x[200005],y[200005],flag[200005],f[200005];
signed main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
		cin >> x[i] >> y[i];
	for(int i=0;i<=58;i++)
		for(int j=0;j<=200000;j++) dp[i][j]=-1e9;
	dp[0][0]=1,dp[0][1]=1;
	for(int i=1;i<=58;i++)
	{
		memset(flag,0,sizeof flag);
		for(int j=1;j<=q;j++)
		{
			if(dp[i-1][x[j]]==y[j])
				flag[x[j]]=1;
		}
		for(int j=0;j<=n;j++)
		{
			if(dp[i-1][j]>=0)
			{
				dp[i][min(n,dp[i-1][j]+j+flag[j])]=max(dp[i][min(n,dp[i-1][j]+j+flag[j])],dp[i-1][j]);
				dp[i][j]=max(dp[i][j],min(dp[i-1][j]+j+flag[j],m));
			}
			else break;
		}
		for(int j=n-1;j>=0;j--) dp[i][j]=max(dp[i][j],dp[i][j+1]);
	}
	int ans=1e9;
	for(int i=58;i>=0;i--)
		if(dp[i][n]>=m) ans=i;
		
	memset(flag,0,sizeof flag);
	for(int i=1;i<=q;i++)
		if(y[i]==m) flag[x[i]]=1;
	for(int i=0;i<=200000;i++) f[i]=1e9;
	for(int i=58;i>=0;i--)
		for(int j=1;j<=n;j++)
			if(dp[i][j]>=m) f[j]=i;
	for(int i=0;i<=200000;i++)
	{
		int nxt=min(n,i+m+flag[i]);
		f[nxt]=min(f[nxt],f[i]+1);
	}
	ans=min(ans,f[n]);
	
	memset(flag,0,sizeof flag);
	for(int i=1;i<=q;i++)
		if(x[i]==n) flag[y[i]]=1;
	for(int i=0;i<=200000;i++) f[i]=1e9;
	for(int i=58;i>=0;i--)
		if(dp[i][n]>=0) f[dp[i][n]]=i;
	for(int i=0;i<=200000;i++)
	{
		int nxt=min(m,i+n+flag[i]);
	//		cout << i << " " << nxt << "*\n";
		f[nxt]=min(f[nxt],f[i]+1);
	}
	cout << min(ans,f[m]);
	return 0;
}
/*
2 200000
8
2 12
2 15
2 18
2 21
2 24
2 27
2 30
2 33
*/