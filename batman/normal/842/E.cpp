#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)301*1000)
#define K ((ll)20)

struct Node
{
	ll maxi,cnt_max,lazy;
};

ll n,par[K][N],h[N],strt[N],fnsh[N],_cnt;
vector <ll> e[N];
Node seg[4*N];

void build(ll xl=0,ll xr=n,ll id=1)
{
	seg[id]={0,0,0};
	if(xl==xr-1)return ;
	ll mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
}

void update(ll ql,ll qr,ll val,bool type,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		if(!type){seg[id]={val,1,0};return ;}
		seg[id].maxi+=val;
		seg[id].lazy+=val;
		return ;
	}
	ll mid=(xl+xr)/2;
	
	seg[id*2].maxi+=seg[id].lazy;
	seg[id*2].lazy+=seg[id].lazy;
	seg[id*2+1].maxi+=seg[id].lazy;
	seg[id*2+1].lazy+=seg[id].lazy;
	seg[id].lazy=0;
	
	update(ql,qr,val,type,xl,mid,id*2);
	update(ql,qr,val,type,mid,xr,id*2+1);
	
	seg[id].maxi=max(seg[id*2].maxi,seg[id*2+1].maxi);
	seg[id].cnt_max=0;
	if(seg[id*2].maxi==seg[id].maxi)seg[id].cnt_max+=seg[id*2].cnt_max;
	if(seg[id*2+1].maxi==seg[id].maxi)seg[id].cnt_max+=seg[id*2+1].cnt_max;
}

void pre_dfs(ll x)
{
	strt[x]=_cnt++;
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
		par[0][u]=x,
		h[u]=h[x]+1,
		pre_dfs(u);
	fnsh[x]=_cnt;
}

ll iPar(ll x,ll num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

ll lca(ll x,ll y)
{
	if(h[x]<h[y])swap(x,y);
	x=iPar(x,h[x]-h[y]);
	if(x==y)return x;
	for(int i=K-1;i>=0;i--)
		if(par[i][x]!=par[i][y])
			x=par[i][x],y=par[i][y];
	return par[0][x];
}

ll Dis(ll x,ll y){return h[x]+h[y]-2*h[lca(x,y)];}

ll calc(ll x,ll y,ll p,ll num)
{
	if(num<=h[x]-h[p])return iPar(x,num);
	num=h[x]+h[y]-2*h[p]-num;
	return iPar(y,num);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;n++;
	for(int i=2;i<=n;i++)
	{
		ll x;
		cin>>x;
		e[x].push_back(i);
	}
	pre_dfs(1);
	build();
	ll v=1,u=1,dist=0;
	update(strt[1],strt[1]+1,0,0);
	for(int i=2;i<=n;i++)
	{
		ll _v=Dis(i,v),_u=Dis(i,u);
		if(max(_v,_u)<=dist)
		{
			update(strt[i],strt[i]+1,max(_v,_u),0);
			cout<<seg[1].cnt_max<<"\n";
			continue;
		}
		if(_v<_u)swap(v,u),swap(_v,_u);
		ll p=lca(v,i);
		ll x1=calc(i,v,p,_v/2);
		ll x2=calc(i,v,p,_v/2+1);
		if(x1==par[0][x2])
			update(strt[x2],fnsh[x2],1,1);
		else
			update(strt[1],fnsh[1],1,1),
			update(strt[x1],fnsh[x1],-1,1);
		update(strt[i],strt[i]+1,max(_v,_u),0);
		u=i;dist++;
		cout<<seg[1].cnt_max<<"\n";
	}
	return 0;
}