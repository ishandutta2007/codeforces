#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define INF ((ll)1e9)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,dp[2][3][N];
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	dp[s[0]-'0'][0][0]=1;
	dp[1-(s[0]-'0')][1][0]=1;
	for(int i=1;i<n;i++)
	{
		dp[s[i]-'0'][0][i]=max(dp[1-(s[i]-'0')][0][i-1]+1,dp[s[i]-'0'][0][i-1]);
		dp[1-(s[i]-'0')][0][i]=dp[1-(s[i]-'0')][0][i-1];
		dp[1-(s[i]-'0')][1][i]=max(max(dp[s[i]-'0'][0][i-1]+1,dp[s[i]-'0'][1][i-1]+1),max(dp[1-(s[i]-'0')][1][i-1],dp[1-(s[i]-'0')][0][i-1]));
		dp[s[i]-'0'][1][i]=max(dp[s[i]-'0'][1][i-1],dp[s[i]-'0'][0][i-1]);
		dp[s[i]-'0'][2][i]=max(dp[1-(s[i]-'0')][1][i-1]+1,max(dp[s[i]-'0'][1][i-1],max(dp[s[i]-'0'][2][i-1],dp[1-(s[i]-'0')][2][i-1]+1)));
		dp[1-(s[i]-'0')][2][i]=max(dp[1-(s[i]-'0')][1][i-1],dp[1-(s[i]-'0')][2][i-1]);
	}
	cout<<max(dp[0][0][n-1],max(dp[0][1][n-1],max(dp[0][2][n-1],max(dp[1][0][n-1],max(dp[1][1][n-1],dp[1][2][n-1])))));
    return 0;
}