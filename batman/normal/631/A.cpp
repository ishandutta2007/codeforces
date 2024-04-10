#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1100)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,a[N],b[N],dp[2][N][N],ans;

int main()
{ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)dp[0][i][i]=a[i],dp[1][i][i]=b[i],ans=max(ans,dp[0][i][i]+dp[1][i][i]);
    for(int t=2;t<=n;t++)
    	for(int i=0;i+t-1<n;i++)
    	{
    		ll j=i+t-1;
    		dp[0][i][j]=dp[0][i][j-1]|a[j];
    		dp[1][i][j]=dp[1][i][j-1]|b[j];
    		ans=max(ans,dp[0][i][j]+dp[1][i][j]);
		}
	cout<<ans;
    return 0;
}