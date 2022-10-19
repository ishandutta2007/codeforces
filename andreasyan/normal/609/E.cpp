#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=2*100005;
struct ban
{
	long long x,y,d;
};
bool operator<(const ban& a,const ban b)
{
	return a.d>b.d;
}

long long n,m,l;
pair<pair<long long,long long>,long long> k[N];
vector<ban> a[N];
vector<ban> b[N];
ban t;
bool c[N];
vector<long long> up[N];
vector<long long> md[N];
long long tin[N];
long long tout[N];
long long tim;
long long ans;
long long lc1;
map<pair<long long,long long>,bool> mp;
void dfs(long long x,long long p,long long herp)
{
	long long i,j;
	ban h;
	tin[x]=++tim;
	up[x][0]=p;
	md[x][0]=herp;
	for(i=1;i<=l;++i)
	{
		up[x][i]=up[up[x][i-1]][i-1];
		md[x][i]=max(md[x][i-1],md[up[x][i-1]][i-1]);
	}
	for(i=0;i<b[x].size();++i)
	{
		h=b[x][i];
		if(h.x==p)
			continue;
		dfs(h.x,x,h.d);
	}
	tout[x]=++tim;
}
bool ip(long long x,long long y)
{
	return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
long long lca(long long x,long long y)
{
	long long i,j;
	long long res=0;
	if(ip(x,y))
		return 0;
	for(i=l;i>=0;--i)
		if(!ip(up[x][i],y) || up[x][i]==lc1)
		{
			res=max(res,md[x][i]);
			x=up[x][i];
		}
	return res;
}
long long lca1(long long x,long long y)
{
	long long i,j;
	long long res=0;
	if(ip(x,y))
		return x;
	if(ip(y,x))
		return y;
	for(i=l;i>=0;--i)
		if(!ip(up[x][i],y))
			x=up[x][i];
	return up[x][0];
}
int main()
{
	long long i,j,x,y,z;
	//////////////////////////input
	scanf("%I64d%I64d",&n,&m);
	for(i=0;i<m;++i)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		t.d=z;
		t.x=y;
		a[x].push_back(t);
		t.x=x;
		a[y].push_back(t);
		k[i].first.first=x;
		k[i].first.second=y;
		k[i].second=z;
	}
	//////////////////////////prim
	priority_queue<ban> q;
	t.y=1;
	t.d=0;
	q.push(t);
	while(!q.empty())
	{
		ban h;
		do
		{
			if(q.empty())
				goto kov;
			t=q.top();
			q.pop();
		}while(c[t.y]);
		c[t.y]=true;
		ans+=t.d;
		if(t.d)
		{
			h.d=t.d;
			h.x=t.x;
			b[t.y].push_back(h);
			h.x=t.y;
			b[t.x].push_back(h);
			mp[make_pair(t.x,t.y)]=true;
			mp[make_pair(t.y,t.x)]=true;
		}
		for(i=0;i<a[t.y].size();++i)
		{
			h.d=a[t.y][i].d;
			h.x=t.y;
			h.y=a[t.y][i].x;
			if(!c[h.y])
				q.push(h);
		}
	}
kov:
	////////////////////////////getting ready to do lca
	while ((1<<l) <= n)
		++l;
	for(i=0;i<=n;++i)
	{
		up[i].resize(l+1,1);
		md[i].resize(l+1,0);
	}
	dfs(1,1,0);
	//////////////////////////////output
	for(i=0;i<m;++i)
	{
		if(mp[make_pair(k[i].first.first,k[i].first.second)])
		{
			printf("%I64d\n",ans);
			continue;
		}
		x=0;
		lc1=lca1(k[i].first.first,k[i].first.second);
		x=max(lca(k[i].first.first,k[i].first.second),lca(k[i].first.second,k[i].first.first));
		printf("%I64d\n",ans-x+k[i].second);
	}
	return 0;
}