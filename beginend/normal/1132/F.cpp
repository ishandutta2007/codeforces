#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=505;

int n,a[N],f[N][N],g[N][N];
char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int tmp=0;
	for (int i=1;i<=n;i++)
		if (!tmp||s[i]-'a'!=a[tmp]) a[++tmp]=s[i]-'a';
	n=tmp;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			f[i][j]=g[i][j]=n;
	for (int i=1;i<=n;i++) f[i][i]=0,g[i][i]=1;
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			f[i][j]=g[i+1][j];
			for (int k=i+1;k<=j;k++)
				if (a[k]==a[i]) f[i][j]=std::min(f[i][j],f[k][j]+g[i+1][k-1]);
			g[i][j]=std::min(f[i][j]+1,g[i+1][j]+1);
		}
	printf("%d\n",g[1][n]);
	return 0;
}