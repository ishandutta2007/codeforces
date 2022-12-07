#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int MOD=998244353;
const int N=100005;
const int NN=350;
int add (int x,int y)	{x=x+y;return x>=MOD?x-MOD:x;}
int dec (int x,int y)	{x=x-y;return x<0?x+MOD:x;}
int mul (int x,int y)	{return (LL)x*y%MOD;}
int n,k;
int a[N];
int bel[N];
int L[N],R[N];
int siz;
int g[NN][N+NN];//i
int lzy[N]; 
int f[N],h[N];
int lst[N],lst1[N];//   
void Init ()
{
	scanf("%d%d",&n,&k);siz=sqrt(n);
	for (int u=1;u<=n;u++) 	scanf("%d",&a[u]);
	for (int u=0;u<=n;u++) bel[u]=u/siz+1;
	for (int u=0;u<=n;u++) R[bel[u]]=u;
	for (int u=n;u>=0;u--) L[bel[u]]=u;
	for (int u=1;u<=n;u++) lst[u]=lst1[u]=0;
}
void bt (int x)
{
	for (int u=L[x];u<=R[x];u++)	g[x][h[u]]=add(g[x][h[u]],f[u]);
	for (int u=1;u<=siz+n;u++) g[x][u]=add(g[x][u],g[x][u-1]);
}
void Dec (int l,int r,int x)//l,r1 x 
{
	for (int u=r;u>=max(L[bel[x]],l);u--)	h[u]--;
	r=min(r,L[bel[x]]-1);
	if (r<l) return ;
	if (bel[l]==bel[r])// 
	{
		for (int u=l;u<=r;u++)
		{
			h[u]--;
			g[bel[l]][h[u]]=add(g[bel[l]][h[u]],f[u]);
		}
		return ;
	}
	
	for (int u=bel[l]+1;u<bel[r];u++) lzy[u]--;
	for (int u=l;u<=R[bel[l]];u++)
	{
		h[u]--;
		g[bel[l]][h[u]]=add(g[bel[l]][h[u]],f[u]);
	}
	for (int u=L[bel[r]];u<=r;u++)
	{
		h[u]--;
		g[bel[r]][h[u]]=add(g[bel[r]][h[u]],f[u]);
	}
}
void Add (int l,int r,int x)
{	
	//printf("add:%d %d\n",l,r);
	for (int u=r;u>=max(L[bel[x]],l);u--)	h[u]++;
	r=min(r,L[bel[x]]-1);
	if (r<l) return ;

	if (bel[l]==bel[r])// 
	{
		for (int u=l;u<=r;u++)
		{
			g[bel[l]][h[u]]=dec(g[bel[l]][h[u]],f[u]);
			h[u]++;
		}
		return ;
	}
	for (int u=bel[l]+1;u<bel[r];u++) lzy[u]++;
	for (int u=l;u<=R[bel[l]];u++)
	{
		g[bel[l]][h[u]]=dec(g[bel[l]][h[u]],f[u]);
		h[u]++;
	}
	for (int u=L[bel[r]];u<=r;u++)
	{
		g[bel[r]][h[u]]=dec(g[bel[r]][h[u]],f[u]);
		h[u]++;
	}
}
int calc (int x) 
{
	int lalal=0;	
	for (int u=L[bel[x]];u<x;u++)
		if (h[u]<=k)
			lalal=add(lalal,f[u]);
	for (int u=1;u<bel[x];u++)
	{
		int t=k-lzy[u];
		if (t<0) continue;
		//if (t>n) printf("GG:%d\n",lzy[u]);
		lalal=add(lalal,g[u][t]);
	}
	return lalal;
}
void solve ()
{
	h[0]=0;f[0]=1;if (0==R[bel[0]]) bt(bel[0]);
	for (int u=1;u<=n;u++)
	{
		int x=a[u];
		if (lst[x]!=0)	Dec(lst1[x],lst[x]-1,u);
		Add(lst[x],u-1,u);
	
		lst1[x]=lst[x];lst[x]=u;
		f[u]=calc(u);
		//printf("%d %d\n",u,f[u]);
		if (u==R[bel[u]])//
			bt(bel[u]);
	}
	printf("%d\n",f[n]);
}
int main()
{
	//freopen("a.in","r",stdin);
	Init();
	solve();
	return 0;
}