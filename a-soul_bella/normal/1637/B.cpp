#include <bits/stdc++.h>
#define int long long
using namespace std;
int mex[105][105],vis[105],a[105],dp[105][105];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]>100) a[i]=102;
		}
		for(int i=1;i<=n;i++)
		{
			int x=0;
			memset(vis,0,sizeof vis);
			for(int j=1;j<=n;j++)
			{
				vis[a[j]]=1;
				while(vis[x]) ++x;
				mex[i][j]=x+1;
			}
		}
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++)
			dp[i][i]=mex[i][i];
		int ans=0;
		for(int len=2;len<=n;len++)
		{
			for(int l=1;l+len-1<=n;l++)
			{
				int r=l+len+1;
				for(int k=l;k<=r;k++)
					dp[l][r]=max(dp[l][r],mex[l][k]+dp[k+1][r]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			int cnt0=0;
			for(int j=i;j<=n;j++)
			{
				cnt0+=a[j]==0;
				ans+=j-i+1+cnt0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}