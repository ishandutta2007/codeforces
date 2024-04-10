#include<cstdio>
int n,Test_num;
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d",&n);
		if(n==1)puts("a");
		else
		{
			for(int i=1;i<=n/2;++i)printf("a");
			printf("b");
			for(int i=1;i<n/2;++i)printf("a");
			puts(n&1? "c":"");
		}
	}
	return 0;
}