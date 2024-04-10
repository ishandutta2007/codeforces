#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,t=0,t1=1;
LL ans=-inf;
int a[200002],st[200002],id[200002];
LL pre[200002];
struct Vec
{
	LL x,y;
}p[200002];
inline bool cmp(int x,int y)
{
	return a[x]>a[y];
}
inline Vec mns(Vec a,Vec b)
{
	return (Vec){a.x-b.x,a.y-b.y};
}
inline LL cross(Vec a,Vec b)
{
	return a.x*b.y-a.y*b.x;
}
inline LL calc(int t,int a)
{
	return p[st[t]].y-p[st[t]].x*a;
}
int main()
{
	scanf("%d",&n),p[n]=(Vec){0,0};
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i],p[n-i]=(Vec){-i,-pre[i]},id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=0;i<=n;++i)
	{
		for(;t>1 && cross(mns(p[st[t]],p[st[t-1]]),mns(p[i],p[st[t]]))>=0;--t);
		st[++t]=i;
	}
	for(int i=1;i<=n;++i)
	{
		for(;t1<t && calc(t1,a[id[i]])<=calc(t1+1,a[id[i]]);++t1);
		ans=max(ans,pre[id[i]]-(LL)id[i]*a[id[i]]+calc(t1,a[id[i]]));
	}
	for(int i=1;i<=n;++i)ans+=(LL)i*a[i];
	return 0&printf("%lld",ans);
}