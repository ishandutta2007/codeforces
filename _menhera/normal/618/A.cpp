#include<cstdio>
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=20; i>=0; i--)
	{
		if( N & (1<<i) ) printf("%d ",i+1);
	}
	return 0;
}