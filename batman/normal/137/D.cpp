#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (555)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

string s;
ll k;
pair <ll,ll> dp[N][N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>k;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]={INF,INF};
	dp[s.size()][0]={0,INF};
	for(int i=s.size()-1;i>=0;i--)
	{
		for(int j=i;j<s.size();j++)
		{
			ll num=0;
			for(int k1=i,k2=j;k1<k2;k1++,k2--)
				num+=(s[k1]!=s[k2]);
			for(int k1=1;k1<=k;k1++)
				if(num+dp[j+1][k1-1].first<dp[i][k1].first)
					dp[i][k1]={num+dp[j+1][k1-1].first,j+1};	
		}
	}
	ll ans=INF;
	bool mark[N]={};
	for(int i=1;i<=k;i++)
		ans=min(ans,dp[0][i].first);
	for(int i=1;i<=k;i++)
		if(dp[0][i].first==ans)
		{
			ll ex=dp[0][i].second,p=i;
			while(ex!=INF)
				mark[ex]=1,ex=dp[ex][--p].second;	
			break;	
		}
	cout<<ans<<"\n";
	string res="";	
	for(int i=0;i<s.size();i++)
	{
		if(mark[i])
			res+='+';
		res+=s[i];	
	}
	ll l=0;
	for(int i=0;i<res.size();i++)
		if(res[i]=='+')
		{
			ll l1=l,r1=i-1;
			for(;l1<r1;l1++,r1--)
				if(res[l1]!=res[r1])
					res[r1]=res[l1];
			l=i+1;	
		}
	ll l1=l,r1=res.size()-1;
	for(;l1<r1;l1++,r1--)
		if(res[l1]!=res[r1])
			res[r1]=res[l1];		
	cout<<res;	
    return 0;
}