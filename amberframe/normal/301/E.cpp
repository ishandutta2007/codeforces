#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <time.h>

using namespace std;
typedef long long LL;
const int mod = 1e9+7;
const int maxn = 105;
const int N = 200;
int f[maxn][maxn][maxn];
int g[maxn][maxn][maxn];
bool usedf[maxn][maxn];
bool usedg[maxn][maxn];
int n,m,K,ans,c[N+5][N+5];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("arrangement.in","r",stdin);
		freopen("arrangement.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&K);
	if (K==0) {puts("0");return 0;}
	for (int i=0;i<=N;i++) {
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++)
		for (int k=1;k<=K;k++)
		if (usedg[j][k])
			memset(g[j][k],0,sizeof(g[j][k]));
		memset(usedg,0,sizeof usedg);
		for (int t=1;t<=n;t++) usedg[t][1]=true,g[t][1][t]=1;
		for (int j=1;j<=n;j++)
		for (int k=1;k<=K;k++)
		if (usedf[j][k]) {
			for (int l=1;l<=n;l++)
			if (int val=f[j][k][l]) {
				int tmp;
				for (int t=l;t<=n-j;t++)
				if (c[t-1][l-1]<=K&&(tmp=k*c[t-1][l-1])<=K)
					(g[j+t][tmp][t-l]+=val)%=mod,usedg[j+t][tmp]=true;
				else break;
			}
		}
		swap(f,g);swap(usedf,usedg);
		for (int j=1;j<=n;j++)
		for (int k=1;k<=K;k++)
			(ans+=f[j][k][0])%=mod;
	}
	printf("%d",ans);
//	cerr<<clock()<<endl;
	return 0;
}