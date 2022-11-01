#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)

ll n,a[N],seg[4*N],lazy[4*N];

void shift(ll id)
{
	seg[id*2]+=lazy[id];
	seg[id*2+1]+=lazy[id];
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
}

void update(ll ql,ll qr,ll val,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id]+=val;
		lazy[id]+=val;
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(id);
	update(ql,qr,val,xl,mid,id*2);
	update(ql,qr,val,mid,xr,id*2+1);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}

ll query(ll ql,ll qr,ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1)return xl;
	ll mid=(xl+xr)/2;
	shift(id);
	if(seg[id*2+1]>0)return query(ql,qr,mid,xr,id*2+1);
	if(seg[id*2]<=0)return -1;
	return query(ql,qr,xl,mid,id*2);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll p,t,x;
		cin>>p>>t;p--;
		if(t==1)
		{
			cin>>x;
			a[p]=x;
			update(0,p+1,1);
		}
		if(t==0)update(0,p+1,-1);
		if(seg[1]<=0){cout<<"-1\n";continue;}
		cout<<a[query(0,n)]<<"\n";
	}
	return 0;
}