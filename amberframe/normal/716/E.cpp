#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
const int maxn = 200005;
const LL inf = 1ll<<50;

int n;LL M,ans=0;
int ehead[maxn],ecnt;
LL quickPow(LL p,LL k,LL mod) {
	LL res=1ll;p%=mod;
	for (;k;k>>=1,(p*=p)%=mod)
		if (k&1) (res*=p)%=mod;
	return res;
}
LL Getphi(LL n) {
	LL res=n;
	for (LL i=2;i*i<=n;i++)
	if (n%i==0) {
		res=res*(i-1)/i;
		while (n%i==0) n/=i;
	}
	if (n>1) res=res*(n-1)/n;
	return res;
}
struct edge{
	int u,v,w,next;
}edg[maxn];
void add(int u,int v,int w) {
	edg[++ecnt]=(edge){u,v,w,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,w,ehead[v]};
	ehead[v]=ecnt;
}

int root,cnt[maxn],siz[maxn],sum,vis[maxn];
void getroot(int u,int par)
{
	cnt[u]=0;siz[u]=1;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]&&v!=par)
	{
		getroot(v,u);siz[u]+=siz[v];
		cnt[u]=max(cnt[u],siz[v]);
	}
	cnt[u]=max(cnt[u],sum-siz[u]);
	if (cnt[u]<cnt[root]) root=u;
}

map<int,int> bac;
LL powj[maxn],incj[maxn],tag;
void suf(LL num,int len,int u,int par)
{
	if (tag==1&&!num) ++ans;
	bac[num*incj[len]%M]+=tag;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]&&v!=par)
		suf((num*10+edg[j].w)%M,len+1,v,u);
}
void pre(LL num,int len,int u,int par)
{
	if (tag==1&&!num) ++ans;
	ans+=bac[(M-num)%M];
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]&&v!=par)
		pre((num+edg[j].w*powj[len])%M,len+1,v,u);
}
void solve(int u)
{
	tag=1;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]) {
		pre(edg[j].w%M,1,v,u);
		suf(edg[j].w%M,1,v,u);
	}
	tag=-1;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]) {
		suf(edg[j].w%M,1,v,u);
		pre(edg[j].w%M,1,v,u);
	}
	bac.clear();
}
void dfs(int u)
{
	vis[u]=true;solve(u);
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v])
	{
		root=0;sum=siz[v];
		getroot(v,0);dfs(root);
		
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
	#endif
	scanf("%d %lld",&n,&M);
	for (int u,v,w,i=1;i<n;i++) {
		scanf("%d %d %d",&u,&v,&w);
		++u;++v;add(u,v,w);
	}

	powj[0]=incj[0]=1ll;
	LL inc=quickPow(10,Getphi(M)-1,M);
	for (int i=1;i<=n;i++) powj[i]=powj[i-1]*10ll%M;
	for (int i=1;i<=n;i++) incj[i]=incj[i-1]*inc%M;
	cnt[0]=sum=n;root=0;getroot(1,0);
	dfs(root);printf("%lld",ans);
	return 0;
}