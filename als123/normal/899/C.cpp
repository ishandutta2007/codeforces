#include<cstdio>
#include<cstring>
const int N=60005;
int n;
int a[N],tot;
int main()
{
	scanf("%d",&n);
	while (n>=4)
	{
		a[++tot]=n;
		a[++tot]=n-3;
		n-=4;
	}
	int lalal=0;
	if (n==1) a[++tot]=1,lalal=1;
	else if (n==2) a[++tot]=2,lalal=1;
	else if (n==3) a[++tot]=2,a[++tot]=1;
	printf("%d\n",lalal);
	printf("%d ",tot);
	for (int u=tot;u>=1;u--) printf("%d ",a[u]);
	return 0;
}