#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)4001)
#define SQ ((ll)88)
#define INF ((ll)1e9)

ll n,a[N],prt[N],dp[N][2*SQ+2][SQ][2];
bitset <N> mark[2*SQ+2][SQ][2];

ll solve(ll l,ll x,ll k,bool move)
{
	if(mark[x+SQ][k][move][l])return dp[l][x+SQ][k][move];
	ll r=(n+1)-(l+x);
	if(!move)
	{
		if(l+k<=r+1)dp[l][x+SQ][k][move]=solve(l+k,(x-k),k,1-move)+prt[l+k-1]-prt[l-1];
		if(l+k+1<=r+1)dp[l][x+SQ][k][move]=max(dp[l][x+SQ][k][move],solve(l+k+1,(x-k-1),k+1,1-move)+prt[l+k]-prt[l-1]);
		mark[x+SQ][k][move][l]=1;
		return dp[l][x+SQ][k][move];
	}
	if(l+k<=r+1)dp[l][x+SQ][k][move]=solve(l,(x+k),k,1-move)-prt[r]+prt[r-k];
	if(l+k+1<=r+1)dp[l][x+SQ][k][move]=min(dp[l][x+SQ][k][move],solve(l,(x+k+1),k+1,1-move)-prt[r]+prt[r-k-1]);
	mark[x+SQ][k][move][l]=1;
	return dp[l][x+SQ][k][move];
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],prt[i]=a[i]+prt[i-1];
	cout<<solve(1,0,1,0);
    return 0;
}