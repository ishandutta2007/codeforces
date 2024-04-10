#include<cstdio>
int a[4];
int f[34][52];
int main()
{
	for(int i=0;i<4;++i)
	{
		scanf("%d",&a[i]),--a[i];
		for(int j=8*i+1;j<=8*(i+1);++j)
			for(int k=1;k<=50;++k)
				f[j][k]=i;
	}
	for(int i=1,i1;i<=4;++i)
	{
		i1=(i%4);
		for(int j=8*(i-1)+1;j<=8*i;j+=2)
		{
			for(int k=2;k<=50;k+=2)
			{
				if(!a[i1])break;
				f[j][k]=i1,--a[i1];
			}
			if(!a[i1])break;
		}
	}
	puts("32 50");
	for(int i=1;i<=32;++i)
	{
		for(int j=1;j<=50;++j)
			printf("%c",f[i][j]+'A');
		puts("");
	}
	return 0;
}