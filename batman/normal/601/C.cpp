#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=((n&1)?a:1ll),res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101;
const ll M=1001;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)1e9);

ll n,m,sum;
ld dp[2][N*M];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	dp[1][0]=m-1;
	if(m==1)return cout<<1,0;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;sum+=x;
		bool p=(i&1);
		for(int j=0;j<N*M;j++)dp[p][j]=0;
		for(int j=0;j<N*M;j++)
		{
			ld ex=dp[!p][j]/(ld)(m-1);
			if(j+1<N*M)dp[p][j+1]+=ex;
			if(j+x<N*M)dp[p][j+x]-=ex;
			if(j+x+1<N*M)dp[p][j+x+1]+=ex;
			if(j+m+1<N*M)dp[p][j+m+1]-=ex;
			if(j)dp[p][j]+=dp[p][j-1];
		}
	}
	ld ans=0;
	for(int i=0;i<sum;i++)ans+=dp[!(n&1)][i];
	cout<<fixed<<setprecision(14)<<ans+1;
  	return 0;
}