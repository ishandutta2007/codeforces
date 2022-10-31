#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <bitset>

using namespace std;
typedef long long LL;
const int maxn = 4005;
const int maxm = 500005;
const int inf = 1<<30;

int u[maxm],v[maxm],n,m;
bitset<maxn> bs[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("permutations.in","r",stdin);
		freopen("permutations.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d %d",&u[i],&v[i]),bs[u[i]][v[i]]=1;
	for (int i=1;i<=n;i++) bs[i][i+n]=1;
	for (int i=1;i<=n;i++) {
		int t=i;while (t<=n&&!bs[t][i]) ++t;
		if (t!=i&&t<=n) swap(bs[t],bs[i]);
		for (int j=1;j<=n;j++)
		if (bs[j][i]&&j!=i) bs[j]^=bs[i];
	}
	for (int i=1;i<=m;i++)
	if (!bs[v[i]][u[i]+n]) puts("YES");
	else puts("NO");
	return 0;
}