#include<cstdio>
#include<algorithm>
typedef long long LL;
LL  n,k;
LL mx,ans,ans1;;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	mx=n;
	for (LL u=1;u<=k;u++) 
	{
		LL x;
		scanf("%I64d",&x);
		LL a=n%x,b=n/x;
		if (a<mx)
		{
			mx=a;ans=u;ans1=b;
		}
	}
	if (mx==n) printf("1 0\n");
	else printf("%I64d %I64d\n",ans,ans1);
	return 0;
}