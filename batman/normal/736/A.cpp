#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}


ll n,dp[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	dp[0]=1;
	dp[1]=2;
	if(n==2)return cout<<1,0;
	for(int i=2;;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
		if(n-dp[i-1]<dp[i-2])return cout<<i-1<<"\n",0;
	}
	return 0;
}