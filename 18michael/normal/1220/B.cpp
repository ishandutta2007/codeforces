#include<cstdio>
#include<cmath>
int n,n1;
long long a;
long long b[1005];
int main()
{
	scanf("%d",&n),n1=n+2;
	for(int i=0;i<=n1;++i)
		scanf("%lld",&b[i]);
	printf("%lld",(a=sqrt(b[1]*b[2]/b[n1])));
	for(int i=1;i<n;++i)
		printf(" %lld",b[i]/a);
	return 0;
}