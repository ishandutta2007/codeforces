#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)
#define INF ((ll)1e10)

ll n,m,h,b[N],a[N],num[N],ip[N],fen[N];
vector <pair<ll,ll> > ex;
ll seg[4*N],lazy[4*N];

ll add(ll x,ll val){for(;x<N;x+=x&-x)fen[x]+=val;}
ll sum(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}


void shift(ll id)
{
	seg[id*2]+=lazy[id];
	lazy[id*2]+=lazy[id];
	seg[id*2+1]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	lazy[id]=0;
}

void update1(ll q,ll xl,ll xr,ll id,ll val)
{
	if(xl==xr-1)
	{
		seg[id]=val;
		lazy[id]=0;
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(id);
	if(q<mid)update1(q,xl,mid,id*2,val);
	else update1(q,mid,xr,id*2+1,val);
	seg[id]=min(seg[id*2],seg[id*2+1]);
}

void update2(ll ql,ll qr,ll xl,ll xr,ll id,ll val)
{
	if(xr<=ql || qr<=xl)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id]+=val;
		lazy[id]+=val;
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(id);
	update2(ql,qr,xl,mid,id*2,val);
	update2(ql,qr,mid,xr,id*2+1,val);
	seg[id]=min(seg[id*2],seg[id*2+1]);
}

ll _do(ll x)
{
	update1(ip[x],0,n,1,num[x]-sum(ip[x])-1);
	update2(ip[x]+1,n,0,n,1,-1);
	add(ip[x]+1,1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>h;
	for(int i=0;i<4*N;i++)seg[i]=INF;
	for(int i=0;i<m;i++)cin>>b[i];
	sort(b,b+m);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		num[i]=m-(lower_bound(b,b+m,h-a[i])-b);
		ex.push_back({num[i],i});
	}
	sort(ex.begin(),ex.end());
	for(int i=0;i<n;i++)ip[ex[i].second]=i;
	for(int i=0;i<m;i++)
		_do(i);
	ll ans=seg[1]>=0;
	for(int i=1;i+m<=n;i++)
	{
		update1(ip[i-1],0,n,1,INF);
		update2(ip[i-1]+1,n,0,n,1,1);
		add(ip[i-1]+1,-1);
		_do(i+m-1);
		ans+=seg[1]>=0;
	}
	cout<<ans<<"\n";
	return 0;
}