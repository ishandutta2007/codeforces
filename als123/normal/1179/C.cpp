#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1e6+5;
struct qq
{
	int l,r;
	int lzy;
	int c;
	int s1,s2;
}tr[N*2];int num;
void upd (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c=min(tr[s1].c,tr[s2].c);
}
void modify (int now,int c)	{tr[now].lzy+=c;tr[now].c+=c;}
void Push_down (int now)
{
	if (tr[now].lzy==0) return ;
	modify(tr[now].s1,tr[now].lzy);
	modify(tr[now].s2,tr[now].lzy);
	tr[now].lzy=0;
}
void bt (int l,int r)
{
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	if (l==r) return ;
	int mid=(tr[now].l+tr[now].r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
}
void add (int now,int l,int r,int c)
{
	if (tr[now].l==l&&tr[now].r==r) 	{modify(now,c);return ;}
	Push_down(now);
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) add(s1,l,r,c);
	else if (l>mid) add(s2,l,r,c);
	else add(s1,l,mid,c),add(s2,mid+1,r,c);
	upd(now);
}
int query (int now)
{
	if (tr[now].l==tr[now].r) return tr[now].l;
	Push_down(now);
	int s1=tr[now].s1,s2=tr[now].s2;
	if (tr[s2].c<0) return query(s2);
	else return query(s1);
}
int n,m;
int a[N],b[N];
int main()
{
	bt(1,1e6);
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);
		add(1,1,a[u],-1);
	}
	for (int u=1;u<=m;u++)
	{
		scanf("%d",&b[u]);
		add(1,1,b[u],1);
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if (op==1)
		{
			add(1,1,a[x],1);
			a[x]=y;
			add(1,1,a[x],-1);
		}
		else
		{
			add(1,1,b[x],-1);
			b[x]=y;
			add(1,1,b[x],1);
		}
		if (tr[1].c>=0) printf("-1\n");
		else printf("%d\n",query(1));
	}
	return 0;
}