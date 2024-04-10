#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)10*1001)
#define INF ((ll)1e18)

ll n,c,p[N],s[N],dp[2][N];

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>s[i],dp[0][i]=dp[1][i]=INF;
	dp[1][0]=INF;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			dp[(i&1)][j]=min(j?s[i]+dp[!(i&1)][j-1]:INF,p[i]+dp[!(i&1)][j]+c*j);
			
	for(int i=1;i<=n;i++)dp[(n&1)][i]=min(dp[(n&1)][i],dp[(n&1)][i-1]);
	cout<<dp[(n&1)][n]<<"\n";
	return 0;
}