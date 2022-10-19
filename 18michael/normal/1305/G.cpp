#include<bits/stdc++.h>
#define Mx 262143
#define LL long long
using namespace std;
int n;
LL ans=0;
int a[200002],rt[200002],mx[Mx+2],se[Mx+2],to[200002],val[200002];
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline bool check()
{
	for(int i=0;i<=n;++i)getroot(i);
	for(int i=1;i<=n;++i)if(rt[i]^rt[0])return 1;
	return 0;
}
inline void ins(int x,int y)
{
	if(a[mx[x]]<a[y])
	{
		if(rt[mx[x]]^rt[y])se[x]=mx[x];
		mx[x]=y;
	}
	else if(a[se[x]]<a[y] && rt[mx[x]]^rt[y])se[x]=y;
}
int main()
{
	scanf("%d",&n),a[n+1]=-1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),rt[i]=i,ans-=a[i];
	while(check())
	{
		for(int i=0;i<=Mx;++i)mx[i]=se[i]=n+1;
		for(int i=0;i<=n;++i)ins(a[i],i),val[i]=-1;
		for(int i=0;i<=Mx;++i)for(int j=0;j<18;++j)if((i>>j)&1)ins(i,mx[i^(1<<j)]),ins(i,se[i^(1<<j)]);
		for(int i=0;i<=n;++i)
		{
			if(mx[Mx^a[i]]<=n && rt[mx[Mx^a[i]]]^rt[i])if((a[i]|a[mx[Mx^a[i]]])>val[rt[i]])to[rt[i]]=mx[Mx^a[i]],val[rt[i]]=(a[i]|a[mx[Mx^a[i]]]);else;
			else if(se[Mx^a[i]]<=n && (a[i]|a[se[Mx^a[i]]])>val[rt[i]])to[rt[i]]=se[Mx^a[i]],val[rt[i]]=(a[i]|a[se[Mx^a[i]]]);
		}
		for(int i=0;i<=n;++i)if((getroot(i),rt[i])==i && i^(getroot(to[i]),rt[to[i]]))ans+=val[i],rt[i]=rt[to[i]];
	}
	return 0&printf("%lld",ans);
}