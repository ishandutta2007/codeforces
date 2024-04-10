#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MIN(x,y) x=std::min(x,y)

const int N=5005;
const int inf=1000000000;

int n,a[N],f[2][N][2][2];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=-1;
	for (int i=0;i<=n;i++) f[0][i][0][0]=f[0][i][0][1]=f[0][i][1][0]=inf;
	f[0][0][0][0]=0;
	int now=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=i+1;j++) f[now^1][j][0][0]=f[now^1][j][0][1]=f[now^1][j][1][0]=inf;
		for (int j=0;j<=i;j++)
		{
			if (f[now][j][0][0]<inf)
			{
				MIN(f[now^1][j][0][0],f[now][j][0][0]);
				MIN(f[now^1][j+1][0][1],f[now][j][0][0]+std::max(0,a[i]-a[i+1]+1));
			}
			if (f[now][j][0][1]<inf)
			{
				MIN(f[now^1][j][1][0],f[now][j][0][1]+std::max(0,a[i+1]-a[i]+1));
			}
			if (f[now][j][1][0]<inf)
			{
				MIN(f[now^1][j][0][0],f[now][j][1][0]);
				MIN(f[now^1][j+1][0][1],f[now][j][1][0]+std::max(0,std::min(a[i-1]-1,a[i])-a[i+1]+1));
			}
		}
		now^=1;
	}
	for (int i=1;i<=(n+1)/2;i++)
		printf("%d ",std::min(f[now][i][0][0],std::min(f[now][i][0][1],f[now][i][1][0])));
	return 0;
}