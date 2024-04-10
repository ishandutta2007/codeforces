#include<cstdio>
int main()
{
	int l,k,n=0;
	long long t;
	scanf("%d%d",&k,&l);t=k;
	while(t<=l)
	{
		if(t==l)
		{
			printf("YES\n%d\n",n);
			return 0;
		}
		t*=k,n++;
	}
	printf("NO\n");
}