#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,k,a_t=0;
LL ans=0;
LL f[202][52],g[202][52];
bitset<502> bs[502][502];
struct aaa
{
	int x,y;
	double k;
}a[250002];
inline bool cmp(aaa a,aaa b)
{
	return a.k<b.k? 1:0;
}
struct Vec
{
	LL x,y;
}p[202];
inline Vec mns(Vec a,Vec b)
{
	return (Vec){a.x-b.x,a.y-b.y};
}
inline LL cross(Vec a,Vec b)
{
	return a.x*b.y-a.y*b.x;
}
inline void upd(LL &x,LL y)
{
	if(y>x)x=y;
}
inline void solve(int x)
{
	for(int i=1;i<=n;++i)for(int j=0;j<=k;++j)f[i][j]=g[i][j]=-Inf;
	f[x][0]=g[x][0]=0;
	for(int i=a_t;i;--i)
	{
		if(a[i].x==x)
		{
			upd(f[a[i].y][1],0);
			continue;
		}
		if((bs[x][a[i].y]&bs[a[i].y][a[i].x]&bs[a[i].x][x]).count())continue;
		for(int j=0;j<k;++j)upd(f[a[i].y][j+1],f[a[i].x][j]+cross(mns(p[a[i].y],p[x]),mns(p[a[i].x],p[x])));
	}
	for(int i=1;i<=a_t;++i)
	{
		if(a[i].x==x)
		{
			upd(g[a[i].y][1],0);
			continue;
		}
		if((bs[x][a[i].x]&bs[a[i].x][a[i].y]&bs[a[i].y][x]).count())continue;
		for(int j=0;j<k;++j)upd(g[a[i].y][j+1],g[a[i].x][j]+cross(mns(p[a[i].x],p[x]),mns(p[a[i].y],p[x])));
	}
	for(int i=1;i<=n;++i)for(int j=0;j<=k;++j)ans=max(ans,f[i][j]+g[i][k-j]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&p[i].x,&p[i].y);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(j!=i)
	{
		if(p[i].x<=p[j].x)a[++a_t]=(aaa){i,j,p[i].x==p[j].x? (p[i].y<p[j].y? inf:-inf):1.0*(p[j].y-p[i].y)/(p[j].x-p[i].x)};
		for(int k=1;k<=n;++k)if(k!=i && k!=j && cross(mns(p[i],p[k]),mns(p[j],p[k]))>0)bs[i][j].set(k);
	}
	sort(a+1,a+a_t+1,cmp);
	for(int i=1;i<=n;++i)solve(i);
	return 0&printf("%.2lf",ans/2.0);
}