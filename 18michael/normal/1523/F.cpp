#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,Mx,ans=0;
int X[16],Y[16];
int f[16384][102],g[16384][102],mnf[16384][16],mng[16384][102];
struct aaa
{
	int x,y,t;
}a[102];
inline bool cmp(aaa a,aaa b)
{
	return a.t<b.t;
}
inline void updf(int &x,int y)
{
	if(y<x)x=y;
}
inline void updg(int &x,int y)
{
	if(y>x)x=y;
}
int main()
{
	scanf("%d%d",&n,&m),Mx=(1<<n);
	for(int i=0;i<n;++i)scanf("%d%d",&X[i],&Y[i]);
	for(int i=1;i<=m;++i)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
	sort(a+1,a+m+1,cmp);
	for(int i=0;i<Mx;++i)
	{
		for(int j=0;j<n;++j)
		{
			mnf[i][j]=inf;
			for(int k=0;k<n;++k)if((i>>k)&1)mnf[i][j]=min(mnf[i][j],abs(X[k]-X[j])+abs(Y[k]-Y[j]));
		}
		for(int j=1;j<=m;++j)
		{
			mng[i][j]=inf;
			for(int k=0;k<n;++k)if((i>>k)&1)mng[i][j]=min(mng[i][j],abs(X[k]-a[j].x)+abs(Y[k]-a[j].y));
		}
	}
	for(int i=0;i<Mx;++i)for(int j=0;j<=m;++j)f[i][j]=inf,g[i][j]=-inf;
	for(int i=0;i<n;++i)f[1<<i][0]=0;
	for(int i=1;i<=m;++i)g[0][i]=1;
	for(int i=0;i<Mx;++i)
	{
		for(int j=0;j<=m;++j)
		{
			for(int k=0;k<n;++k)if(!((i>>k)&1))updf(f[i|(1<<k)][j],f[i][j]+mnf[i][k]);
			for(int k=1;k<=m;++k)if(f[i][j]+mng[i][k]<=a[k].t)updg(g[i][k],j+1);
		}
		for(int j=1;j<=m;++j)
			if(g[i][j]>=0)
			{
				for(int k=0;k<n;++k)if(!((i>>k)&1))updf(f[i|(1<<k)][g[i][j]],a[j].t+min(mnf[i][k],abs(a[j].x-X[k])+abs(a[j].y-Y[k])));
				for(int k=j+1;k<=m;++k)if(a[j].t+min(mng[i][k],abs(a[j].x-a[k].x)+abs(a[j].y-a[k].y))<=a[k].t)updg(g[i][k],g[i][j]+1);
			}
	}
	for(int i=0;i<Mx;++i)for(int j=1;j<=m;++j)updg(ans,g[i][j]);
	return 0&printf("%d",ans);
}