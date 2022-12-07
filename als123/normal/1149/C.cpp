#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005*2;
struct qq
{
	int l,r;
	int s1,s2;
	int c1,c2,l1,l2,r1,r2;
	int c;
}tr[N*2];int num;
char ss[N];
int n,q;
int a[N];
//c1---]                c2---[
//l1---max( ] + [ )     l2---max( [ - ] )
//r1---max( ] + [ )     r2---max( ] - [ )
void calc (int now,int x)
{
	if (x==1)//[
	{
		tr[now].c=1;
		tr[now].c1=0;tr[now].c2=1;
		tr[now].l1=1;tr[now].r1=1;
		tr[now].l2=1;tr[now].r2=0;
	}
	else
	{
		tr[now].c=1;
		tr[now].c1=1;tr[now].c2=0;
		tr[now].l1=1;tr[now].r1=1;
		tr[now].l2=0;tr[now].r2=1;
	}
}
void update (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c=max(max(tr[s1].r1+tr[s2].l2,tr[s1].r2+tr[s2].l1),max(tr[s1].c,tr[s2].c));
	
	tr[now].c1=tr[s1].c1+max(0,tr[s2].c1-tr[s1].c2);
	tr[now].c2=tr[s2].c2+max(0,tr[s1].c2-tr[s2].c1);
	
	tr[now].l1=max(tr[s1].l1,max(tr[s2].l1+tr[s1].c1-tr[s1].c2,tr[s2].l2+tr[s1].c1+tr[s1].c2));
	tr[now].l2=max(tr[s1].l2,tr[s2].l2+tr[s1].c2-tr[s1].c1);
	
	tr[now].r1=max(tr[s2].r1,max(tr[s1].r1+tr[s2].c2-tr[s2].c1,tr[s1].r2+tr[s2].c1+tr[s2].c2));
	tr[now].r2=max(tr[s2].r2,tr[s1].r2+tr[s2].c1-tr[s2].c2);
}
void bt (int l,int r)
{
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	if (l==r)	{calc(now,a[l]);return ;}
	int mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
	update(now);
}
void change (int now,int x)
{
	if (tr[now].l==tr[now].r)
	{
		calc(now,a[x]);
		return ;
	}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) change(s1,x);
	else change(s2,x);
	update(now);
}
int main()
{
	scanf("%d%d",&n,&q);n=2*n-2;
	scanf("%s",ss+1);
	for (int u=1;u<=n;u++)
	{
		if (ss[u]=='(') a[u]=1;
		else a[u]=-1;
	}
	bt(1,n);
	printf("%d\n",tr[1].c);
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		swap(a[x],a[y]);
		change(1,x);change(1,y);
		printf("%d\n",tr[1].c);
	}
	return 0;
}