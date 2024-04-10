#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)51)

ll n,dp[N][3][3],t[3][3];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>t[i][j];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			ll p=0;
			while(p==i || p==j)p++;
			dp[1][i][j]=min(t[i][j],t[i][p]+t[p][j]);
		}
			
	cin>>n;
	for(int k=2;k<=n;k++)
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i!=j)
				{
					ll p=0;
					while(p==i || p==j)p++;
					dp[k][i][j]=min(dp[k-1][i][p]+t[i][j]+dp[k-1][p][j],dp[k-1][i][j]+t[i][p]+dp[k-1][j][i]+t[p][j]+dp[k-1][i][j]);
					//cout<<k<<" "<<i<<" "<<j<<" "<<dp[k][i][j]<<"\n";
				}
	cout<<dp[n][0][2];
	return 0;
}