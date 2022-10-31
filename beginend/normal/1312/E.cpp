#include<bits/stdc++.h>

const int N=505;

int n,a[N],f[N][N],g[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) f[i][i]=a[i];
	for (int l=1;l<n;l++)
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			for (int k=i;k<j;k++)
				if (f[i][k]>0&&f[i][k]==f[k+1][j])
				{
					f[i][j]=f[i][k]+1;
					break;
				}
		}
	for (int i=1;i<=n;i++)
	{
		g[i]=i;
		for (int j=1;j<=i;j++)
			if (f[j][i]) g[i]=std::min(g[i],g[j-1]+1);
			else g[i]=std::min(g[i],g[j-1]+i-j+1);;
	}
	printf("%d\n",g[n]);
	return 0;
}