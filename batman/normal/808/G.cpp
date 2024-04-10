#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)

ll n,m,nex[26][N],par[N],dp[2][N];
string s,t;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s>>t;
	n=s.size();m=t.size();
	nex[t[0]-'a'][0]=1;
	for(int i=1;i<=m;i++)
	{
		if(i>1)par[i]=nex[t[i-1]-'a'][par[i-1]];
		for(int j=0;j<26;j++)
		{
			if(i!=m && t[i]-'a'==j)nex[j][i]=i+1;
			else nex[j][i]=nex[j][par[i]];
		}
	}
	for(int i=0;i<=m;i++)dp[0][i]=-N;
	if(s[0]==t[0] || s[0]=='?')dp[0][1]=0;
	if(s[0]!=t[0])dp[0][0]=0;
	for(int i=0;i<n-1;i++)
	{
		bool p=(i&1);
		for(int j=0;j<=m;j++)dp[!p][j]=-N;
		for(int j=0;j<=m;j++)
		{
			if(j==m)dp[p][j]++;
			if(s[i+1]=='?')
			{
				for(int k=0;k<26;k++)
					dp[!p][nex[k][j]]=max(dp[!p][nex[k][j]],dp[p][j]);
				continue;
			}
			dp[!p][nex[s[i+1]-'a'][j]]=max(dp[!p][nex[s[i+1]-'a'][j]],dp[p][j]);;
		}
	}
	ll ans=0;
	dp[!(n&1)][m]++;
	for(int i=0;i<=m;i++)ans=max(ans,dp[!(n&1)][i]);
	cout<<ans;
	return 0;
}