#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int x,t,a,b,da,db;
	scanf("%d %d %d %d %d %d",&x,&t,&a,&b,&da,&db);
	int i;
	if(x==0)
		printf("YES\n");
	else
	{
		int j,k;
		int f=0;
		for(i=0;i<=t;i++)
		{
			for(j=0;j<=t;j++)
			{
				int c=0;
				if(i!=t && j!=t)
				c = a-da*i + b-db*j;
				else if(i==t && j!=t)
					c = b-db*j;
				else if(i!=t && j==t)
					c = a-da*i;
				else
					c = 0;
				if(c == x)
				{
					f=1;
					break;
				}
			}
			if(f)
				break;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}