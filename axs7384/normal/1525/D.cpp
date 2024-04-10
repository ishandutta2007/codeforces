#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int inf=1e9+7;
int a[N],p[N],n,m;
int f[N][N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if (a[i])
			p[++m]=i;
	}
	for (int i=1;i<=m;++i)
		f[0][i]=inf;
	for (int i=1;i<=n;++i)
		if (a[i])
		{
			for (int j=1;j<=m;++j)
				f[i][j]=f[i-1][j];
		}
		else
		{
			for (int j=1;j<=m;++j)
				f[i][j]=min(f[i-1][j],f[i-1][j-1]+abs(i-p[j]));
		}
	cout<<f[n][m];
	return 0;
}