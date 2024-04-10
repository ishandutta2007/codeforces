#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)51*1000)
#define K ((ll)2700)

string s;
ll n,cnt[26];
ll dp[K][K];


ll maxi=1;
bool hund=0;
pair <ll,ll> id,id2;
string ans;

void solve(ll x,ll y)
{
	if(x>y)return ;
	if(s[x]==s[y])
	{
		ans+=s[x];
		solve(x+1,y-1);
		return ;
	}
	if(dp[x][y]==dp[x+1][y])
	{
		solve(x+1,y);
		return ;
	}
	solve(x,y-1);
}

int main() {
   	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>s;
   	ll n=s.size();
   	if(s.size()<K)
   	{
   		for(int i=0;i<n;i++)
   		{
   			dp[i][i]=1;
   			if(i)
			{
			 	dp[i-1][i]=1+(s[i]==s[i-1]);
				if(dp[i-1][i]>maxi)maxi=dp[i-1][i],id2={i-1,i};  	
			}
		}
		for(int t=3;t<=n;t++)
		{
			for(int i=0;i+t-1<n;i++)
			{
				ll j=i+t-1;
				if(s[i]==s[j])dp[i][j]=2+dp[i+1][j-1];
				else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
				if(dp[i][j]==100 || dp[i][j]==101)hund=1,id={i,j};
				if(dp[i][j]>maxi)maxi=dp[i][j],id2={i,j};
			}
		}
		if(hund)
		{
			solve(id.first,id.second);
			for(int i=0;i<50;i++)cout<<ans[i];
			for(int i=49;i>=0;i--)cout<<ans[i];
			return 0;
		}
		solve(id2.first,id2.second);
		cout<<ans;
		if(maxi%2==0)cout<<ans[(ll)ans.size()-1];
		for(int i=(ll)ans.size()-2;i>=0;i--)cout<<ans[i];
		return 0;
	}
	for(int i=0;i<n;i++)cnt[s[i]-'a']++;
	for(int i=0;i<26;i++)
		if(cnt[i]>=100)
		{
			for(int j=0;j<100;j++)cout<<((char)(i+'a'));
			return 0;
		}
    return 0;
}