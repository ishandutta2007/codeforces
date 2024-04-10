#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,i,a[200005];
int Abs(int a)
{
	return a>0?a:-a;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",a+i);
		for(i=1;i<n;++i)
			if(Abs(a[i]-a[i+1])>=2)
				break;
		if(i<n)
		{
			printf("YES\n%d %d\n",i,i+1);
			continue;
		}
		puts("NO");
	}
	return 0;
}