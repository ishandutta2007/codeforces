#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)8010)

ll n,dp[N],cnt[N],f[N];
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;s="."+s;
	n=(ll)s.size()-1;
	for(int i=1,j=1,k=10;i<N;i++)
	{
		if(i==k)j++,k*=10;
		cnt[i]=j;
	}
	for(int i=1;i<=n;i++)dp[i]=1e9;
	for(int i=0;i<n;i++)
	{
		dp[i+1]=min(dp[i+1],dp[i]+2);
		f[i+1]=i;
		for(int j=i+2,k=i;j<=n;j++)
		{
			while(k>i && s[k+1]!=s[j])k=f[k];
			if(s[k+1]==s[j])k++,f[j]=k;
			else f[j]=i;
			if((j-i)%(j-f[j])==0)dp[j]=min(dp[j],dp[i]+cnt[(j-i)/(j-f[j])]+(j-f[j]));
			dp[j]=min(dp[j],dp[i]+1+(j-i));
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}