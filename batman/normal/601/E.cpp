#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)31*1000)
#define K ((ll)1020)
#define INF ((ll)2e9)
#define P ((ll)1e7+19)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

struct exhibit{
	ll l,r,v,w;
};

ll n,k,q,num,now[K];
long long ans[N];
exhibit a[N];
vector <pair<ll,ll> > seg[4*N];

void add(ll v,ll w,ll dp[]){for(int i=k;i>=w;i--)dp[i]=max(dp[i],dp[i-w]+v);}

void update(ll ql,ll qr,ll v,ll w,ll xl=0,ll xr=num,ll id=1)
{
	if(xr<=ql || qr<=xl)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id].push_back({v,w});
		return ;
	}
	ll mid=(xl+xr)/2;
	update(ql,qr,v,w,xl,mid,id*2);
	update(ql,qr,v,w,mid,xr,id*2+1);
}

void build(ll xl=0,ll xr=num,ll id=1)
{
	ll ex[K];
	for(int i=0;i<=k;i++)ex[i]=now[i];
	for(auto u:seg[id])add(u.first,u.second,now);
	if(xl==xr-1)
	{
		for(ll i=1,ex=1,ex2=now[1];i<=k;i++,ex*=P,ex%=MOD,ex2=max(now[i],ex2))if(ex2>0)ans[xl]+=ex2*ex,ans[xl]%=MOD;
		for(int i=0;i<=k;i++)now[i]=ex[i];
		return ;
	}
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	for(int i=0;i<=k;i++)now[i]=ex[i];
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(now,-63,sizeof now);now[0]=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		ll v,w;
		cin>>v>>w;
		a[i].l=0,a[i].v=v,a[i].w=w;a[i].r=-1;
	}
	cin>>q;
	while(q--)
	{
		ll t,v,w,x;
		cin>>t;
		if(t==1)
		{
			cin>>v>>w;
			a[n].l=num,a[n].v=v,a[n].w=w;a[n].r=-1;
			n++;
		}
		if(t==2)cin>>x,x--,a[x].r=num;
		if(t==3)num++;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i].r==-1)a[i].r=num;
		update(a[i].l,a[i].r,a[i].v,a[i].w);
	}
	build();
	for(int i=0;i<num;i++)cout<<ans[i]<<"\n";
	return 0;
}