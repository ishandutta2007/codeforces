#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

typedef long long LL;
#define pb push_back
using namespace std;
const int maxn = 200005;
const LL mod = 1e9+7;
bool vis[maxn];LL ans=1ll;
int dep[maxn],sum,n;
LL quickpow(LL p,LL k) {
	LL res=1ll;p%=mod;
	for (;k;k>>=1,(p*=p)%=mod)
		if (k&1) (res*=p)%=mod;
	return res;
}
	
int ehead[maxn],ecnt=1;
struct edge{
	int u,v,next;
}edg[maxn*2];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

int xabs(int x) {return x>0?x:-x;}
void dfs(int u,int faj) {
	vis[u]=true;
	for (int j=ehead[u];j;j=edg[j].next) 
	if (j!=(faj^1)) {
		int v=edg[j].v;
		if (vis[v]) {
			if (dep[u]<dep[v]) continue;
			int w=dep[u]-dep[v]+1;sum+=w;
			(ans*=quickpow(2,w)-2ll)%=mod;
		}
		else {
			dep[v]=dep[u]+1;dfs(v,j);
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("roads.in","r",stdin);
		freopen("roads.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int v,i=1;i<=n;i++)
		scanf("%d",&v),add(i,v);
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i,0);
	(ans*=quickpow(2,n-sum))%=mod;
	if (ans<0) ans+=mod;
	printf("%I64d",ans);
	return 0;
}