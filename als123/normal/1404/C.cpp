#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=600005;
int n,m;
int a[N];
int t[N];
bool rt[N];
int f[N];
int lb (int x)	{return x&(-x);}
int query (int x)
{
	int t=0;
	while (x>0)
	{
		t+=f[x];
		x-=lb(x);
	}
	return t;
}
void modify (int x,int c)
{
	while (x<=n)
	{
		f[x]+=c;
		x+=lb(x);
	}
}
struct qq
{
	int x,y,id;
}Q[N];
bool cmp (qq x,qq y)	{return x.y<y.y;}
int ans[N];
void Add (int x)
{
	if (a[x]<0) return ;
	int l=0,r=x-1;
	int p=-1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (query(x)-query(mid)>=a[x]) {p=mid;l=mid+1;}
		else r=mid-1;
	}
	if (p==-1) return ;
//	printf("x:%d %d\n",x,p);
	modify(p+1,1);
}
int main()
{
	memset(rt,false,sizeof(rt));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++) 	{scanf("%d",&a[u]);a[u]=u-a[u];}
//	for (int u=1;u<=n;u++) printf("%d ",a[u]);printf("\n");
	for (int u=1;u<=m;u++)
	{
		scanf("%d%d",&Q[u].x,&Q[u].y);
		Q[u].y=n-Q[u].y;
		Q[u].id=u;
	}
	sort(Q+1,Q+1+m,cmp);
	int R=0;
	for (int u=1;u<=m;u++)
	{
		while (R+1<=Q[u].y)	{R++;Add(R);}
		ans[Q[u].id]=query(n)-query(Q[u].x);
	}
	for (int u=1;u<=m;u++) printf("%d\n",ans[u]);
	return 0;
}