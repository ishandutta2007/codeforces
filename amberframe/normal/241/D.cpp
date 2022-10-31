#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef long long LL;
const int inf = 1<<30;
const int maxn = 50005;
int n,p,a[maxn],cnt,num[maxn];
bool f[33][maxn][32];
int g[33][maxn][32];
int stk[maxn],top,pos[maxn];
void dfs(int i,int j,int k) {
	if (f[i-1][j][k]) dfs(i-1,j,k);
	else {
		if (g[i][j][k]>=0)
			dfs(i-1,g[i][j][k],k^num[i]);
		stk[++top]=num[i];
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("numbers.in","r",stdin);
		freopen("numbers.out","w",stdout);
	#endif
	scanf("%d %d",&n,&p);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),pos[a[i]]=i;
	for (int i=1;i<=n;i++) {
		if (a[i]>=32) continue;
		num[++cnt]=a[i];
		f[cnt][a[i]%p][a[i]]=1;
		g[cnt][a[i]%p][a[i]]=-1;
		for (int j=0;j<p;j++)
		for (int k=0;k<32;k++)
		if (a[i]<10&&f[cnt-1][j][k])
			f[cnt][(j*10+a[i])%p][k^a[i]]=f[cnt][j][k]=1,
			g[cnt][(j*10+a[i])%p][k^a[i]]=j;
		else if (i>=10&&f[cnt-1][j][k])
			f[cnt][(j*100+a[i])%p][k^a[i]]=f[cnt][j][k]=1,
			g[cnt][(j*100+a[i])%p][k^a[i]]=j;
	}
	if (f[cnt][0][0]) {
		dfs(cnt,0,0);
		printf("Yes\n%d\n",top);
		for (int i=1;i<=top;i++)
			printf("%d ",pos[stk[i]]);
	}
	else puts("No");
	return 0;
}