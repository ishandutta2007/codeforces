#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)36*1000)
#define K ((ll)52)
#define INF ((ll)1e9)

ll n,k,a[N],dp[N],lst[N];
ll seg[4*N],lazy[4*N];

void build(ll xl=0,ll xr=n+1,ll id=1)
{
	lazy[id]=0;
	if(xl==xr-1)
	{
		seg[id]=dp[xl];
		return ;
	}
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}

void shift(ll id)
{
	seg[id*2]+=lazy[id];
	seg[id*2+1]+=lazy[id];
	lazy[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
}

void update(ll ql,ll qr,ll val,ll xl=0,ll xr=n+1,ll id=1)
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

ll query(ll ql,ll qr,ll xl=0,ll xr=n+1,ll id=1)
{
	if(qr<=xl || xr<=ql)return -INF;
	if(ql<=xl && xr<=qr)return seg[id];
	ll mid=(xl+xr)/2;
	shift(id);
	return max(query(ql,qr,xl,mid,id*2),query(ql,qr,mid,xr,id*2+1));
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n;i++)lst[i]=-1;
		for(int i=1;i<=n;i++)
		{
			if(lst[a[i]]!=-1)update(lst[a[i]],i,1);
			else update(0,i,1);
			lst[a[i]]=i;
			dp[i]=query(0,i);
		}
		dp[0]=-INF;
		//for(int i=0;i<=n;i++)cout<<dp[i]<<" ";cout<<"\n";
		if(j<k)build();
	}
	cout<<dp[n]<<"\n";
	return 0;
}