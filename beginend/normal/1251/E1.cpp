#include<bits/stdc++.h>

typedef long long LL;

const int N=5005;
const LL inf=(LL)1e15;

int n;
LL f[N][N];
struct data{int m,p;}a[N];

bool cmp(data a,data b)
{
	return a.m<b.m;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i].m,&a[i].p);
		std::sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++)
			for (int j=0;j<=n;j++)
			{
				f[i][j]=inf;
				if (j+i-1>=a[i].m) f[i][j]=f[i-1][j];
				if (j<n) f[i][j]=std::min(f[i][j],f[i-1][j+1]+a[i].p);
			}
		printf("%lld\n",f[n][0]);
	}
	return 0;
}