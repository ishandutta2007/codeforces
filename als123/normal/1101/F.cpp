#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=405;
int f[N][N][N];
int n,m;
int a[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)  scanf("%d",&a[u]);
	for (int u=1;u<=n;u++)
		for (int i=u;i<=n;i++)
			f[0][u][i]=a[i]-a[u];
	for (int u=1;u<=n;u++)
		for (int i=1;i<=n;i++)
		{
			int k=i;
			for (int j=1;j<=n;j++)
			{
				while (k<j&&max(f[u-1][i][k+1],a[j]-a[k+1])<=max(f[u-1][i][k],a[j]-a[k])) k++;
				f[u][i][j]=max(f[u-1][i][k],a[j]-a[k]);
			}
		}
	LL ans=0;
	while (m--)
	{
		int st,ed,c,r;
		scanf("%d%d%d%d",&st,&ed,&c,&r);
		ans=max(ans,(LL)f[r][st][ed]*c);
	}
	printf("%lld\n",ans);
	return 0;
}