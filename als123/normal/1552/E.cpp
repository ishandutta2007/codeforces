#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=105*105;
int n,k;
int c[N],lst[N];
struct qq
{
	int l,r,id,len;
}a[N];int nn=0;
bool cmp (qq x,qq y)
{
	return x.r<y.r;
}
bool in[N];
int calc (int l,int r)
{
	int tot=0;
	for (int u=l;u<=r;u++)
	{
		if (in[c[u]]==false) tot++;
		in[c[u]]=true;
	}
	for (int u=l;u<=r;u++) in[c[u]]=false;
	return tot;
}
int x[N],y[N];
int cnt[N];
int main()
{
	memset(x,-1,sizeof(x));
	memset(lst,-1,sizeof(lst));
	memset(in,false,sizeof(in));
	scanf("%d%d",&n,&k);
	int t=n/(k-1);
	if (n%(k-1)!=0) t++;
//	printf("%d\n",t);	
	for (int u=1;u<=n*k;u++)
	{
		scanf("%d",&c[u]);
		if (lst[c[u]]!=-1)
		{
			a[++nn].l=lst[c[u]];
			a[nn].r=u;
			a[nn].id=c[u];
			a[nn].len=calc(a[nn].l,a[nn].r);
		}
		lst[c[u]]=u;
	}
	sort(a+1,a+1+nn,cmp);
	for (int u=1;u<=nn;u++)
	{
		int id=a[u].id;
		if (x[id]!=-1) continue;
		int mx=0;
		for (int i=a[u].l;i<=a[u].r;i++) mx=max(mx,cnt[i]);
	//	printf("%d %d %d %d\n",id,mx,a[u].l,a[u].r);
		if (mx+1>t) continue;
		x[id]=a[u].l;y[id]=a[u].r;
		for (int i=a[u].l;i<=a[u].r;i++) cnt[i]++;
	}
	for (int u=1;u<=n;u++)	printf("%d %d\n",x[u],y[u]);
	return 0;
}