#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define MOD ((ll)1e9+7)

ll n,dp[N],prt[N],id[N];
bool mark[N];

int main()
{
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		vector <ll> v;
		for(int j=2;;j++)
		{
			ll ex=j*(j+1)/2;
			if(ex>i)break;
			if((i-ex)%j)continue;
			ll num=(i-ex)/j;
			ex=(prt[num+j]^prt[num]);
			if(!ex && !id[i])id[i]=j;
			mark[ex]=1;v.push_back(ex);
		}
		for(int j=0;;j++)
			if(!mark[j])
			{
				dp[i]=j;
				break;
			}
		for(auto u:v)mark[u]=0;
		prt[i]=(prt[i-1]^dp[i]);
	}
	cout<<(dp[n]?id[n]:-1);
	return 0;
}