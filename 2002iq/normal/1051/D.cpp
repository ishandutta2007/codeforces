#include <iostream>
using namespace std;
#define mod 998244353
int dp[1005][2005][4];
int main()
{
	int n,x;
	cin >> n >> x;
	dp[1][1][0]=1;
	dp[1][2][1]=1;
	dp[1][2][2]=1;
	dp[1][1][3]=1;
	for (int i=2;i<=n;i++)
	{
		for (int k=1;k<=2*i;k++)
		{
			for (int m=0;m<4;m++)
			{
				for (int l=0;l<4;l++)
				{
					int c=2;
					if (m%2==l%2)
					c--;
					if (m/2==l/2)
					c--;
					if (m%2==m/2)
					c--;
					c=max(c,0);
					if (c<=k)
					dp[i][k][m]=(dp[i][k][m]+dp[i-1][k-c][l])%mod;
				}
			}
		}
	}
	int ans=0;
	for (int m=0;m<4;m++)
	ans=(ans+dp[n][x][m])%mod;
	cout << ans;
}