#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;
const int MOD=1e9+7;

int n, k, m;
string s;
int dp[2*N], prv[256];

int32_t main()
{
	IOS;
	memset(prv, -1, sizeof(prv));
	cin>>n>>k>>s;
	m=s.size();
	dp[0]=1;
	for(int i=1;i<=m;i++)
	{
		dp[i]=dp[i-1]*2;
		if(prv[s[i-1]]!=-1)
			dp[i]-=dp[prv[s[i-1]]];
		dp[i]+=MOD;
		dp[i]%=MOD;
		prv[s[i-1]]=(i-1);
	}
	for(int i=1;i<=n;i++)
	{
		int minidx=1e9, minsub= 1e9, ch2='?';
		for(char ch='a';ch<='a'+k-1;ch++)
		{
			if(prv[ch]==-1 || prv[ch]<minidx)
			{
				if(prv[ch]==-1)
				{
					minidx=prv[ch];
					minsub=0;
					ch2=ch;
				}
				else
				{
					minidx=prv[ch];
					minsub=dp[prv[ch]];
					ch2=ch;
				}
			}
		}
		prv[ch2]=m+i-1;	
		dp[m+i]=(dp[m+i-1]*2-minsub+MOD)%MOD;
	}
	cout<<dp[m+n];
	return 0;
}