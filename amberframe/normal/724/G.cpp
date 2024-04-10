#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
#include <time.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const LL inf = 1ll<<50;
const int maxn = 400005;
const int maxm = 65;
const LL mod = 1e9+7;

int ehead[maxn],ecnt=1;
struct edge {
	int u,v;LL w;int next;
}edg[maxn];
void add(int u,int v,LL w) {
	edg[++ecnt]=(edge){u,v,w,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,w,ehead[v]};
	ehead[v]=ecnt;
}

LL pw2[maxm];bool tag[maxm];
LL bas[maxm];int tot;
void insert(LL val) {
	for (int i=60;i>=0;i--)
	if ((val>>i)&1) tag[i]=true;
	for (int i=60;i>=0;i--)
	if ((val>>i)&1) {
		if (bas[i]) val^=bas[i];
		else {bas[i]=val;++tot;break;}
	}
}

LL p0[maxn],zero[maxm],one[maxm];
bool vis[maxn];int n,m;LL ans;
void dfs(int u,int parj) {
	vis[u]=true;
	for (int i=60;i>=0;i--)
		((p0[u]>>i)&1)?one[i]++:zero[i]++;
	for (int j=ehead[u];j;j=edg[j].next)
	if (j!=parj&&j!=(parj^1)) {
		int v=edg[j].v;
		if (vis[v]) insert(edg[j].w^p0[u]^p0[v]);
		else p0[v]=p0[u]^edg[j].w,dfs(v,j);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("graph.in","r",stdin);
		freopen("graph.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);pw2[0]=1ll;
	for (int i=1;i<=60;i++)
		pw2[i]=pw2[i-1]*2%mod;
	for (int i=1;i<=m;i++) {
		int u,v;LL w;
		scanf("%d %d %lld",&u,&v,&w);add(u,v,w);
	}
	for (int i=1;i<=n;i++)
	if (!vis[i]) {
		memset(bas,0,sizeof bas);
		memset(tag,0,sizeof tag);
		memset(zero,0,sizeof zero);
		memset(one,0,sizeof one);
		tot=0;dfs(i,0);
		for (int j=60;j>=0;j--) {
			LL _zero,_one,sum=0;
			if (tag[j]) _zero=_one=pw2[tot-1];
			else _zero=pw2[tot],_one=0;
			(sum+=(zero[j]-1)*zero[j]/2%mod*_one)%=mod;
			(sum+=(one[j]-1)*one[j]/2%mod*_one)%=mod;
			(sum+=zero[j]*one[j]*_zero)%=mod;
			(ans+=sum*pw2[j])%=mod;
		}
	}
	printf("%lld",ans);
	return 0;
}