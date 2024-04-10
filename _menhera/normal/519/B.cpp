#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	long long fi=0,fi1=0,fi2=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		fi+=x;
	}
	for(int i=0;i<n-1;i++)
	{
		int x;
		scanf("%d",&x);
		fi1+=x;
	}
	for(int i=0;i<n-2;i++)
	{
		int x;
		scanf("%d",&x);
		fi2+=x;
	}
	printf("%I64d \n%I64d \n",fi-fi1,fi1-fi2);
}