#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)2001*1000)
#define K ((ll)30)
#define MOD ((ll)1e9+7)

ll n,k,last[K],dp[N],_last[K];
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>s;n+=(ll)s.size();
	dp[0]=1;
	for(int i=0;i<K;i++)last[i]=-1;
	for(int i=1;i<=s.size();i++)
	{
		dp[i]=2*dp[i-1]-((last[s[i-1]-'a']!=-1)?dp[last[s[i-1]-'a']]:0);dp[i]%=MOD;dp[i]+=MOD;dp[i]%=MOD;
		last[s[i-1]-'a']=i-1;
	}
	for(int i=0;i<k;i++)_last[i]=last[i];
	sort(_last,_last+k);
	ll p=s.size()+1;
	while(p<=n)
	{
		for(int i=0;p<=n && i<k;i++)
		{
			dp[p]=2*dp[p-1]-((_last[i]!=-1)?dp[_last[i]]:0);dp[p]%=MOD;dp[p]+=MOD;dp[p]%=MOD;
			_last[i]=p-1;
			p++;
		}	
	}
	cout<<dp[n];
	return 0;
}