#include<cstdio>
#include<cstring>
void exec()
{
	int n;
	long long sm=0,xr=0,g;
	scanf("%d",&n);
	while(n--)scanf("%I64d",&g),sm+=g,xr^=g;
	printf("2\n%I64d %I64d\n",sm+xr,xr);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/