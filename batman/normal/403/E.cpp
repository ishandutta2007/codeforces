#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)

ll n,st[2][N],fn[2][N],now,seg[2][2][4*N];
vector <ll> e[2][N];
vector <pair<ll,ll> > v[2][2][N];
bitset <N> mark[2];

void dfs(ll x,bool p)
{
	st[p][x]=now++;
	for(auto u:e[p][x])dfs(u,p);
	fn[p][x]=now;
}

bool cmp(pair <ll,ll> x,pair<ll,ll> y){return x>y;}

ll merge(ll x,ll y,bool rght,bool p)
{
	while(v[rght][p][x].size() && mark[p][v[rght][p][x].back().second])v[rght][p][x].pop_back();
	while(v[rght][p][y].size() && mark[p][v[rght][p][y].back().second])v[rght][p][y].pop_back();
	if((ll)v[rght][p][y].size()==0)return x;
	if((ll)v[rght][p][x].size()==0)return y;
	return ((v[rght][p][x].back()>v[rght][p][y].back())^rght)?y:x;
}

void update(ll q,bool rght,bool p,ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1){seg[rght][p][id]=xl;return ;}
	ll mid=(xl+xr)/2;
	if(q<mid)update(q,rght,p,xl,mid,id*2);
	else update(q,rght,p,mid,xr,id*2+1);
	seg[rght][p][id]=merge(seg[rght][p][id*2],seg[rght][p][id*2+1],rght,p);
}

void build(bool rght,bool p,ll xl=0,ll xr=n,ll id=1)
{
	if(xl==xr-1){seg[rght][p][id]=xl;return ;}
	ll mid=(xl+xr)/2;
	build(rght,p,xl,mid,id*2);
	build(rght,p,mid,xr,id*2+1);
	seg[rght][p][id]=merge(seg[rght][p][id*2],seg[rght][p][id*2+1],rght,p);
}

ll query(ll ql,ll qr,bool rght,bool p,ll xl=0,ll xr=n,ll id=1)
{
	if(qr<=xl || xr<=ql)return n;
	if(ql<=xl && xr<=qr)return merge(seg[rght][p][id],n,rght,p);
	ll mid=(xl+xr)/2;
	return merge(query(ql,qr,rght,p,xl,mid,id*2),query(ql,qr,rght,p,mid,xr,id*2+1),rght,p);
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		ll x;
		scanf("%d",&x);
		e[0][x].push_back(i);
	}
	for(int i=2;i<=n;i++)
	{
		ll x;
		scanf("%d",&x);
		e[1][x].push_back(i);
	}
	dfs(1,0);now=0;dfs(1,1);
	for(int i=1;i<=n;i++)
		for(int p=0;p<=1;p++)
			for(auto u:e[p][i])
			{
				ll x=i,y=u;
				if(st[1-p][x]>st[1-p][y])swap(x,y);
				v[1][1-p][st[1-p][x]].push_back({st[1-p][y],u-1});
				v[0][1-p][st[1-p][y]].push_back({st[1-p][x],u-1});
			}
	for(int p=0;p<=1;p++)for(int q=0;q<=1;q++)for(int i=0;i<n;i++)
	{
		if(p==1)sort(v[p][q][i].begin(),v[p][q][i].end());
		else sort(v[p][q][i].begin(),v[p][q][i].end(),cmp);
	}
	ll ed;scanf("%d",&ed);mark[1][ed]=1;
	for(int p=0;p<=1;p++)for(int q=0;q<=1;q++)build(p,q);
	vector <ll> ex;ex.push_back(ed);
	for(int t=0;ex.size();t=1-t)
	{
		if(t)printf("Red\n");
		else printf("Blue\n");
		vector <ll> ex2;
		sort(ex.begin(),ex.end());
		for(auto u:ex)
		{
			printf("%d ",u);
			ll ver=u+1;
			while(1)
			{
				ll x=query(st[t][ver],fn[t][ver],1,t);
				if((ll)v[1][t][x].size()==0 || v[1][t][x].back().first<fn[t][ver])break;
				mark[t][v[1][t][x].back().second]=1;
				ex2.push_back(v[1][t][x].back().second);
				ll y=v[1][t][x].back().first;
				update(x,1,t);
				update(y,0,t);
			}
			while(1)
			{
				ll x=query(st[t][ver],fn[t][ver],0,t);
				if((ll)v[0][t][x].size()==0 || v[0][t][x].back().first>=st[t][ver])break;
				mark[t][v[0][t][x].back().second]=1;
				ex2.push_back(v[0][t][x].back().second);
				ll y=v[0][t][x].back().first;
				update(x,0,t);
				update(y,1,t);
			}
		}
		printf("\n");ex=ex2;
	}
	return 0;
}