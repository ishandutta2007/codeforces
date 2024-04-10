#include<cstdio>
int N;
int a[101010];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
		while(a[i]%3==0)
			a[i]/=3;
		while(a[i]%2==0)
			a[i]/=2;
		if(a[i]!=a[0])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}