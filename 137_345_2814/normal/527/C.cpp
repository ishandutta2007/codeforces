#include<cstdio>
using namespace std;
struct edge{
	int l,r,sz;
}e[800006][5];
void build(int m,int l,int r,int x)
{
	e[m][x].l=l;
	e[m][x].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(m<<1,l,mid,x);
	build(m<<1|1,mid+1,r,x);
}
void add(int m,int x,int y,int t)
{
	if(e[m][t].l==e[m][t].r&&e[m][t].l==x)
	{e[m][t].sz+=y;return;}
	int mid=(e[m][t].l+e[m][t].r)>>1;
	if(mid>=x) add(m<<1,x,y,t);
	else add(m<<1|1,x,y,t);
	e[m][t].sz=e[m<<1][t].sz+e[m<<1|1][t].sz;
}
int fnd(int m,int t)
{	
	if(e[m][t].l==e[m][t].r)
	return e[m][t].l;
	if(e[m<<1|1][t].sz)
	return fnd(m<<1|1,t);	
	return fnd(m<<1,t);
}
int query(int m,int x,int t)
{
//	printf("%d %d %d %d\n",e[m][t].l,e[m][t].r,x,t);
	if(e[m][t].l==e[m][t].r)
	return e[m][t].l;
	if(e[m<<1][t].sz>=x)
	return query(m<<1,x,t);
	else
	return query(m<<1|1,x-e[m<<1][t].sz,t);
}
int que(int m,int r,int t)
{
	if(e[m][t].r==r)
	return e[m][t].sz;
	int mid=(e[m][t].l+e[m][t].r)>>1;
	if(mid>=r)
	return que(m<<1,r,t);
	else
	return e[m<<1][t].sz+que(m<<1|1,r,t);
}
int n,m,k,s;
char f;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	build(1,1,n,1);
	build(1,1,m,2);
	build(1,1,n+1,3);
	build(1,1,m+1,4);
	add(1,n,1,1);
	add(1,m,1,2);
	add(1,1,1,3);add(1,n+1,1,3);
	add(1,1,1,4);add(1,m+1,1,4);
	for(int i=1;i<=k;i++)
	{
		scanf("\n%c%d",&f,&s);
		if(f=='V')
		{
			int tmp=que(1,s+1,3);
			int lb=query(1,tmp,3),rb=query(1,tmp+1,3);
//			printf("%d %d %d\n",s+1,lb,rb);
			add(1,rb-lb,-1,1);
			add(1,rb-s-1,1,1);
			add(1,s+1-lb,1,1);
			add(1,s+1,1,3);
		}
		else
		{
			int tmp=que(1,s+1,4);
			int lb=query(1,tmp,4),rb=query(1,tmp+1,4);
			add(1,rb-lb,-1,2);
			add(1,rb-s-1,1,2);
			add(1,s+1-lb,1,2);
			add(1,s+1,1,4);
		}
		printf("%lld\n",1ll*fnd(1,1)*fnd(1,2));
	}
}