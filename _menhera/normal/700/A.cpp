#include<cstdio>
int main()
{
	int n,l,v1,v2,k;
	scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k);
	n = (n+k-1)/k;
	double y = 1.0*l*(v2+v1)/(1.0*(2*n-1)*v1+v2);
	double ans = y/v2 +(l-y)/v1;
	printf("%.12f\n",ans);
}