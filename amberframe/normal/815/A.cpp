#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
const int maxn = 105;

int g[maxn][maxn],a[maxn],b[maxn],n,m,ans;

bool check()
{
	for (int i=1;i<=n;i++) if (a[i]<0) return false;
	for (int i=1;i<=m;i++) if (b[i]<0) return false;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (a[i]+b[j]!=g[i][j]) return false;
	return true;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("game.in","r",stdin);
		//freopen("game.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		scanf("%d",&g[i][j]);
	for (int i=1;i<=n;i++) a[i]=g[i][1];
	int mi=a[1];
	for (int i=2;i<=n;i++) mi=min(mi,a[i]);
	for (int i=1;i<=n;i++) a[i]-=mi;
	for (int i=1;i<=m;i++) b[i]=g[1][i]-a[1];
	if (check()) {
		int mia=a[1],mib=b[1];
		for (int i=1;i<=n;i++) mia=min(mia,a[i]);
		for (int i=1;i<=m;i++) mib=min(mib,b[i]);
	for (int i=1;i<=n;i++) a[i]-=mia;
	for (int i=1;i<=m;i++) b[i]-=mib;
		
	int t=g[1][1]-a[1]-b[1];
		if (n<m) for (int i=1;i<=n;i++) a[i]+=t;
		else for (int i=1;i<=m;i++) b[i]+=t;
		for (int i=1;i<=n;i++) ans+=a[i];
		for (int i=1;i<=m;i++) ans+=b[i];
		printf("%d\n",ans);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=a[i];j++)
			printf("row %d\n",i);
		for (int i=1;i<=m;i++)
		for (int j=1;j<=b[i];j++)
			printf("col %d\n",i);
	}
	else puts("-1");
	return 0;
}