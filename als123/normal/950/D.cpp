#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,q;
int main()
{
	scanf("%I64d%I64d",&n,&q);
	while (q--)
	{
		LL x;
		scanf("%I64d",&x);
		while (x%2==0)
		{
			x=n+(x/2);
		}
		printf("%I64d\n",(x+1)/2);
	}
	return 0;
}