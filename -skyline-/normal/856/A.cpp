#include <stdio.h>
#include <bitset>
#include <algorithm>
using namespace std;
bitset<1000001> b1,b2;
int a[201],ans[201];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		b1=bitset<1000001>();
		b2=bitset<1000001>();
		for (int i=1;i<n;++i)
			for (int j=i+1;j<=n;++j)
				b2.set(a[j]-a[i],1);
		int rem=n;
		for (int i=1;i<=1000000&&rem;++i)
			if (b1.test(i)==0)
			{
				ans[rem--]=i;
				b1|=(b2<<i);
			}
		if (rem)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for (int i=1;i<=n;++i)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}