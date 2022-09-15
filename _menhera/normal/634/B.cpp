#include<cstdio>
int main()
{
	long long s, x;
	scanf("%lld%lld",&s,&x);
	
	long long smx = s-x;
	if(smx%2)
	{
		puts("0");
		return 0;
	}
	smx/=2;
	if(smx & x)
	{
		puts("0");
		return 0;
	}
	int cnt = 0;
	for(int i=0; i<50; i++)
		if((1LL<<i) & x) cnt++;
	if(smx)
		printf("%lld",1LL<<cnt);
	else
		printf("%lld",(1LL<<cnt)-2);
	return 0;
}