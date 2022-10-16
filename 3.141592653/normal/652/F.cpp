#include<bits/stdc++.h>
typedef long long ll;
int n,m,ans[1111111];
ll t;
struct pnt{int x,d,Id,Idd;}p[1111111],q[1111111],r[1111111];
bool operator<(const pnt x,const pnt y){if(x.x^y.x)return x.x<y.x;return x.d<y.d;}
bool incId(const pnt x,const pnt y){return x.Id<y.Id;}
ll calc(int x,int y)
{
	int dt=y-x;
	if(dt<0)dt+=m;
	ll K=m-dt+t*2;
	return K/m;
}
int main()
{
	scanf("%d%d%lld",&n,&m,&t);
	register int i;
	for(i=1;i<=n;i++)
	{
		char c[4];
		scanf("%d%s",&p[i].x,c),p[i].Id=i;
		if(*c=='R')p[i].d=1;
		else p[i].d=-1;
	}std::sort(p+1,p+n+1);
	for(i=1;i<=n;i++)p[i].Idd=i,q[i]=p[i],q[i].x=(q[i].x+q[i].d*t%m+m-1)%m+1;
	std::sort(q+1,q+n+1);
	ll shift=0;
	for(i=2;i<=n;i++)
		if(p[i].d!=p[1].d)
		{
			if(p[1].d>0)(shift+=calc(p[1].x,p[i].x))%=n;
			else(shift+=n-calc(p[i].x,p[1].x)%n)%=n;
		}
	int loc=1,tot=0;
	for(i=1;i<=n;i++)if(q[i].Idd==1)loc=i;
	loc=(loc+n-shift-1)%n+1;
	for(i=loc;i<=n;i++)r[++tot]=q[i];
	for(i=1;i<loc;i++)r[++tot]=q[i];
	for(i=1;i<=n;i++)ans[p[i].Id]=r[i].x;
	for(i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
}
/*
Please don't let me down.
*/