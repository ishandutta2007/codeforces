#include<bits/stdc++.h>
int n,a[1111111],b[1111111];
std::set<int>S;
typedef long long ll;
ll ans[1111111];
namespace segt
{
	int stk[10222222],s[10222222][2],sz[10222222],tc=5e5,tp;
	ll sm[10222222];
	int nd()
	{
		if(tp)
		{
			int a=stk[tp];
			tp--,s[a][0]=s[a][1]=sz[a]=sm[a]=0;
			return a;
		}else return ++tc;
	}
	#define ls(x) s[x][0]
	#define rs(x) s[x][1]
	void pushu(int p){sz[p]=sz[ls(p)]+sz[rs(p)],sm[p]=sm[ls(p)]+sm[rs(p)];}
	void ins(int v,int p,int pl=1,int pr=4e5)
	{
		if(pl==pr){sz[p]=1,sm[p]=v;return;}
		if(!ls(p))ls(p)=nd(),rs(p)=nd();
		int pm=(pl+pr)>>1,dr=v>pm;
		dr?pl=pm+1:pr=pm,ins(v,s[p][dr],pl,pr),pushu(p);
	}
	ll lins(int v,int p,int pl=1,int pr=4e5)
	{
		if(pl==pr){sz[p]=1,sm[p]=v;return 0;}
		if(!ls(p))ls(p)=nd(),rs(p)=nd();
		int pm=(pl+pr)>>1,dr=v>pm;
		ll r;dr?pl=pm+1:pr=pm,r=lins(v,s[p][dr],pl,pr),pushu(p);
		if(dr)r+=v*1ll*sz[ls(p)]-sm[ls(p)];
		return r;
	}
	ll rins(int v,int p,int pl=1,int pr=4e5)
	{
		if(pl==pr){sz[p]=1,sm[p]=v;return 0;}
		if(!ls(p))ls(p)=nd(),rs(p)=nd();
		int pm=(pl+pr)>>1,dr=v>pm;
		ll r;dr?pl=pm+1:pr=pm,r=rins(v,s[p][dr],pl,pr),pushu(p);
		if(!dr)r+=sm[rs(p)]-v*1ll*sz[rs(p)];
		return r;
	}
	void reuse(int p)
	{
		if(ls(p))reuse(ls(p));
		if(rs(p))reuse(rs(p));
		stk[++tp]=p;
	}
}
bool dec(int x,int y){return x>y;}
int L[1111111],R[1111111],tp[1111111],rt[1111111];
ll merge(int l,int m,int r)
{
	register int i;
	ll ret=0;
	if(m-l>r-m)
	{
		segt::reuse(rt[m+1]);
		std::sort(tp+m+1,tp+r+1,dec);
		for(i=m+1;i<=r;i++)ret+=segt::lins(tp[i],rt[l]);
	}
	else
	{
		segt::reuse(rt[l]);
		std::sort(tp+l,tp+m+1,dec);
		rt[l]=rt[m+1];
		for(i=m;i>=l;i--)ret+=segt::rins(tp[i],rt[l]);
	}L[l]=r,R[r]=l;
	return ret;
}
ll push(int x,int v)
{
	L[x]=R[x]=x,segt::ins(v,x),tp[x]=v;
	ll r=0;
	if(R[x-1])r+=merge(R[x-1],x-1,x);
	if(L[x+1])r+=merge(R[x],x,L[x+1]);
	return r;
}
int main()
{
	register int i;
	for(i=1;i<=400000;i++)S.insert(i),rt[i]=i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",a+i,b+i);
		int da=*S.lower_bound(a[i]);
		ans[i]=b[i]*1ll*(da-a[i]),S.erase(da),a[i]=da;
	}ll V=0;
	for(i=1;i<=n;i++)V+=ans[i]-push(a[i],b[i]),printf("%lld\n",V);
}
/*
Please don't let me down.
*/