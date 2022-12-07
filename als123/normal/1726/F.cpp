#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
const LL MAX=1e15+7;
int n,t;
int g[N],c[N];
struct qq{
	int l,r,id;
	bool operator<(const qq&x)const{
		return r<x.r;
	}
};
int reg (LL x)
{
	x%=t;
	return x<0?x+t:x;
}
LL d[N];
int L[N],R[N];
LL f[N];
set<qq> S;
set<qq> :: iterator split(int x)
{
	auto it=S.lower_bound({0,x,0});
	if (it==S.end()||it->l==x) return it;
	auto now=*it;
	S.erase(now);
	S.insert({now.l,x-1,now.id});
	return S.insert({x,now.r,now.id}).first;
}
void cover (int l,int r,int x)
{
	if (l<=r)
	{
		auto ed=split(r+1);
		auto st=split(l);
		for (auto it=st;it!=ed;)	S.erase(it++);
		S.insert({l,r,x});
	}
	else	{cover(l,t-1,x);cover(0,r,x);}
}
int main()
{
	scanf("%d%d",&n,&t);
	for (int u=1;u<=n;u++) scanf("%d%d",&g[u],&c[u]);
	for (int u=1;u<n;u++) {scanf("%d",&d[u]);d[u]+=d[u-1];}
	for (int u=1;u<=n;u++)
	{
		c[u]=reg((LL)c[u]+d[u-1]);
		L[u]=reg(-c[u]);
		R[u]=reg(L[u]+g[u]);
	}
	S.insert({0,t-1,n+1});
	f[n+1]=0;
	for (int u=n;u>=1;u--)
	{
		auto it=S.lower_bound({0,L[u],0});
		f[u]=f[it->id]+(it->id==n+1?0:reg(L[it->id]-L[u]));
		cover(R[u],L[u],u);
	}
	LL ans=MAX;
	for (auto xx:S)
	{
		if (xx.id==n+1) ans=0;
		else			ans=min(ans,f[xx.id]+reg(L[xx.id]-xx.r));
	}
	printf("%lld\n",ans+d[n-1]);
	return 0;
}