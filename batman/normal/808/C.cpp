#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)

ll n,w,a[N],ans[N];
pair <ll,ll> b[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>w;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		w-=(a[i]+1)/2;
		ans[i]=(a[i]+1)/2;
		b[i]={a[i],i};
	}
	if(w<0)return cout<<-1,0;
	sort(b,b+n);
	for(int i=n-1;i>=0;i--)
	{
		ll now=min(w,b[i].first-(b[i].first+1)/2);
		w-=now;
		ans[b[i].second]+=now;
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}