#include<cstdio>
const int maxn=200;
int n,a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<n;j++)if(a[j]>a[j+1])
		{
			printf("%d %d\n",j,j+1);
			int t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
	return 0;
}