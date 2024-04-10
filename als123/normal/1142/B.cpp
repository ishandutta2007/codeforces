#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
const int N=200005;
int n,m,q;
int a[N],b[N];
int nxt[N];
int f[N][20];
int pos[N];
int calc (int x)
{
	//printf("YES:%d\n",x);
	int t=n-1;
	for (int u=19;u>=0;u--)
	{
		if ((1<<u)<=t)
		{
			t=t-(1<<u);
			x=f[x][u];
			//printf("fail:%d %d\n",u,x);
			if (x==-1) return m+1;
		}
	}
	return x;
}
int g[N];
struct qq
{
	int l,r;
	int s1,s2;
	int c;
}tr[N*2];int num;
void bt (int l,int r)
{
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	if (l==r)	{tr[now].c=g[l];return ;}
	int mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
	tr[now].c=min(tr[tr[now].s1].c,tr[tr[now].s2].c);
}
int query (int now,int l,int r)
{
//	printf("%d %d %d %d\n",l,r,tr[now].l,tr[now].r);
	if (tr[now].l==l&&tr[now].r==r) return tr[now].c;
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) return query(s1,l,r);
	else if (l>mid) return query(s2,l,r);
	else return min(query(s1,l,mid),query(s2,mid+1,r));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);a[n+1]=a[1];
	for (int u=1;u<=n;u++) nxt[a[u]]=a[u+1];
	for (int u=1;u<=m;u++) scanf("%d",&b[u]);
	memset(pos,-1,sizeof(pos));
	memset(f,-1,sizeof(f));
	for (int u=m;u>=1;u--)
	{
		pos[b[u]]=u;g[u]=m+1;
		int x=pos[nxt[b[u]]];
		if (x==-1) continue;
		f[u][0]=x;for (int i=1;i<20;i++) f[u][i]=f[f[u][i-1]][i-1];
		int r=calc(u);
		g[u]=r;
	//	printf("%d %d %d\n",u,x,g[u]);
	}
	/*for (int u=1;u<=m;u++) printf("%d ",g[u]);
	printf("\n");*/
	bt(1,m);
	for (int u=1;u<=q;u++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if (query(1,l,r)<=r)
		{
			printf("1");
		}
		else printf("0");
	}
	return 0;
}