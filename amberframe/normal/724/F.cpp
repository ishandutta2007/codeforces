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
const int maxn = 1005;
const int maxd = 15;

int n,d;LL f[maxn],inc[maxn];
LL mod,g[maxn][maxn][maxd];
LL QuickPow(LL p,LL k) {
	LL res=1ll;p%=mod;
	for (;k;k>>=1,(p*=p)%=mod)
		if (k&1) (res*=p)%=mod;
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
	#endif
	scanf("%d %d %lld",&n,&d,&mod);
	if (n<=2) {puts("1");return 0;}
	for (int i=1;i<=n;i++)
		inc[i]=QuickPow(i,mod-2);
	
	f[1]=g[0][0][0]=1ll;
	for (int i=0;i<=d;i++) g[1][i][i]=1ll;
	for (int i=2;i<=n/2;i++) {
		f[i]=g[i-1][i-1][d-1];
		for (int k=0;k<=d;k++)
		for (int j=0;j<=n;j++)
		if (g[i-1][j][k]) {
			LL cur=g[i-1][j][k];
			for (int l=0;j+l*i<=n&&l+k<=d;l++) {
				(g[i][j+l*i][l+k]+=cur)%=mod;
				(cur*=(f[i]+l)*inc[l+1]%mod)%=mod;
			}
		}
	}
	if (n&1) printf("%lld",g[n/2][n-1][d]);
	else {
		LL ans=g[n/2-1][n-1][d],cur=f[n/2];
		(ans+=(cur+1)*cur%mod*inc[2])%=mod;
		printf("%lld",ans);
	}
	return 0;
}