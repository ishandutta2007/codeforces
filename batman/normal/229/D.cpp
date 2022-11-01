#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (5050)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,a[N];
pair <ll,ll> dp[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(ll j=i,sum=0;j>=1;j--)
		{
			sum+=a[j];
			if(dp[j-1].first<=sum)
			{
				dp[i]={sum,i-j+dp[j-1].second};
				break;
			}
		}
	}
	cout<<dp[n].second;
    return 0;
}