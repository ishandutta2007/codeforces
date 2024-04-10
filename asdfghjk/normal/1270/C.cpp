#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,i,a[200005];
long long X,Y;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		X=Y=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			X+=a[i],Y^=a[i];
		}
		printf("2\n");
		printf("%lld %lld\n",Y,X+Y);
	}
	return 0;
}