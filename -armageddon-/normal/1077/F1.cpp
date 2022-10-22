#include <bits/stdc++.h>
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define all(A) A.begin(),A.end()
const int inf=1018181818;
using namespace std;
ll dp[205][205][205];//pos, used, gap.
int n,k,x;
int a[205];

int main()
{
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			for(int k=0;k<200;k++)
			{
				dp[i][j][k]=-1LL*inf*inf;
			}
		}
	}
//	memset(dp,-1,sizeof(dp));
	dp[0][0][1]=0;
	dp[0][1][0]=a[0];
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<=x;j++)
		{
			for(int o=0;o<k;o++)
			{
				dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][o]+a[i+1]);
				dp[i+1][j][o+1]=max(dp[i+1][j][o+1],dp[i][j][o]);
//				cout<<dp[i][j][o]<<endl;
			}
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<=x;j++)
//		{
//			for(int o=0;o<k;o++)
//			{
//				cout<</*i<<' '<<j<<' '<<o<<' '<<*/dp[i][j][o]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//	cout<<dp[4][3][1]<<endl;
	ll res=-1;
	for(int j=0;j<=x;j++)
	{
		for(int o=0;o<k;o++)
		{
//			cout<<n-1<<' '<<j<<' '<<k<<endl;
//			cout<<dp[n-1][j][o]<<endl;
			res=max(res,dp[n-1][j][o]);
		}
	}
	cout<<res<<endl;
	return 0;
}