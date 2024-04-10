#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define pi 3.14159265359
#define zero(a) (abb(a)<=1e-7)
#define lowbit(a) ((a)&(-(a)))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abb(a) ((a)>0?(a):(-(a)))

int main()
{
	int i=1,n,m;
	scanf("%d%d",&n,&m);
	while (1)
	{
		if (m<i)
			break;
		m-=i;
		i=i%n+1;
	}
	printf("%d\n",m);
	return 0;
}