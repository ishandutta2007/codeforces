#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=100005;
int n,m,X;
struct qt
{
	LL tot;
	int c[21],c1[21];
	int l,r;
	void print()
	{
		printf("l:%d r:%d tot:%d\n",l,r,tot);
		for (int u=0;u<=5;u++) printf("%d ",c[u]);
		printf("\n");
		for (int u=0;u<=5;u++) printf("%d ",c1[u]);
		printf("\n");
	}
};
struct qq
{
	int l,r;
	int s1,s2;
	qt c;
}tr[N*2];int num;
int a[N];
void calc (int now,int x,int xx)
{
	for (int u=0;u<=20;u++)
	{
		int t=(1<<u);
		if ((t&xx)!=0)	tr[now].c.c[u]=tr[now].c.c1[u]=x;
		else tr[now].c.c[u]=tr[now].c.c1[u]=-1;
	}
	tr[now].c.tot=(xx>=X);
}
struct qr
{
	int x,id;
};
int f[100],g[100];
bool cmp (qr x,qr y)	{return x.id>y.id;}	
qr A[50],B[50];
qt Merge (qt x,qt y)
{
	if (x.tot==-1) return y;
//	printf("x:");x.print();
//	printf("y:");y.print();
	qt ans;

	for (int u=0;u<=20;u++)
	{
		if (x.c[u]==-1) ans.c[u]=y.c[u];
		else ans.c[u]=x.c[u];
		ans.c1[u]=max(x.c1[u],y.c1[u]);
	}
	ans.l=x.l;ans.r=y.r;
	ans.tot=x.tot+y.tot;
	for (int u=0;u<=20;u++)	{A[u].x=(1<<u);A[u].id=x.c1[u];}
	for (int u=0;u<=20;u++)	{B[u].x=(1<<u);B[u].id=y.c[u];}
	B[21].id=y.l;	B[21].x=0;
	A[21].id=x.r;	A[21].x=0;
	sort(A,A+22,cmp);
	sort(B,B+22,cmp);
	//A
	for (int u=0;u<=21;u++)	{f[u]=f[u-1];if (A[u].id==-1) break;f[u]|=(A[u].x);}
	for (int u=21;u>=0;u--)	{g[u]=g[u+1];if (B[u].id==-1) continue;g[u]|=(B[u].x);}
	//for (int u=0;u<=21;u++) printf("OZY:%d %d\n",B[u].id,B[u].x);
	int now=0;// 
	int last=y.r+1;
	for (int u=0;u<=21;u++)
	{
		if (B[u].id==-1) break;
		if (u!=0&&B[u].id==B[u-1].id) continue;
		while (now<=21)
		{
			if ((f[now]|g[u])>=X) break;
			now++;
			if (A[now].id==-1) break;
		}
		if (now>21||A[now].id==-1) break;
		if (u==0) ans.tot=ans.tot+(LL)(last-B[u].id)*(A[now].id-x.l+1);
		else ans.tot=ans.tot+(LL)(last-B[u].id)*(A[now].id-x.l+1);
		//printf("%d %d %d %d %d\n",last,B[u].id,A[now].id,f[now],x.l);
		last=B[u].id;
	}
	//printf("ans:");ans.print();
//	system("pause");
	return ans;
}
void bt (int l,int r)
{
	int o=++num;
	tr[o].l=l;tr[o].r=r;
	tr[o].c.l=l;tr[o].c.r=r;
	if (l==r)	{calc(o,l,a[l]);return ;}
	int mid=(l+r)>>1;
	tr[o].s1=num+1;bt(l,mid);
	tr[o].s2=num+1;bt(mid+1,r);
	tr[o].c=Merge(tr[tr[o].s1].c,tr[tr[o].s2].c);
}
void change (int now,int x,int xx)
{
	if (tr[now].l==tr[now].r)	{calc(now,x,xx);return ;}
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (x<=mid) change(s1,x,xx);
	else change(s2,x,xx);
	tr[now].c=Merge(tr[s1].c,tr[s2].c);
}
qt ans;
void find (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)
	{
		ans=Merge(ans,tr[now].c);
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) find(s1,l,r);
	else if (l>mid) find(s2,l,r);
	else find(s1,l,mid),find(s2,mid+1,r);
}
int read ()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	n=read();m=read();X=read();
	for (int u=1;u<=n;u++)	a[u]=read();
	bt(1,n);
	for (int u=1;u<=m;u++)
	{
		int op=read();
		if (op==1)
		{
			int x,y;
			x=read();y=read();
			change(1,x,y);
		}
		else
		{
			int l,r;
			l=read();r=read();
			ans.tot=-1;
			find(1,l,r);
			printf("%lld\n",ans.tot);
		}
	}
	return 0;
}