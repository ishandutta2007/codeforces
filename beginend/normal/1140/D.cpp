#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=505;
const LL inf=(LL)1e15;

int n;
LL f[N][N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=i+2;j<=n;j++)
			f[i][j]=inf;
	for (int l=3;l<=n;l++)
		for (int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			for (int k=i+1;k<j;k++)
				f[i][j]=std::min(f[i][j],(LL)i*j*k+f[i][k]+f[k][j]);
		}
	printf("%lld\n",f[1][n]);
	return 0;
}