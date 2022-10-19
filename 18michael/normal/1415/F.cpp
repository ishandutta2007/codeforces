#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n;
LL l,r;
bool ok;
LL t[5002],X[5002];
LL f[5002][2];
inline void upd(LL &x,LL y)
{
	if(y<x)x=y;
}
inline void calc(LL sx,LL st,LL ex,LL et,LL t)
{
	if(et-st<abs(ex-sx))ok=0;
	else l=min(l,max(min(sx,ex)-(et-st-abs(ex-sx))/2,ex-t)),r=max(r,min(max(sx,ex)+(et-st-abs(ex-sx))/2,ex+t));
}
inline bool check(LL x)
{
	return l<=x && x<=r;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld%lld",&t[i],&X[i]),f[i][0]=f[i][1]=inf;
	f[0][0]=0,f[0][1]=inf;
	for(int i=0;i<n;++i)
	{
		if(ok=(f[i][1]<inf))
		{
			if(f[i][1]>=t[i])l=r=X[i-1];
			else l=inf,r=-inf;
		}
		for(int j=i+1;j<=n && ok;++j)
		{
			if(j==i+1)
			{
				if(check(X[j]) && f[i][1]<=t[j])upd(f[j][1],max(f[i][1],t[i]));
				if(f[i][1]+abs(X[j]-X[i-1])<=t[j])upd(f[j][0],max(f[i][1]+abs(X[j]-X[i-1]),t[i]));
				calc(X[i-1],f[i][1],X[j],t[j],t[j]-t[i]);
			}
			else
			{
				if(check(X[j]) && t[j-1]<=t[j])upd(f[j][1],max(t[j-1],t[i]));
				if(t[j-1]+abs(X[j]-X[j-1])<=t[j])upd(f[j][0],max(t[j-1]+abs(X[j]-X[j-1]),t[i]));
				calc(X[j-1],t[j-1],X[j],t[j],t[j]-t[i]);
			}
		}
		if(ok=(f[i][0]<inf))
		{
			if(f[i][0]>=t[i])l=r=X[i];
			else l=inf,r=-inf;
		}
		for(int j=i+1;j<=n && ok;++j)
		{
			if(j==i+1)
			{
				if(check(X[j]) && f[i][0]<=t[j])upd(f[j][1],max(f[i][0],t[i]));
				if(f[i][0]+abs(X[j]-X[i])<=t[j])upd(f[j][0],max(f[i][0]+abs(X[j]-X[i]),t[i]));
				calc(X[j-1],f[i][0],X[j],t[j],t[j]-t[i]);
			}
			else
			{
				if(check(X[j]) && t[j-1]<=t[j])upd(f[j][1],max(t[j-1],t[i]));
				if(t[j-1]+abs(X[j]-X[j-1])<=t[j])upd(f[j][0],max(t[j-1]+abs(X[j]-X[j-1]),t[i]));
				calc(X[j-1],t[j-1],X[j],t[j],t[j]-t[i]);
			}
		}
	}
	return 0&puts(min(f[n][0],f[n][1])<inf? "YES":"NO");
}