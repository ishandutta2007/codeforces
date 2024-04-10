#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
	int l,r,mx;
}e[400002];
int n,m,k,q,a,b,c,d;
void pushup(int m)
{
	e[m].mx=min(e[m<<1].mx,e[m<<1|1].mx);
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	e[m].mx=0;
	if(l==r)
	return;
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
}
void add(int m,int x,int y)
{
	if(e[m].l==e[m].r&&e[m].l==x)
	{
		e[m].mx=y;
		return;
	}
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=x)
	add(m<<1,x,y);
	else
	add(m<<1|1,x,y);
	pushup(m);
}
int que(int m,int l,int r)
{
//	printf("%d %d %d %d %d\n",m,l,r,e[m].l,e[m].r);
	if(e[m].l==l&&e[m].r==r)
	return e[m].mx;
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=r)
	return que(m<<1,l,r);
	else
	if(mid<l)
	return que(m<<1|1,l,r);
	else
	return min(que(m<<1,l,mid),que(m<<1|1,mid+1,r));
}
struct node{
	int x,y,xx,yy,s;
}q1[200004];
struct node2{
	int x,y;
}q2[200004];
bool cmp(node a,node b)
{return a.yy<b.yy;}
bool cmp1(node a,node b)
{return a.xx<b.xx;}
bool cmp2(node2 a,node2 b)
{return a.x<b.x;}
bool cmp3(node2 a,node2 b)
{return a.y<b.y;}
int ans[200001];
inline int read()
{
	int ans=0;
	char c='l';
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	ans=(ans<<3)+(ans<<1)+c-'0',c=getchar();
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;i++)
	q2[i].x=read(),q2[i].y=read();
	for(int i=1;i<=q;i++)
	q1[i].x=read(),q1[i].y=read(),q1[i].xx=read(),q1[i].yy=read(),q1[i].s=i;
	sort(q1+1,q1+q+1,cmp);
	sort(q2+1,q2+k+1,cmp3);
	build(1,1,n);
	int st=1,nt=1;
	for(int i=1;i<=m;i++)
	{
		while(q2[nt].y==i)add(1,q2[nt].x,q2[nt].y),nt++;
		while(q1[st].yy==i)
		{
			if(que(1,q1[st].x,q1[st].xx)>=q1[st].y) ans[q1[st].s]=1;
			st++;
		}
	}
	sort(q1+1,q1+q+1,cmp1);
	sort(q2+1,q2+k+1,cmp2);
	build(1,1,m);
	st=1,nt=1;
	for(int i=1;i<=n;i++)
	{
		while(q2[nt].x==i)add(1,q2[nt].y,q2[nt].x),nt++;
		while(q1[st].xx==i)
		{
			if(que(1,q1[st].y,q1[st].yy)>=q1[st].x) ans[q1[st].s]=1;
			st++;
		}
	}
	for(int i=1;i<=q;i++)
	if(ans[i])
	printf("YES\n");
	else
	printf("NO\n");
}