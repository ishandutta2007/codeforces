#include<cstdio>
#include<algorithm>
using namespace std;
struct ed{
	int l,r;
	double ans,ans2;
}e[400001];
void pushup(int m)
{
	e[m].ans=e[m<<1].ans*e[m<<1|1].ans;
	e[m].ans2=e[m<<1].ans2+e[m<<1|1].ans2*e[m<<1].ans;
}
int v[100001][2],n,cnt,m;
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	if(l==r)
	{
		e[m].ans=e[m].ans2=(double)(v[l][1]-v[l][0])/v[l][0];
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	pushup(m);
}
void add(int m,int s,double p)
{
	if(e[m].l==e[m].r)
	{
		if(e[m].l==s)
		e[m].ans=e[m].ans2=(1-p)/p;
		return;
	}
	int mid=(e[m].l+e[m].r)>>1;
	if(s>mid)
	add(m<<1|1,s,p);
	else
	add(m<<1,s,p);
	pushup(m);
}
pair<double,double> que(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	{
		return make_pair(e[m].ans,e[m].ans2);
	}
	if(e[m].l==e[m].r)
	return make_pair(1,0);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
	return que(m<<1|1,l,r);
	else
	if(r<=mid)
	return que(m<<1,l,r);
	else
	{
		pair<double,double> q1=que(m<<1,l,mid);
		pair<double,double> q2=que(m<<1|1,mid+1,r);
		return make_pair(q1.first*q2.first,q1.second+q2.second*q1.first);
	}
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&v[i][0],&v[i][1]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d%d",&b,&c,&d);
			add(1,b,(double)c/d);
		}
		else
		{
			scanf("%d%d",&b,&c);
			printf("%.10lf\n",1/(que(1,b,c).second+1));
		}
	}
}