#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

typedef long long LL;
#define pb push_back
using namespace std;
const int maxn = 105;
const LL inf = 1ll<<50;
int p[maxn][maxn],c[maxn],n,m,K;
LL f[maxn][maxn][maxn],ans=inf;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("coloring.in","r",stdin);
		freopen("coloring.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&K);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		scanf("%d",&p[i][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	for (int l=0;l<=n;l++)
		f[i][j][l]=inf;
	
	for (int j=1;j<=m;j++) {
		LL res=inf;
		if (!c[1]) res=p[1][j];
		else if (c[1]==j) res=0;
		f[1][j][1]=res;
	}
	
	for (int i=2;i<=n;i++)
	for (int j=1;j<=m;j++)
	for (int l=1;l<=i;l++) {
		LL res=inf;
		if (!c[i]) {
			for (int k=1;k<=m;k++)
			if (!c[i-1]||c[i-1]==k)
				res=min(res,f[i-1][k][l-(k!=j)]+p[i][j]);
		}
		else if (c[i]==j) {
			for (int k=1;k<=m;k++)
			if (!c[i-1]||c[i-1]==k)
				res=min(res,f[i-1][k][l-(k!=j)]);
		}
		f[i][j][l]=res;
	}
	
	for (int j=1;j<=m;j++)
		ans=min(ans,f[n][j][K]);
	if (ans!=inf) printf("%I64d",ans);
	else puts("-1"); 
	return 0;
}