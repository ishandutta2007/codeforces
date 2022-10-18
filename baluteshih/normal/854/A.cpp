#include <stdio.h>

int gcd(int a,int b)
{
	int t;
	while(b) t=a%b,a=b,b=t;
	return a;
}

int main()
{
	int n,a,b,i;
	scanf("%d",&n),a=1,b=n-1;
	for(i=2;i*2<n;i++)
		if(gcd(i,n-i)==1 && a*(n-i)<i*b) a=i,b=(n-i);
	printf("%d %d\n",a,b);
}