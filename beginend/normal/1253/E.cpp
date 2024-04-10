#include<bits/stdc++.h>

const int N=85;
const int inf=1e9;

int n,m,f[N][100005],mn[100005];
std::pair<int,int> a[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second);
	std::sort(a+1,a+n+1);
	for (int i=1;i<=m;i++) f[0][i]=inf;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			mn[j]=std::min(mn[j-1],f[i-1][j]-j);
			if (j<=a[i].first+a[i].second)
			{
				if (a[i].first-a[i].second<=1) {f[i][j]=0;continue;}
				int k=std::min(j,a[i].first-a[i].second-1);
				f[i][j]=std::min(a[i].first-a[i].second-1+mn[k],f[i][j]);
			}
			else
			{
				int del=j-a[i].first-a[i].second,k=std::max(0,a[i].first-a[i].second-del-1);
				if (k<=0) f[i][j]=std::min(f[i][j],del);
				else f[i][j]=std::min(f[i][j],a[i].first-a[i].second-1+mn[k]);
			}
		}
	printf("%d\n",f[n][m]);
	return 0;
}