#include<cstdio>
#include<cstring>
#include<algorithm>
#define reply fflush(stdout)
#define retrun return
#define cpnst const
#define inlien inline
typedef long long ll;
typedef double db;
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
inline int max(int x,int y)
{return(x>y)?x:y;}
int n;
int a[1111111];
ll x0,y0,ax,ay,bx,by,xs,ys,t;
ll px[111],py[111];
inline ll abs(ll x)
{return(x<0)?-x:x;} 
inline ll dis(ll x,ll y,ll xx,ll yy)
{return abs(x-xx)+abs(y-yy);} 
bool vis[111111];
inline int brut(int l,int r,ll xs,ll ys,ll t)
{
	ll x=px[l],y=py[l],xx=px[r],yy=py[r];
	ll d=dis(x,y,xx,yy)+
	min(dis(xs,ys,x,y),
	dis(xs,ys,xx,yy));
	//if(xs<x)d+=x-xs;
	//if(xs>xx)d+=xs-xx;
	//if(ys<y)d+=y-ys;
	//if(ys>yy)d+=ys-yy;
	
	if(t>=d)return r-l+1;
	return 0;
}
void exec()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",
	&x0,&y0,&ax,&ay,&bx,&by,&xs,&ys,&t);
	px[0]=x0,py[0]=y0;
	register int i;
	for(i=1;i<=70;i++)
	{
		if(px[i-1]>1e18/ax)break;
		if(py[i-1]>1e18/ay)break;
		px[i]=px[i-1]*ax+bx;
		py[i]=py[i-1]*ay+by;
	}int tot=i-1;
	//for(i=0;i<=tot;i++)printf("%lld %lld\n",px[i],py[i]);
	register int ii;
	int s=0;
	for(i=0;i<=tot;i++)
		for(ii=i;ii<=tot;ii++)
			s=max(s,brut(i,ii,xs,ys,t));
	printf("%d\n",s);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/