#include <stdio.h>

int main()
{
	int a,b,a2,b2,p,q,i,j;
	scanf("%d%d",&a,&b);
	a2=a*a;
	b2=b*b;
	for(i=-1000;i<=1000;i++)
	{
		for(j=-1000;j<=1000;j++)
		{
			if((b*j)%a==0&&(b*i)%a==0)
			{
				p=-b*j/a;
				q=b*i/a;
				if(i*i+j*j==a2&&p*p+q*q==b2&&i!=0&&j!=0&&i!=p&&j!=q)
				{
					printf("YES\n0 0\n%d %d\n%d %d",i,j,p,q);
					return 0;
				}
			}
		}
	}
	printf("NO");
	return 0;
}