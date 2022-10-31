#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)21*1000)

ll n,par[N],all,a[N],b[N],c[N];
vector <pair<ll,pair<ll,ll> > > ed;

ll root(ll x){if(par[x]==-1)return x;return par[x]=root(par[x]);}

bool check(ll x)
{
	memset(par,-1,sizeof par);
	for(auto q:ed)
	{
		if(q.first>=x)break;
		par[root(q.second.first)]=root(q.second.second);
	}
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	for(int i=1;i<=n;i++)
		b[root(i)]++,c[root(i)]+=a[i];
	for(int i=1;i<=n;i++)
		if(par[i]==-1 && all-c[i]<b[i])
			return 0;
	return 1;
}

int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		ed.push_back({w,{v,u}});
	}
	for(int i=1;i<=n;i++)cin>>a[i],all+=a[i];
	sort(ed.begin(),ed.end());
	ll l=0,r=20*1000;
	while(l<r-1)
	{
		ll mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}