#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005;
const int M=500010;
int n,m,q;
int X[M],Y[M],Z[M];
struct qt
{
	vector<int> a;
	void print ()
	{
		printf("OZY:");
		for (int u=0;u<a.size();u++) printf("%d ",a[u]);
		printf("\n");
	};
};// 
struct qq
{
	int l,r;
	qt c;
	int s1,s2;
}tr[M*2];int num;
int f[N],g[N];
int find (int x)
{
	if (f[x]==x) return f[x];
	int t=f[x];f[x]=find(f[x]);g[x]=(g[x]^g[t]);
	return f[x];
}
int p[N*2];
qt Merge (qt x,qt y)// 
{
	int cnt=0;
	qt o;
	int a=x.a.size(),b=y.a.size();
	int now=0,now1=0;
	while (now<a&&now1<b)
	{
		if (Z[x.a[now]]>Z[y.a[now1]])	p[++cnt]=x.a[now++];
		else p[++cnt]=y.a[now1++];
	}
	while (now<a) p[++cnt]=x.a[now++];
	while (now1<b) p[++cnt]=y.a[now1++];
	for (int u=1;u<=n;u++) f[u]=u,g[u]=0;
	for (int u=1;u<=cnt;u++)
	{
		int xx=X[p[u]],yy=Y[p[u]];
		int fx=find(xx),fy=find(yy);
		if (fx!=fy)// 
		{
			g[fx]=(g[xx]^g[yy]^1);
			f[fx]=fy;
			o.a.push_back(p[u]);
		}
		else if (g[xx]!=g[yy]) continue;
		else
		{
			o.a.push_back(p[u]);break;
		}
	}
	return o;
}
void bt (int l,int r)
{
	int a=++num;
	tr[a].l=l;tr[a].r=r;
	if (l==r)	{tr[a].c.a.push_back(l);return ;}
	int mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
	tr[a].c=Merge(tr[tr[a].s1].c,tr[tr[a].s2].c);
}
qt find (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)
	{
		return tr[now].c;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) return find(s1,l,r);
	else if (l>mid) return find(s2,l,r);
	else return Merge(find(s1,l,mid),find(s2,mid+1,r));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int u=1;u<=m;u++)	scanf("%d%d%d",&X[u],&Y[u],&Z[u]);
	num=0;bt(1,m);
	for (int u=1;u<=q;u++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		qt ans=find(1,l,r);
		int tot=ans.a.size();
		int lalal=-1;
		for (int u=1;u<=n;u++) f[u]=u;
	//	printf("%d\n",tot);
		for (int u=0;u<tot;u++)
		{
			int x=X[ans.a[u]],y=Y[ans.a[u]],z=Z[ans.a[u]];
		//	printf("YES:%d %d\n",x,y);
			int fx=find(x),fy=find(y);
			if (fx!=fy)	f[fx]=fy;
			else {lalal=z;break;}
		}
		printf("%d\n",lalal);
	}
	return 0;
}