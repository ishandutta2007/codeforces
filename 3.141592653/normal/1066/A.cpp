#include<cstdio>
#include<algorithm>
typedef long long ll;
ll l,r,v,L;
ll inc(ll R)
{return R/v;}
void exec()
{
	int n;
	scanf("%I64d%I64d%I64d%I64d",&L,&v,&l,&r);
	printf("%I64d\n",inc(L)-inc(r)+inc(l-1));
	
}
int main()
{
	int T;
	scanf("%d",&T);
	//T=1;
	while(T--)exec();
}