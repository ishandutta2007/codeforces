#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX(x,y) x=max(x,y)
using namespace std;

const int N=2005;

int n,a[N],f[N][2][2][2];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]--;
	int ans=0;
	for (int i=0;i<=n;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				for (int l=0;l<2;l++)
				{
					ans=max(ans,f[i][j][k][l]);
					if (k&&!l) continue;
					if (a[i+1]>=j) MAX(f[i+1][a[i+1]][0][l],f[i][j][k][l]+1);
					if (k&&(a[i+1]^1)>=j||!l&&(a[i+1]^1)>=j) MAX(f[i+1][a[i+1]^1][1][1],f[i][j][k][l]+1);
					MAX(f[i+1][j][k][l],f[i][j][k][l]);
				}
	printf("%d",ans);
	return 0;
}