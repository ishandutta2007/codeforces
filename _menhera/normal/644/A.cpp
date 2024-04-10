#include<cstdio>
int arr[100][100];
int main()
{
	int n,a,b;
	int tp=0;
	scanf("%d%d%d",&n,&a,&b);
	if(n>a*b)
	{
		puts("-1");
		return 0;
	}
	for(int i=0; i<a; i++)
	{
		if(i%2==0)
		{
			for(int j=0; j<b; j++)
			{
				if(tp<n) arr[i][j]=++tp;
			}
		}
		else
		{
			for(int j=b-1;j>=0;j--)
			{if(tp<n) arr[i][j]=++tp;
			}
		}
	}
	for(int i=0; i<a ; i++)
	{
		for(int j=0; j<b; j++)
		{
			printf("%d ",arr[i][j]);
		}
		puts("");
	}
}