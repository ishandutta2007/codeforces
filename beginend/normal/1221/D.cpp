#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;
const LL inf=(LL)1e18;

int n,a[N],b[N];
LL f[N][3];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		for (int i=1;i<=n;i++)
			for (int j=0;j<=2;j++)
			{
				f[i][j]=inf;
				for (int k=0;k<=2;k++)
					if (a[i]+j!=a[i-1]+k) f[i][j]=std::min(f[i][j],f[i-1][k]+(LL)j*b[i]);
			}
		printf("%lld\n",std::min(f[n][0],std::min(f[n][1],f[n][2])));
	}
	return 0;
}