#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (1100)

ll n,m,a,b,c,d,dp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>c>>d;
	for(int i=c;i<N;i+=c)
		dp[i]=(i/c)*d;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c>>d;
		ll ex=a/b;
		for(int j=n;j>=0;j--)
			for(int k=1;j+k*c<=n && k<=ex;k++)
				dp[j+k*c]=max(dp[j+k*c],dp[j]+d*k);
	}	
	ll ans=0;
	for(int i=n;i>=0;i--)
		ans=max(ans,dp[i]);
	cout<<ans;	
    return 0;
}