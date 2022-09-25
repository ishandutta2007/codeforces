#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
#define N 1505
struct point{double x,y;}q2[N],p[N],as[N],as2,as3;
point operator +(point a,point b){return (point){a.x+b.x,a.y+b.y};}
point operator -(point a,point b){return (point){a.x-b.x,a.y-b.y};}
point operator *(point a,double b){return (point){a.x*b,a.y*b};}
struct vec{point s,t;double ag;}ed[N],ed2[N],ed3[N],q[N];
int hd,tl,n,m,f[N];
double ag[N],rag[N],pi=acos(-1);
double cross(point x,point y,point z,point l){return (y.x-x.x)*(l.y-z.y)-(l.x-z.x)*(y.y-x.y);}
bool cmp(vec a,vec b)
{
	if(abs(a.ag-b.ag)<=1e-8)return cross(a.s,a.t,a.s,b.t)<0;
	return a.ag<b.ag;
}
point ins(vec a,vec b){return a.s+(a.t-a.s)*(cross(a.s,b.s,a.s,b.t)/(cross(a.s,b.s,a.s,a.t)+cross(a.s,a.t,a.s,b.t)));}
bool si(int s1,int s2)
{
	int tp=clock();
	q[1]=ed[1];hd=tl=1;
	int v1=2,v2=1;
	if(ed[1].ag>ed2[1].ag)v1=1,v2=2,q[1]=ed2[1];
	if(abs(ed[1].ag-ed2[1].ag)<=1e-8)
	{
		if(cmp(ed[1],ed2[1])==1)q[1]=ed[1];
		else q[1]=ed2[1];
		v1=v2=2;
	}
	for(int i=2;i<=s1+s2;i++)
	{
		int fg=0;
		if(v1==s1+1&&v2==s2+1)break;
		if(v2==s2+1)fg=1;
		else if(v1==s1+1)fg=0;
		else
		{
			if(abs(ed[v1].ag-ed2[v2].ag)<=1e-8)
			if(cmp(ed[v1],ed2[v2])==1)fg=1,v2++;
			else fg=0,v1++;
			else
			if(ed[v1].ag<ed2[v2].ag)fg=1;
			else fg=0;
		}
		if(fg)
		{
			if(hd<tl&&(cross(q[hd].s,q[hd].t,q[hd+1].s,q[hd+1].t)==0||cross(q[tl-1].s,q[tl-1].t,q[tl].s,q[tl].t)==0))return 0;
			while(hd<tl&&cross(ed[v1].s,ed[v1].t,ed[v1].s,q2[tl-1])<0)tl--;
			while(hd<tl&&cross(ed[v1].s,ed[v1].t,ed[v1].s,q2[hd])<0)hd++;
			q[++tl]=ed[v1];
			if(hd<tl)q2[tl-1]=ins(q[tl-1],q[tl]);
			v1++;
		}
		else
		{
			if(hd<tl&&(cross(q[hd].s,q[hd].t,q[hd+1].s,q[hd+1].t)==0||cross(q[tl-1].s,q[tl-1].t,q[tl].s,q[tl].t)==0))return 0;
			while(hd<tl&&cross(ed2[v2].s,ed2[v2].t,ed2[v2].s,q2[tl-1])<0)tl--;
			while(hd<tl&&cross(ed2[v2].s,ed2[v2].t,ed2[v2].s,q2[hd])<0)hd++;
			q[++tl]=ed2[v2];
			if(hd<tl)q2[tl-1]=ins(q[tl-1],q[tl]);
			v2++;
		}
	}
	while(hd<tl&&cross(q[hd].s,q[hd].t,q[hd].s,q2[tl-1])<0)tl--;
	while(hd<tl&&cross(q[tl].s,q[tl].t,q[tl].s,q2[hd])<0)hd++;
	if(tl-hd<=1)return 0;
	q2[tl]=ins(q[hd],q[tl]);
	int ct=0;
	for(int i=hd;i<=tl;i++)
	{
		point a=q2[i],b=q2[i==tl?hd:i+1];
		if(!(abs(a.x-b.x)<=1e-14&&abs(a.y-b.y)<=1e-14))ct++;
	}
	return ct;
}
int cnt=0;
bool check(int l,int r,double mid)
{
	int ct=0;cnt++;
	for(int i=1;i<=n;i++)ed[++ct]=(vec){p[i],p[i==n?1:i+1],ag[i]};
	ct=0;
	for(int i=l;i<=r;i++)
	{
		ed2[++ct]=(vec){p[i%n+1],p[(i-1)%n+1],rag[(i-1)%n+1]};
		double dis=sqrt((ed2[ct].t.y-ed2[ct].s.y)*(ed2[ct].t.y-ed2[ct].s.y)+(ed2[ct].t.x-ed2[ct].s.x)*(ed2[ct].t.x-ed2[ct].s.x));
		point tp=ed2[ct].t-ed2[ct].s;tp=tp*(mid/dis);
		point tp2=(point){tp.y,-tp.x};
		ed2[ct].s=ed2[ct].s+tp2,ed2[ct].t=ed2[ct].t+tp2;
	}
	int mn1=1;
	for(int i=1;i<=n;i++)if(ed[i].ag<ed[mn1].ag)mn1=i;
	for(int i=1;i<=n;i++)ed3[i]=ed[i];
	for(int i=1;i<=n;i++)ed[(i+n-mn1)%n+1]=ed3[i];
	mn1=1;
	for(int i=1;i<=ct;i++)if(ed2[i].ag<ed2[mn1].ag)mn1=i;
	for(int i=1;i<=ct;i++)ed3[i]=ed2[i];
	for(int i=1;i<=ct;i++)ed2[(i+ct-mn1)%ct+1]=ed3[i];
	if(!si(n,ct))return 0;
	as[l]=q2[hd];return 1;
}
bool solve(double mid)
{
	for(int i=1;i<=n;i++)
	{
		int las=f[i-1]-1;
		if(las<i)las=i;
		while(1)
		if(las<n+i&&check(i,las+1,mid))las++;
		else break;
		f[i]=las;
	}
	for(int i=1;i<=n;i++)
	if(f[i]>=n+i-1){as2=as3=as[i];return 1;}
	for(int i=1;i<=n;i++)
	if(f[f[i]%n+1]>=n+i-1){as2=as[i],as3=as[f[i]%n+1];return 1;}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)
	{
		vec a=(vec){p[i],p[i==n?1:i+1],0};
		ag[i]=atan2(a.t.y-a.s.y,a.t.x-a.s.x);
		rag[i]=atan2(a.s.y-a.t.y,a.s.x-a.t.x);
	}
	double lb=0,rb=1e5,as=1e5;
	for(int i=1;i<=60;i++)
	{
		double mid=(lb+rb)/2;
		if(solve(mid))rb=mid,as=rb;
		else lb=mid;
	}
	printf("%.10lf\n%.10lf %.10lf\n%.10lf %.10lf\n",as,as2.x,as2.y,as3.x,as3.y);
}