#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e18)

ll n,l[N],v[N],r[N],ans;
vector <ll> _l[N],_v[N],_r[N];
ll seg[4*N],lazy[4*N],fen[N];

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
		seg[id]=max(seg[id],val);
		return ;
	}
	ll mid=(xl+xr)/2;
	shift(id);
	if(q<mid)update1(q,xl,mid,id*2,val);
	else update1(q,mid,xr,id*2+1,val);
	seg[id]=max(seg[id*2],seg[id*2+1]);
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
	seg[id]=max(seg[id*2],seg[id*2+1]);
}

ll query(ll q,ll xl,ll xr,ll id)
{
	if(xl==xr-1)return seg[id];
	ll mid=(xl+xr)/2;
	shift(id);
	if(q<mid)return query(q,xl,mid,id*2);
	return query(q,mid,xr,id*2+1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<4*N;i++)seg[i]=-INF;
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>v[i]>>r[i];
		_l[l[i]].push_back(i);
		_v[v[i]].push_back(i);
		_r[r[i]].push_back(i);
	}
	for(int i=1;i<N;i++)
	{
		for(auto x:_l[i])
		{
			update1(r[x],0,N,1,sum(r[x]));
			update2(v[x],r[x]+1,0,N,1,1);
			add(v[x],1);
			add(r[x],-1);
			ans=max(ans,seg[1]);
		}
		for(auto x:_v[i])
		{
			update1(r[x],0,N,1,-INF);
			update2(v[x],r[x]+1,0,N,1,-1);
			add(v[x],-1);
			add(r[x],1);
		}
	}
	for(int i=0;i<4*N;i++)lazy[i]=0,seg[i]=-INF;
	for(int i=0;i<N;i++)fen[i]=0;
	cout<<ans<<"\n";
	for(int i=1;i<N;i++)
	{
		for(auto x:_l[i])
		{
			update1(r[x],0,N,1,sum(r[x]));
			update2(v[x],r[x]+1,0,N,1,1);
			add(v[x],1);
			add(r[x],-1);
			if(seg[1]==ans)
			{
				
				ll r_res=N-1;
				for(;;r_res--)
					if(query(r_res,0,N,1)==ans)
						break;
				for(int i=0;i<n;i++)
					if(l[i]<=l[x] && r_res<=r[i] && l[x]<=v[i] && v[i]<=r_res)
						cout<<i+1<<" ";
				return 0;
			}
		}
		for(auto x:_v[i])
		{
			update1(r[x],0,N,1,-INF);
			update2(v[x],r[x]+1,0,N,1,-1);
			add(v[x],-1);
			add(r[x],1);
		}
	}
	return 0;
}