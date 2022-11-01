#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)2100)

ll n,A,B;
ld a[N],b[N];
pair <ld,ll> dp[N][N];

bool check(ld x)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=A;j++)
		{
			pair <ld,ll> ex;
			dp[i][j]=dp[i-1][j];
			
			ex={dp[i-1][j-1].first+a[i],dp[i-1][j-1].second};
			if(j && ex>dp[i][j])dp[i][j]=ex;
			
			ex={dp[i-1][j].first+b[i]-x,dp[i-1][j].second-1};
			if(ex>dp[i][j])dp[i][j]=ex;
			
			ex={dp[i-1][j-1].first+a[i]+b[i]-a[i]*b[i]-x,dp[i-1][j-1].second-1};
			if(j && ex>dp[i][j])dp[i][j]=ex;
		}
	return (-dp[n][A].second>=B);
}

int main()
{
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	ld l=0,r=2;
	for(int i=0;i<60;i++)
	{
		ld mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	check(l);
	cout<<fixed<<setprecision(14)<<(ld)dp[n][A].first+(ld)B*l<<"\n";
	return 0;
}