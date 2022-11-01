#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (111)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll dp[N*N],cnt[N][N][N],m;

void solve(ll a[],ll n)
{
	
	//cout<<"HIR";
	for(int t=1;t<=n;t++)
		for(int i=0;i+t-1<n;i++)
			for(int j=1;j<=t;j++)
				cnt[i][i+t-1][j]=max(cnt[i][i+t-2][j-1]+a[i+t-1],cnt[i+1][i+t-1][j-1]+a[i]);
	//cout<<"HIR";			
	for(int i=m;i>=0;i--)
	{
		for(int j=1;j<=n && i>=j;j++)
			dp[i]=max(dp[i-j]+cnt[0][n-1][j],dp[i]);	
	}			
	
	
}

int main()
{
	ll n,a[N][N]={},p,sum=0,p_all;
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		p_all+=p;
		for(int j=0;j<p;j++)
			cin>>a[i][j],sum+=a[i][j];
		//cout<<"HIR";	
		solve(a[i],p);	
	}
	if(p_all<=m)
		return cout<<sum,0;
	cout<<dp[m];
	
		
    return 0;
}