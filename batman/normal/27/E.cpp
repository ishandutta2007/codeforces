#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1010)
#define INF ((ll)2e18)
#define K (14)

ll n,dp[K][N],a[K]={1,2,3,5,7,11,13,17,19,23,29,31,37,41};

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<K;i++)for(int j=0;j<N;j++)dp[i][j]=INF;
	for(int i=0;i<K;i++)dp[i][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<K;j++)
		{
			dp[j][i]=dp[j-1][i];
			for(ll k=2,p=a[j];INF/a[j]>p;k++,p*=a[j])
				if(i%k==0)
					if(INF/p>dp[j-1][i/k])
						dp[j][i]=min(dp[j][i],p*dp[j-1][i/k]);
		}
	cout<<dp[K-1][n];		
				
    return 0;
}