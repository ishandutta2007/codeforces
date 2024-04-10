#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define INF ((ll)2e9)

struct Node
{
	long long sum;
	ll maxi,max_id,lazy;
};

ll n,q,a[N];
set <pair<pair<ll,ll>,ll> > s;
pair <pair<ll,ll>,ll> hlp;
Node seg[4*N];

void shift(ll id,ll xl,ll xr)
{
	if(seg[id].lazy==-1)return ;
	ll mid=(xl+xr)/2;
	seg[id*2].maxi=seg[id*2+1].maxi=seg[id*2].lazy=seg[id*2+1].lazy=seg[id].lazy;
	seg[id*2].max_id=xl;seg[id*2+1].max_id=mid;
	seg[id*2].sum=1LL*(mid-xl)*seg[id].lazy;
	seg[id*2+1].sum=1LL*(xr-mid)*seg[id].lazy;
	seg[id].lazy=-1;
}

Node merge(Node x,Node y)
{
	Node res;
	res.sum=x.sum+y.sum;
	res.maxi=max(x.maxi,y.maxi);
	if(x.maxi>=y.maxi)res.max_id=x.max_id;
	else res.max_id=y.max_id;
	res.lazy=-1;
	return res;
}

void update(ll ql,ll qr,ll val,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id].lazy=seg[id].maxi=val;
		seg[id].sum=1LL*(xr-xl)*val;
		seg[id].max_id=xl;
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(id,xl,xr);
	update(ql,qr,val,xl,mid,id*2);
	update(ql,qr,val,mid,xr,id*2+1);
	seg[id]=merge(seg[id*2],seg[id*2+1]);
}

Node query(ll ql,ll qr,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return {0,0,0,-1};
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	shift(id,xl,xr);
	return merge(query(ql,qr,xl,mid,id*2),query(ql,qr,mid,xr,id*2+1));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<4*N;i++)seg[i].lazy=-1;
	for(int i=0;i<n;i++)cin>>a[i],update(i,i+1,a[i]),s.insert({{i,i},a[i]});
	hlp.first.second=hlp.second=INF;
	while(q--)
	{
		ll t,l,r,x;
		cin>>t;
		if(t==3)
		{
			cin>>l>>x;l--;
			r=l;
			update(l,r+1,x);
			hlp.first.first=l;
			auto it=s.upper_bound(hlp);it--;
			pair <ll,ll> p=it->first;
			ll num=it->second;
			s.erase(it);
			s.insert({{l,p.second},num});
			if(l>p.first)
				s.insert({{p.first,l-1},num});
			hlp.first.first=r;
			it=s.upper_bound(hlp);it--;
			p=it->first;num=it->second;
			s.erase(it);
			s.insert({{p.first,r},num});
			if(r<p.second)
				s.insert({{r+1,p.second},num});
			while(1)
			{
				hlp.first.first=l-1;
				it=s.lower_bound(hlp);
				if(it==s.end() || it->first.first>r)break;
				s.erase(it);
			}
			s.insert({{l,r},x});
		}
		if(t==2)
		{
			cin>>l>>r>>x;l--;r--;
			while(1)
			{
				Node ex=query(l,r+1);
				if(ex.maxi<x)break;
				hlp.first.first=ex.max_id;
				auto it=s.upper_bound(hlp);it--;
				pair <ll,ll> p;p=it->first;
				s.erase(it);
				if(p.second>r)
				{
					s.insert({{r+1,p.second},ex.maxi});
					s.insert({{p.first,r},ex.maxi%x});
				}
				else if(p.first<l)
				{
					s.insert({{p.first,l-1},ex.maxi});
					s.insert({{l,p.second},ex.maxi%x});
				}
				else
				{
					s.insert({p,ex.maxi%x});
				}
				update(max(l,p.first),min(p.second,r)+1,ex.maxi%x);
			}
		}
		if(t==1){cin>>l>>r;l--;r--;cout<<query(l,r+1).sum<<"\n";}
	}

	return 0;
}