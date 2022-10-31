#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 1005;
const int maxm = 100005;
const int inf = 1<<30;
int par[maxn],w[maxn],b[maxn];
int f[2][maxm],n,m,W,cur;
int findp(int t) {
	return par[t]?par[t]=findp(par[t]):t;
}
void merge(int u,int v) {
	u=findp(u);v=findp(v);
	if (u!=v) par[u]=v;
}
void upd(int &x,int y) {
	if (x<y) x=y;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("hoses.in","r",stdin);
		freopen("hoses.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&W);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int u,v,i=1;i<=m;i++) scanf("%d %d",&u,&v),merge(u,v);
	for (int i=1;i<=n;i++)
	if (findp(i)==i) {
		int sumb=0,sumw=0;cur^=1;
		for (int k=0;k<=W;k++)
			f[cur][k]=f[cur^1][k];
		for (int j=1;j<=n;j++)
		if (findp(j)==i) {
			sumb+=b[j];sumw+=w[j];
			for (int k=w[j];k<=W;k++)
				upd(f[cur][k],f[cur^1][k-w[j]]+b[j]);
		}
		for (int k=sumw;k<=W;k++)
			upd(f[cur][k],f[cur^1][k-sumw]+sumb);
	}
	printf("%d",f[cur][W]);
	return 0;
}