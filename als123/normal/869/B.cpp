#include<cstdio>
typedef long long LL;
LL a,b;
int main()
{
	scanf("%I64d%I64d",&a,&b);
	LL shen=1,aa=0;
	for (LL u=a+1;u<=b;u++)
	{
		if (u%2==0)
		{
			if (aa==5)
			{
				printf("0\n");
				return 0;
			}
			aa=2;
		}
		if (u%5==0)
		{
			if (aa==2)
			{
				printf("0\n");
				return 0;
			}
			aa=5;
		}
		shen=(shen*(u%10))%10;
	}
	printf("%I64d\n",shen);
	return 0;
}