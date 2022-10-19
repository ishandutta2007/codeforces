#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[1000][1000];
inline bool check(int x,int y)
{
	for (int i=-1;i<=1;++i)
		for (int j=-1;j<=1;++j)
			if (a[x+i][y+j])
				return false;
	return true;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n+1;++i)
			for (int j=0;j<=m+1;++j)
				a[i][j]=0;
		for (int i=1;i<=m;++i)
			if (check(1,i))
				a[1][i]=1;
		for (int i=2;i<n;++i)
			if (check(i,m))
				a[i][m]=1;
		for (int i=m;i>=1;--i)
			if (check(n,i))
				a[n][i]=1;
		for (int i=n-1;i>=2;--i)
			if (check(i,1))
				a[i][1]=1;
		for (int i=1;i<=n;++i,puts(""))
			for (int j=1;j<=m;++j)
				printf("%d",a[i][j]);
		puts("");
	}
	return 0;
}