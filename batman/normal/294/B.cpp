#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (111)
#define INF ((ll)1e9)
ll n,sum,dp[N*2];
pair <ll,ll> p[N];
int main()
{
	ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>p[i].first>>p[i].second,sum+=p[i].first;
    for(int i=1;i<2*N;i++)dp[i]=INF;	
	for(int i=0;i<n;i++)
		for(int j=sum;j>=0;j--)
			dp[j]=min(((j>=p[i].first)?dp[j-p[i].first]:INF),dp[j]+p[i].second);
	for(int i=0;i<2*N;i++)
		if(dp[i]<=i)
			return cout<<i,0;	
    return 0;
}