#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 200005;
const int inf = 1<<30;
int a[maxn],b[maxn],n;
int col[maxn],v0[maxn];
void dfs(int u) {
	int v;
	if (!col[v=v0[u]]) {
		col[v]=3-col[u];dfs(v);
	}
	if (!col[v=(u&1?u+1:u-1)]) {
		col[v]=3-col[u];dfs(v);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("party.in","r",stdin);
		freopen("party.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d %d",&a[i],&b[i]),
		v0[a[i]]=b[i],v0[b[i]]=a[i];
	for (int i=1;i<=2*n;i++)
	if (!col[i]) {col[i]=1;dfs(i);}
	for (int i=1;i<=n;i++)
		printf("%d %d\n",col[a[i]],col[b[i]]);
	return 0;
}