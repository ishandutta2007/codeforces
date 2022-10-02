#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10005];
int dp[105][105][2];
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
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			cnt1+=(a[i]&1);
			cnt2+=!(a[i]&1);
		}
		memset(dp,0,sizeof dp);
		dp[0][0][1]=0,dp[0][0][0]=1;
		for(int i=0;i<=cnt1;i++)
		{
			for(int j=!i;j<=cnt2;j++)
			{
				for(int k=0;k<2;k++)
				{
					if(i+j+n&1)//bob
					{
						if((i&&!dp[i-1][j][k])||(j&&!dp[i][j-1][k]))
							dp[i][j][k]=0;
						else dp[i][j][k]=1;
					}
					else//alice
					{
						if((i&&dp[i-1][j][k^1])||(j&&dp[i][j-1][k]))
							dp[i][j][k]=1;
						else dp[i][j][k]=0;
					}
				}
			}
		}
		if(dp[cnt1][cnt2][0]) cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}