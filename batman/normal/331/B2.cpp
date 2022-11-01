#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)301*1000)

struct node{
	ll ans,l,r;
};

ll n,m,a[N],pos[N];
node seg[4*N];

node merge(node x,node y)
{
	node res;
	res.l=x.l;res.r=y.r;
	res.ans=x.ans+y.ans+(x.r>y.l);
	return res;
}

void update(ll q,ll xl=0,ll xr=N,ll id=1)
{
	if(xl==xr-1)
	{
		seg[id].l=seg[id].r=pos[xl];
		return ;
	}
	ll mid=(xl+xr)/2;
	if(q<mid)update(q,xl,mid,id*2);
	else update(q,mid,xr,id*2+1);
	seg[id]=merge(seg[id*2],seg[id*2+1]);
}

node query(ll ql,ll qr,ll xl=0,ll xr=N,ll id=1)
{
	if(qr<=xl || xr<=ql)return {0,N,-1};
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	return merge(query(ql,qr,xl,mid,id*2),
					query(ql,qr,mid,xr,id*2+1));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
		update(a[i]);
	}
	cin>>m;
	while(m--)
	{
		ll t,x,y;
		cin>>t>>x>>y;
		if(t==1)
			cout<<query(x,y+1).ans+1<<"\n";
		if(t==2)
			swap(a[x],a[y]),
			swap(pos[a[x]],pos[a[y]]),
			update(a[x]),update(a[y]);
	}
	return 0;
}