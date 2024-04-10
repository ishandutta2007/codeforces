#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (4444)

ll t,n,p;
string s[3];


int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		bool mark[3][N]={},dp[3][N]={};
		cin>>n>>p>>s[0]>>s[1]>>s[2];
		s[0]+=".....",s[1]+=".....",s[2]+=".....";
		dp[0][0]=(s[0][0]=='s'),dp[1][0]=(s[1][0]=='s'),dp[2][0]=(s[2][0]=='s');		
		for(int i=3;i<=n+3;i+=3)
		{
			dp[0][i]=((s[0][i]=='.' && s[0][i-1]=='.' && s[0][i-2]=='.') && ((dp[1][i-3] && s[1][i-2]=='.') || dp[0][i-3]));
			dp[2][i]=((s[2][i]=='.' && s[2][i-1]=='.' && s[2][i-2]=='.') && ((dp[1][i-3] && s[1][i-2]=='.') || dp[2][i-3]));
			dp[1][i]=((s[1][i]=='.' && s[1][i-1]=='.' && s[1][i-2]=='.') && (dp[1][i-3] || (dp[0][i-3] && s[0][i-2]=='.') || (dp[2][i-3] && s[2][i-2]=='.')));
		}
		/*
		for(int i=0;i<=n+3;i+=3)
			cout<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<"\n";
		*/
		cout<<((dp[0][(n+1)/3*3] || dp[1][(n+1)/3*3] || dp[2][(n+1)/3*3])?"YES":"NO")<<"\n";
	}
    return 0;
}