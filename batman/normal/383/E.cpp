#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define K ((ll)24)

int n,dp[(1<<K)];
ll ans;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x=0;
		for(int j=0;j<3;j++)
		{
			char c;cin>>c;
			x|=(1<<(c-'a'));
		}
		dp[x]++;
	}
	for(int i=0;i<K;i++)
		for(int j=0;j<(1<<K);j++)
			if((j&(1<<i)))
				dp[j]+=dp[j-(1<<i)];
	for(int i=0;i<(1<<K);i++)ans^=(n-dp[i])*(n-dp[i]);
	cout<<ans;
	return 0;
}