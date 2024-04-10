#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=400005;
const int M=1048580;
const LL inf=(LL)1e18;

int n,m,a[N],bin[25],ls[25];
LL lef[25][M],f[M];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),m=std::max(m,a[i]);
	bin[0]=1;
	for (int i=1;i<=m;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			if (j!=a[i]) lef[a[i]][bin[j-1]]+=ls[j];
		ls[a[i]]++;
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<bin[m];j++)
			lef[i][j]=lef[i][j-(j&(-j))]+lef[i][j&(-j)];
	for (int i=1;i<bin[m];i++) f[i]=inf;
	for (int i=0;i<bin[m]-1;i++)
		for (int j=1;j<=m;j++)
			if (!(i&bin[j-1])) f[i+bin[j-1]]=std::min(f[i+bin[j-1]],f[i]+lef[j][bin[m]-1-i]);
	printf("%lld\n",f[bin[m]-1]);
	return 0;
}