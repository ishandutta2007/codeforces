#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)

struct Dsu
{
	ll par,sz;
	bool clr;
};

ll n,q,ans;
Dsu a[N];
map <pair<ll,ll>,ll> mp;
vector <pair<ll,ll> > seg[4*N];

pair<ll,ll> root(ll x)
{
	if(a[x].par<0)return {x,0};
	pair <ll,ll> res=root(a[x].par);
	res.second^=a[x].clr;
	return res;
}

void update(ll ql,ll qr,pair<ll,ll> ed,ll xl=0,ll xr=q,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id].push_back(ed);
		return ;
	}
	ll mid=(xl+xr)/2;
	update(ql,qr,ed,xl,mid,id*2);
	update(ql,qr,ed,mid,xr,id*2+1);
}

void build(ll xl=0,ll xr=q,ll id=1)
{
	ll mid=(xl+xr)/2;
	ll now=0;
	vector <pair<ll,ll> > ex;
	for(auto u:seg[id])
	{
		pair <ll,ll> r1,r2;
		r1=root(u.first);r2=root(u.second);
		if(r1.first==r2.first)
		{
			if(r1.second==r2.second)now++;
			continue;
		}
		if(a[r1.first].sz>a[r2.first].sz)swap(r1,r2),swap(u.first,u.second);
		ex.push_back({r1.first,r2.first});
		if(r1.second==r2.second)a[r1.first].clr=1;
		a[r2.first].sz+=a[r1.first].sz;
		a[r1.first].par=r2.first;
	}
	ans+=now;
	if(xl==xr-1)
	{
		cout<<((!ans)?"YES\n":"NO\n");
	}
	else
	{
		build(xl,mid,id*2);
		build(mid,xr,id*2+1);
	}
	ans-=now;
	for(int i=(ll)ex.size()-1;i>=0;i--)
	{
		pair <ll,ll> u=ex[i];
		a[u.second].sz-=a[u.first].sz;
		a[u.first].par=-1;
		a[u.first].clr=0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)a[i].par=-1,a[i].clr=0,a[i].sz=1;
	for(int i=0;i<q;i++)
	{
		ll v,u;
		cin>>v>>u;
		if(v>u)swap(v,u);
		if(mp[{v,u}])
			update(mp[{v,u}]-1,i,{v,u}),mp[{v,u}]=0;
		else
			mp[{v,u}]=i+1;
	}
	for(auto u:mp)
		if(u.second)
			update(u.second-1,q,u.first);
	build();
	return 0;
}