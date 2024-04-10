#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N=110;


string s;
ll n;
bool dp[2][2*N][N][N/2];


int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>n;
	dp[0][N][0][0]=1;
	for(int i=1;i<=s.size();i++)
	{
		for(int j=0;j<2*N;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(s[i-1]=='T')
				{
					dp[0][j][i][k]=dp[1][j][i-1][k];dp[1][j][i][k]=dp[0][j][i-1][k];
					if(k && j)dp[0][j][i][k]|=dp[0][j-1][i-1][k-1];
					if(k && j<2*N-1)dp[1][j][i][k]|=dp[1][j+1][i-1][k-1];
				}
				else
				{
					if(k)dp[0][j][i][k]=dp[1][j][i-1][k-1],dp[1][j][i][k]=dp[0][j][i-1][k-1];
					if(j)dp[0][j][i][k]|=dp[0][j-1][i-1][k];
					if(j<2*N-1)dp[1][j][i][k]|=dp[1][j+1][i-1][k];
				}
			}
		}
	}
	ll maxi=0;
	for(int i=0;i<2*N;i++)
	{
		ll res=0;
		for(int j=n;j>=0;j-=2)res|=(dp[0][i][(ll)s.size()][j] || dp[1][i][(ll)s.size()][j]);
		if(abs(i-N)>maxi && res)
			maxi=abs(i-N);
	}
		
	cout<<maxi;
	return 0;
}