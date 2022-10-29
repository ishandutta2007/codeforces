#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n/2;++i)
	{
		for(j=1;j<=m;++j)
		{
			printf("%d %d\n",i,j);
			printf("%d %d\n",n-i+1,m-j+1);
		}
	}
	if(n&1)
	{
		i=(n+1)/2;
		for(j=1;j<=m/2;++j)
		{
			printf("%d %d\n",i,j);
			printf("%d %d\n",i,m-j+1);
		}
		if(m&1)
			printf("%d %d",i,j);
	}
	return 0;
}