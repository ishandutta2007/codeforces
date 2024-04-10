#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)
#define K ((ll)20)

ll n,q,a[N],b[N],ans[N],now_time;
vector <pair<pair<ll,ll>,pair<ll,ll> > > qu;
ll pre[K][N],maxi[4*N];
set <pair<ll,ll> > st[4*N];

void build(ll xl=0,ll xr=n,ll id=1,ll h=0)
{
	if(xl==xr-1)
	{
		pre[h][xl]=-1;
		maxi[id]=xl;
		return ;
	}
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2,h+1);
	build(mid,xr,id*2+1,h+1);
	vector <pair<pair<ll,ll>,ll> > v;
	for(int i=xl;i<xr;i++)v.push_back({{b[i],a[i]},i});sort(v.begin(),v.end());
	vector <ll> ex;
	for(auto u:v)
	{
		while(ex.size() && a[ex.back()]<=a[u.second])ex.pop_back();
		ex.push_back(u.second);
	}
	pre[h][ex[0]]=-1;maxi[id]=ex[0];
	for(int i=1;i<ex.size();i++)
	{
		ll dif=(a[ex[i-1]]-a[ex[i]]+b[ex[i]]-b[ex[i-1]]-1)/(b[ex[i]]-b[ex[i-1]]);
		st[id].insert({dif,ex[i]});
		pre[h][ex[i]]=ex[i-1];
	}
}

ll query(ll ql,ll qr,ll xl=0,ll xr=n,ll id=1,ll h=0)
{
	if(qr<=xl || xr<=ql)return n;
	if(ql<=xl && xr<=qr)
	{
		while(st[id].size() && st[id].begin()->first<=now_time)
		{
			ll x=st[id].begin()->second;st[id].erase(st[id].begin());
			if(pre[h][pre[h][x]]==-1)
			{
				maxi[id]=x;
				pre[h][x]=-1;
			}
			else
			{
				ll y=pre[h][x];
				pre[h][x]=pre[h][pre[h][x]];
				ll dif=(a[pre[h][x]]-a[x]+b[x]-b[pre[h][x]]-1)/(b[x]-b[pre[h][x]]);
				st[id].insert({dif,x});
				dif=(a[pre[h][x]]-a[y]+b[y]-b[pre[h][x]]-1)/(b[y]-b[pre[h][x]]);
				st[id].erase({dif,y});
			}
		}
		return maxi[id];
	}
	ll mid=(xl+xr)/2;
	ll x=query(ql,qr,xl,mid,id*2,h+1),y=query(ql,qr,mid,xr,id*2+1,h+1);
	return (now_time*b[x]+a[x]>now_time*b[y]+a[y])?x:y;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	for(int i=0;i<q;i++)
	{
		ll l,r,t;
		cin>>l>>r>>t;
		qu.push_back({{t,i},{l-1,r}});
	}
	sort(qu.begin(),qu.end());
	build();
	for(auto u:qu)
	{
		now_time=u.first.first;
		ans[u.first.second]=query(u.second.first,u.second.second)+1;
	}
	for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
	return 0;
}