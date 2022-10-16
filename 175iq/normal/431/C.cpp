#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

int main()
{
	int n,k,d;
	cin>>n;
	cin>>k;
	cin>>d;
	std::vector<std::vector<int> > dp(n+1,std::vector<int> (2,0));
	dp[0][0]=1;
	dp[0][1]=0;

	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 1; j <=k ; ++j)
		{
			if(i-j<0)
			{
				break;
			}

			if(j<d)
			{
				dp[i][0] = (dp[i][0] + dp[i-j][0])%MOD ; 
				dp[i][1] = (dp[i][1] + dp[i-j][1])%MOD ; 
			}
			else
			{
				dp[i][1] = (dp[i][1] + dp[i-j][1])%MOD ;
				dp[i][1] = (dp[i][1] + dp[i-j][0])%MOD ;
			}
		}
	}
	cout<<dp[n][1];
	return 0;
}