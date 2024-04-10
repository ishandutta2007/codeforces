#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
using namespace std;

#define pb push_back
typedef long double cdb;
const int maxn = 100005;
const int maxm = 105;
int cnt[maxn],maxb[maxn],n,q;
double f[maxn][maxm],ans=0.0;
void move(int u,int v) {
	for (int j=0;j<=maxb[u];j++)
		f[u][j]=f[u][j]*(cnt[u]-j)/cnt[u]+f[u][j+1]*(j+1)/cnt[u];
	cnt[u]--;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("birthday.in","r",stdin);
		freopen("birthday.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int a,i=1;i<=n;i++)
		scanf("%d",&a),maxb[i]=cnt[i]=a,f[i][a]=1.0;
	for (int i=1;i<=n;i++) ans+=f[i][0];
	scanf("%d",&q);
	for (int u,v,k,i=1;i<=q;i++) {
		scanf("%d %d %d",&u,&v,&k);
		ans-=f[u][0];
		for (int j=1;j<=k;j++) move(u,v);
		ans+=f[u][0];cnt[v]+=k;
		printf("%.12lf\n",ans);
	}
	return 0;
}