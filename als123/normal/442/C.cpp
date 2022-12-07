#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=500005;
LL n;
LL sta[N],top=0;
LL ans=0;
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)
	{
		LL x;
		scanf("%lld",&x);
		while (top>=2)
		{
			//printf("%lld %lld %lld\n",u,sta[top-1],sta[top]);
			if (sta[top-1]>=sta[top]&&sta[top]<=x)
			{	
				//printf("YES:%lld\n",u);
				ans=ans+min(x,sta[top-1]);
				top--;
			}
			else break;
		}
		sta[++top]=x;
	}
	/*for (LL u=1;u<=top;u++) printf("%lld ",sta[u]);
	printf("\n");*/
	sort(sta+1,sta+1+top);
	for (LL u=1;u<=top-2;u++)	ans=ans+sta[u];
	printf("%I64d\n",ans);
	return 0;
}