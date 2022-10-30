#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const LL inf = 1ll<<50;
const int maxn = 30005;

LL f[2][maxn];
int n,c,p[maxn],s[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("transportation.in","r",stdin);
		freopen("transportation.out","w",stdout);
	#endif
	scanf("%d %d",&n,&c);
	for (int i=n;i>=1;i--) scanf("%d",&p[i]);
	for (int i=n;i>=1;i--) scanf("%d",&s[i]);
	for (int i=1;i<=n;i++) {
		f[i&1][0]=f[i-1&1][0]+s[i];
		f[i-1&1][i]=inf;
		for (int j=1;j<=i;j++)
			f[i&1][j]=min(f[i-1&1][j-1]+p[i],f[i-1&1][j]+s[i]+(LL)c*j);
	}
	LL ans=inf;
	for (int j=0;j<=n;j++)
		ans=min(ans,f[n&1][j]);
	printf("%lld",ans);
	return 0;
}