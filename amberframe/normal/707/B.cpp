#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 100005;
const int inf = 1<<30;
int u[maxn],v[maxn],w[maxn];
int n,m,k,sto[maxn],ans=inf;
int main() {
	#ifndef ONLINE_JUDGE
		freopen("bakery.in","r",stdin);
		freopen("bakery.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	for (int x,i=1;i<=k;i++)
		scanf("%d",&x),sto[x]=1;
	for (int i=1;i<=m;i++)
	if (sto[u[i]]^sto[v[i]])
		ans=min(ans,w[i]);
	if (ans!=inf) printf("%d\n",ans);
	else puts("-1"); 
	return 0;
}