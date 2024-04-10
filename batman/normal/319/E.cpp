#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((ll)301*1000)

struct Seg{
	ll l,r,par;
};
ll n,m=1,num[N],seg[4*N];
Seg a[N];
vector <pair<ll,pair<ll,ll> > > qu;
map <ll,ll> pos;
set <pair<ll,ll> > _r[N];
ll root(ll x){if(a[x].par==-1)return x;return a[x].par=root(a[x].par);}

void build(ll xl=0,ll xr=N,ll id=1)
{
	if(xl==xr-1)
	{
		num[xl]=-1;
		seg[id]=xl;
		return ;
	}
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	seg[id]=seg[id*2];
}

void update(ll q,ll xl=0,ll xr=N,ll id=1)
{
	if(xl==xr-1)
	{
		if(_r[xl].size()==0)num[xl]=-1;
		else num[xl]=_r[xl].rbegin()->first;
		return ;
	}
	ll mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,id*2);
	else update(q,mid,xr,id*2+1);
	seg[id]=((num[seg[id*2]]>num[seg[id*2+1]])?seg[id*2]:seg[id*2+1]);
}

ll query(ll ql,ll qr,ll xl=0,ll xr=N,ll id=1)
{
	if(qr<=xl || xr<=ql)return N-1;
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	ll x=query(ql,qr,xl,mid,id*2),y=query(ql,qr,mid,xr,id*2+1);
	return ((num[x]>num[y])?x:y);
}

void merge(ll x,ll y)
{
	a[x].l=min(a[x].l,a[y].l);
	a[x].r=max(a[x].r,a[y].r);
	a[y].par=x;
	_r[a[y].l].erase({a[y].r,y});
	update(a[y].l);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	build();
	vector <ll> ex;
	for(int i=0;i<n;i++)
	{
		ll t,l,r;
		cin>>t>>l>>r;
		qu.push_back({t,{l,r}});
		if(t==1)ex.push_back(l),ex.push_back(r);
	}
	sort(ex.begin(),ex.end());ex.resize(unique(ex.begin(),ex.end())-ex.begin());
	for(int i=0;i<ex.size();i++)pos[ex[i]]=i;
	for(auto u:qu)
	{
		ll t=u.first,l=u.second.first,r=u.second.second;
		if(t==1)
		{
			l=pos[l],r=pos[r];
			a[m]={l,r,-1};
			while(1)
			{
				ll x=query(0,r);
				if(_r[x].size()==0)break;
				pair <ll,ll> p=*_r[x].rbegin();
				if(p.first<=r)break;
				merge(m,p.second);
			}
			while(1)
			{
				ll x=query(0,l);
				if(_r[x].size()==0)break;
				pair <ll,ll> p=*_r[x].rbegin();
				if(p.first<=l)break;
				merge(m,p.second);
			}
			l=a[m].l,r=a[m].r;
			_r[l].insert({r,m});
			update(l);
			m++;
		}
		if(t==2)
		{
			l=root(l),r=root(r);
			cout<<((l==r || (a[l].l>=a[r].l && a[l].r<=a[r].r))?"YES":"NO")<<"\n";	
		}
	}
	return 0;
}