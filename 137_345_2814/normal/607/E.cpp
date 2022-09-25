#include<cstdio>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define ld double
using namespace std;
#define N 100050
long double pi=acos(-1),p[N][2],f[N],s1[N],s2[N];
struct point{ld x,y;}s;
point operator +(point a,point b){return (point){a.x+b.x,a.y+b.y};}
point operator -(point a,point b){return (point){a.x-b.x,a.y-b.y};}
point operator *(point a,ld b){return (point){a.x*b,a.y*b};}
struct vec{point s,t;ld a,b,c,d,e;}v[N];
point intersect(vec a,vec b){ld tp=(a.e-b.e)/(b.d-a.d);return (point){tp,a.e+tp*a.d};}
ld dist(point a,vec b){return (b.a*a.x+b.b*a.y+b.c)/sqrt(b.a*b.a+b.b*b.b);}
ld dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int n,a,b,c,k,cnt,is[N],p2[N][2],t1,t2,fu[N],fr[N],id2[N][2];
int id[N*32],ch[N*32][2],sz[N*32],ct,ct2,rt[N],su1;
int build(int l,int r)
{
	int st=++ct;
	id[st]=ch[st][0]=ch[st][1]=sz[st]=id[st]=0;
	if(l==r)return st;
	int mid=(l+r)>>1;
	ch[st][0]=build(l,mid);
	ch[st][1]=build(mid+1,r);
	return st;
}
void init(){ct=ct2=0;rt[0]=build(1,n);}
int add(int x,int l,int r,int v,int s)
{
	int st=++ct;
	ch[st][0]=ch[x][0];
	ch[st][1]=ch[x][1];
	sz[st]=sz[x]+1;
	id[st]=0;
	if(l==r){id[st]=s;return st;}
	int mid=(l+r)>>1;
	if(mid>=v)ch[st][0]=add(ch[x][0],l,mid,v,s);
	else ch[st][1]=add(ch[x][1],mid+1,r,v,s);
	return st;
}
void adds(int v,int s){rt[ct2+1]=add(rt[ct2],1,n,v,s);ct2++;}
int que1(int x,int x2,int l,int r,int l1,int r1)
{
	if(l==l1&&r==r1)return sz[x]-sz[x2];
	if(!x)return 0;
	int mid=(l+r)>>1;
	if(mid>=r1)return que1(ch[x][0],ch[x2][0],l,mid,l1,r1);
	else if(mid<l1)return que1(ch[x][1],ch[x2][1],mid+1,r,l1,r1);
	else return que1(ch[x][0],ch[x2][0],l,mid,l1,mid)+que1(ch[x][1],ch[x2][1],mid+1,r,mid+1,r1);
}
struct sth{int x,id;friend bool operator <(sth a,sth b){return a.x<b.x;};};
struct node{int l,r;vector<sth> sb;}e[N*4];
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
}
void ins(int x,int l,sth a)
{
	e[x].sb.push_back(a);
	if(e[x].l==e[x].r)return;
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=l)ins(x<<1,l,a);
	else ins(x<<1|1,l,a);
}
double que(int x,int l,int r,int l1,int r1,int id)
{
	if(!e[x].sb.size())return 0;
	if(e[x].l==l&&e[x].r==r)
	{
		int lb=0,rb=e[x].sb.size()-1,as=rb+1,as2=-1;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			if(e[x].sb[mid].x>=l1)as=mid,rb=mid-1;
			else lb=mid+1;
		}
		lb=0,rb=e[x].sb.size()-1;
		while(lb<=rb)
		{
			int mid=(lb+rb)>>1;
			if(e[x].sb[mid].x<=r1)as2=mid,lb=mid+1;
			else rb=mid-1;
		}
		double as1=0;
		for(int j=as;j<=as2;j++)
		{
			int t=id,q=e[x].sb[j].id;
			if(t==q)continue;
			double x1=(v[t].e-v[q].e)/(v[q].d-v[t].d),y=v[q].d*x1+v[q].e;su1++;
			as1+=sqrt((s.x-x1)*(s.x-x1)+(s.y-y)*(s.y-y));
		}
		return as1;
	}
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return que(x<<1,l,r,l1,r1,id);
	else if(mid<l)return que(x<<1|1,l,r,l1,r1,id);
	else return que(x<<1,l,mid,l1,r1,id)+que(x<<1|1,mid+1,r,l1,r1,id);
}
long long check(ld r1)
{
	ct=0;cnt=0;t1=t2=0;
	long long su=0,c1=0,c2=0,c3=0;
	ld as=0;
	for(int i=1;i<=n;i++)is[i]=0;
 	for(int i=1;i<=n;i++)
	{
		ld di=dist(s,v[i]);
		if(di<0)di=-di;
		if(di>r1)continue;
		is[i]=1;c3++;
		if(di<=1e-14)
		{
			ld a=pi-atan2(v[i].a,v[i].b);
			if(a>pi)a-=pi;
			p[i][0]=a;
			p[i][1]=a+pi;
			continue;
		}
		long double st=atan2(v[i].b,v[i].a)+pi;
		if(st>pi)st-=pi;
		ld st1=v[i].d*s.x+v[i].e;
		if(st1>s.y)st+=pi;
		ld d1=sqrt(r1*r1-di*di),f1=atan2(d1,di);
		long double t1=st-f1,t2=st+f1;
		if(t1<0)t1+=pi*2;
		if(t2>2*pi)t2-=pi*2;
		if(t1>t2)swap(t1,t2);
		p[i][0]=t1;
		p[i][1]=t2;
	}
	init();
	for(int i=1;i<=n;i++)if(is[i])s1[++t1]=p[i][0]-1e-18,s2[++t2]=p[i][1]-1e-18;
	sort(s1+1,s1+t1+1);sort(s2+1,s2+t1+1);
	for(int i=1;i<=n;i++)if(is[i])
	{
		int tp=lower_bound(s1+1,s1+t1+1,p[i][0])-s1-1,tp2=lower_bound(s2+1,s2+t1+1,p[i][1])-s2-1;
		id2[i][0]=tp;id2[i][1]=tp2;
		fu[tp]=tp2;fr[tp]=i;
	}
	for(int i=1;i<=c3;i++)adds(fu[i],fr[i]);
	for(int i=1;i<=n;i++)if(is[i])
	{
		int tp1=1,tp2=id2[i][0]-1,tp3=id2[i][0],tp5=lower_bound(s1+1,s1+t1+1,p[i][1]+2e-18)-s1-1;
		int v1=lower_bound(s2+1,s2+t1+1,p[i][0]-2e-18)-s2,v2=id2[i][1],v3=v2;
		su+=que1(rt[tp3],0,1,n,v1,v2)+que1(rt[tp5],rt[tp2],1,n,v3,n);
	}
	return su/2-c3;
}
ld solve(ld r1)
{
	ct=0;cnt=0;t1=t2=0;
	long long c1=0,c2=0,c3=0;
	ld as=0;
	for(int i=1;i<=n;i++)is[i]=0;
 	for(int i=1;i<=n;i++)
	{
		long double di=dist(s,v[i]);
		if(di<0)di=-di;
		if(di>r1)continue;
		is[i]=1;c3++;
		if(di<=1e-14)
		{
			ld a=pi-atan2(v[i].a,v[i].b);
			if(a>pi)a-=pi;
			p[i][0]=a;
			p[i][1]=a+pi;
			continue;
		}
		long double st=atan2(v[i].b,v[i].a)+pi;
		if(st>pi)st-=pi;
		ld st1=v[i].d*s.x+v[i].e;
		if(st1>s.y)st+=pi;
		long double d1=sqrt(r1*r1-di*di),f1=atan2(d1,di);
		long double t1=st-f1,t2=st+f1;
		if(t1<0)t1+=pi*2;
		if(t2>2*pi)t2-=pi*2;
		if(t1>t2)swap(t1,t2);
		p[i][0]=t1;
		p[i][1]=t2;
	}
	init();
	for(int i=1;i<=n;i++)if(is[i])s1[++t1]=p[i][0]-1e-18,s2[++t2]=p[i][1]-1e-18;
	sort(s1+1,s1+t1+1);sort(s2+1,s2+t1+1);
	for(int i=1;i<=n;i++)if(is[i])
	{
		int tp=lower_bound(s1+1,s1+t1+1,p[i][0])-s1-1,tp2=lower_bound(s2+1,s2+t1+1,p[i][1])-s2-1;
		fu[tp]=tp2;fr[tp]=i;id2[i][0]=tp;id2[i][1]=tp2;
	}
	build(1,1,n);
	for(int i=1;i<=c3;i++)ins(1,i,(sth){fu[i],fr[i]});
	for(int i=1;i<n*4;i++)sort(e[i].sb.begin(),e[i].sb.end());
	for(int i=1;i<=n;i++)if(is[i])
	{
		int tp1=1,tp2=id2[i][0]-1,tp3=id2[i][0],tp5=lower_bound(s1+1,s1+t1+1,p[i][1]+2e-18)-s1-1;
		int v1=lower_bound(s2+1,s2+t1+1,p[i][0]-2e-18)-s2,v2=id2[i][1],v3=v2;
		as+=que(1,1,tp3,v1,v2,i)+que(1,tp2+1,tp5,v3,n,i);
	}
	as=as/2+(k-su1/2)*r1;
	if(as<0)as=0;
	return as;
}
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	int fg2=0;s.x=a/1000.0;s.y=b/1000.0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);v[i].s=(point){10*1.0,(a*10+b)/1000.0};v[i].t=(point){10*-1.0,(-a*10+b)/1000.0};
		v[i].a=a/1000.0;v[i].b=-1;v[i].c=b/1000.0;
		v[i].d=a/1000.0;v[i].e=b/1000.0;
	}
	ld lb=-1e-7,rb=3e9,as=lb;
	for(int r=1;r<=65;r++)
	{
		ld mid=(lb+rb)/2;
		long long tp=check(mid);
		if(tp<k)as=mid;
		if(tp<k)lb=mid;
		else rb=mid;
	}
	printf("%.15lf\n",(double)solve(as));
}//.....................