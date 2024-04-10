#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if((i+j)&1)printf("720720 ");
			else printf("%d ",720720-a[i][j]*a[i][j]*a[i][j]*a[i][j]);
		}
		if((i+m)&1)printf("720720\n");
		else printf("%d\n",720720-a[i][m]*a[i][m]*a[i][m]*a[i][m]);
	}
	return 0;
}