#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=2005;
LL a[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		LL n,sum=0,x;
		scanf("%lld",&n);
		for (int u=1;u<=n;u++)
		{
			scanf("%d",&a[u]);
			sum^=a[u];
		}
		LL cnt=0,now=0;
		for (int i=1;i<=n;i++)
		{
			now^=a[i];
			if (now==sum) 
			{
				now=0;
				cnt++;
			}
		}
		if (sum==0) cnt=n;
		if (cnt>=2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}