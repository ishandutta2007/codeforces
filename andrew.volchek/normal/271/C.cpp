#include <stdio.h>


int main()
{
	long n,k;
	scanf("%ld %ld",&n,&k);


	if(k*3>n)
	{
		printf("-1");
	}
	else
	{
		if(k%2)
		{
			for(long i=0;i<k;i++)
			{
				if(i)
					printf(" ");
				printf("%ld",i+1);
			}
			for(long i=1;i<k;i++)
			{
				if(i)
					printf(" ");
				printf("%ld",i+1);
			}
			printf(" 1");
			for(long i=2*k+1;i<=n;i++)
			{
				printf(" ");
				printf("%ld",i%k+1);
			}
		}
		else
		{
			for(long i=0;i<k;i++)
			{
				if(i)
					printf(" ");
				printf("%ld",i+1);
			}
			for(long i=0;i<k;i++)
			{
			//	if(i)
					printf(" ");
				printf("%ld",k-i);
			}
			//printf(" 1");
			for(long i=2*k+1;i<=n;i++)
			{
				printf(" ");
				printf("%ld",i%k+1);
			}
		}
	}
	return 0;
}