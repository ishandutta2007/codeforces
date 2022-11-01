#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n/2;i++)
		for (int j=1;j<=m;j++)
			printf("%d %d\n%d %d\n",i,j,n-i+1,m-j+1);
	if (n&1)
	{
		for (int j=1;j<=m/2;j++)
			printf("%d %d\n%d %d\n",n/2+1,j,n/2+1,m-j+1);
		if (m&1) printf("%d %d\n",n/2+1,m/2+1);
	}
	return 0;
}