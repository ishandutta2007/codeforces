#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=3005;

int n,m,p,q,a[N][N],b[N][N],s[N];

void init()
{
	int g0,x,y,z;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	scanf("%d%d%d%d",&g0,&x,&y,&z);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=g0,g0=((LL)g0*x%z+y)%z;
}

int main()
{
	init();
	for (int i=1;i<=n;i++)
	{
		int h=1,t=0;
		for (int j=1;j<q;j++)
		{
			while (h<=t&&a[i][s[t]]>=a[i][j]) t--;
			s[++t]=j;
		}
		for (int j=q;j<=m;j++)
		{
			while (h<=t&&a[i][s[t]]>=a[i][j]) t--;
			s[++t]=j;
			b[i][j]=a[i][s[h]];
			if (s[h]==j-q+1) h++;
		}
	}
	LL ans=0;
	for (int j=q;j<=m;j++)
	{
		int h=1,t=0;
		for (int i=1;i<p;i++)
		{
			while (h<=t&&b[s[t]][j]>=b[i][j]) t--;
			s[++t]=i;
		}
		for (int i=p;i<=n;i++)
		{
			while (h<=t&&b[s[t]][j]>=b[i][j]) t--;
			s[++t]=i;
			ans+=b[s[h]][j];
			if (s[h]==i-p+1) h++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}