#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)

struct node{
	ll frd,zj,ex_frd,ex_zj,lazy;
	bool empty;
};

ll n,q,a[N];
node seg[4*N];

node merge(node x,node y)
{
	if(x.empty)return y;
	if(y.empty)return x;
	node res={0,0,0,0,0,0};
	res.frd=x.frd+y.frd;
	res.zj=x.zj+y.zj;
	res.ex_frd=min(x.ex_frd,x.frd-x.zj+y.ex_frd);
	res.ex_zj=min(x.ex_zj,x.zj-x.frd+y.ex_zj);
	return res;
}

void update(ll,ll,ll,ll,ll,ll);
void shift(ll xl,ll xr,ll id)
{
	ll mid=(xl+xr)/2;
	update(xl,xr,xl,mid,id*2,seg[id].lazy);
	update(xl,xr,mid,xr,id*2+1,seg[id].lazy);
	seg[id].lazy=0;
}

void update(ll ql,ll qr,ll xl,ll xr,ll id,ll val)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id].lazy+=val;
		seg[id].frd+=(xr-xl)/2*val;
		seg[id].zj+=(xr-xl)/2*val;
		if(xl%2==(xr-1)%2)
		{
			if(xl%2==0)seg[id].frd+=val;
			else seg[id].zj+=val;
		}
		if(xl%2==0)seg[id].ex_frd+=val;
		else seg[id].ex_zj+=val;
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(xl,xr,id);
	update(ql,qr,xl,mid,id*2,val);
	update(ql,qr,mid,xr,id*2+1,val);
	seg[id]=merge(seg[id*2],seg[id*2+1]);
}

node query(ll ql,ll qr,ll xl,ll xr,ll id)
{
	if(qr<=xl || xr<=ql)return {0,0,0,0,0,1};
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	shift(xl,xr,id);
	return merge(query(ql,qr,xl,mid,id*2),query(ql,qr,mid,xr,id*2+1));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],update(i,i+1,0,n,1,a[i]);
	cin>>q;
	while(q--)
	{
		ll t,l,r,k;
		cin>>t;
		if(t==1)
		{
			cin>>l>>r>>k;
			update(l,r+1,0,n,1,k);
		}
		if(t==2)
		{
			cin>>l>>r;
			node x=query(l,r,0,n,1);
			if(l%2==0 && !x.empty){if(x.ex_frd<1 || x.ex_zj<0){cout<<"0\n";continue;}}
			else if(!x.empty){if(x.ex_zj<1 || x.ex_frd<0){cout<<"0\n";continue;}}
			ll num,num2;
			if(r%2==0)num=query(r,r+1,0,n,1).frd,num2=x.zj-x.frd;
			else num=query(r,r+1,0,n,1).zj,num2=x.frd-x.zj;
			num2-=(r-l)%2;
			cout<<(num==num2+1)<<"\n";
		}
	}
	return 0;
}