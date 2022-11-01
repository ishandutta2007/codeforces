#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (1111)
#define K (11)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,k,a[K][N],dp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)dp[i]=1;			
	for(int i=n-1;i>=0;i--)
	{
		bool cnt[K][N]={};
		for(int j=1;j<k;j++)
		{
			for(int p=n-1;p>=0 && a[j][p]!=a[0][i];p--)
				cnt[j][a[j][p]]=1;
		}
		for(int j=i+1;j<n;j++)
		{
			bool m=1;
			for(int p=1;p<k;p++)
				if(!cnt[p][a[0][j]])
					m=0;
			if(m)dp[a[0][i]]=max(dp[a[0][i]],dp[a[0][j]]+1);		
		}	
	}		
	ll ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	cout<<ans;
    return 0;
}