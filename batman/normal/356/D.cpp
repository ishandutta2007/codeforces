#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)71*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)

ll n,s,par[N];
bitset <N> dp,ex,ex2;
pair <ll,ll> a[N],ans[N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n>>s;
   	for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;
   	sort(a,a+n);
   	s-=a[n-1].first;
   	dp[0]=1;par[0]=-1;
   	for(int i=0;i<n-1;i++)
   	{
   		ex=dp|(dp<<a[i].first);
   		ex2=ex^dp;
   		for(int j=ex2._Find_first();j<N;j=ex2._Find_next(j))par[j]=i;
   		dp=ex;
	}
	if(s<0 || !dp[s])return cout<<-1,0;
	while(par[s]!=-1)
	{
		ans[a[par[s]].second]={a[par[s]].first,-1};
		s-=a[par[s]].first;
	}
	for(int i=0,lst=-1;i<n;i++)
		if(ans[a[i].second].second!=-1)
		{
			if(lst==-1)ans[a[i].second]={a[i].first,-1};
			else ans[a[i].second]={a[i].first-a[lst].first,a[lst].second};
			lst=i;
		}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i].first<<" "<<((ans[i].second==-1)?0:1);
		if(ans[i].second!=-1)cout<<" "<<ans[i].second+1;
		cout<<"\n";
	}
	return 0;
}