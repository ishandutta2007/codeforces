#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
using namespace std;
typedef long long LL;
const int maxn = 5005;
const LL inf = 1ll<<50;
LL dp[2][maxn][2][2];
int n,s,e,x[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
void upd(LL &x,LL y) {
	if (y<x) x=y;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("ant.in","r",stdin);
		freopen("ant.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&s,&e);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	
	for (int i=0;i<2;i++)
	for (int j=0;j<=n;j++)
	for (int k=0;k<2;k++)
	for (int l=0;l<2;l++)
		dp[i][j][k][l]=inf;
	if (s==1) dp[1][0][0][1]=-x[1]+d[1];
	else if (e==1) dp[1][0][1][0]=-x[1]+b[1];
	else dp[1][0][1][1]=-2*x[1]+b[1]+d[1];
	
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		for (int k=0;k<2;k++)
		for (int l=0;l<2;l++)
			dp[i&1][j][k][l]=inf;
		for (int j=0;j<=n;j++)
		for (int k=0;k<2;k++)
		for (int l=0;l<2;l++)
		if (dp[i-1&1][j][k][l]<inf) {
			LL v=dp[i-1&1][j][k][l];
			if (s==i) {
				if (!k) continue; 
				upd(dp[i&1][j][0][l],v+x[i]+c[i]);
				upd(dp[i&1][j+1][0][l],v-x[i]+d[i]);
			}
			else if (e==i) {
				if (!l) continue; 
				upd(dp[i&1][j][k][0],v+x[i]+a[i]);
				upd(dp[i&1][j+1][k][0],v-x[i]+b[i]);
			}
			else {
				if (j) {
					upd(dp[i&1][j+1][k][l],v-2*x[i]+b[i]+d[i]); 
					upd(dp[i&1][j][k][l],v+a[i]+d[i]); 
					upd(dp[i&1][j][k][l],v+b[i]+c[i]); 
					upd(dp[i&1][j-1][k][l],v+2*x[i]+a[i]+c[i]);
				}
				if (k) {
					upd(dp[i&1][j][k][l],v+b[i]+c[i]); 
					upd(dp[i&1][j+1][k][l],v-2*x[i]+b[i]+d[i]); 
				}
				if (l) {
					upd(dp[i&1][j][k][l],v+a[i]+d[i]); 
					upd(dp[i&1][j+1][k][l],v-2*x[i]+b[i]+d[i]); 
				}
			}
		}
	}
	printf("%I64d",dp[n&1][0][0][0]);
	return 0;
}