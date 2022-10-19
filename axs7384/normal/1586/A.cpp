#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005];
inline bool check(int x)
{
	for (int i=2;i*i<=x;++i)
		if (x%i==0)
			return true;
	return false;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int sum=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if (check(sum))
		{
			printf("%d\n",n);
			for (int j=1;j<=n;++j)
				printf("%d ",j);
			puts("");
		}
		else
		{
			printf("%d\n",n-1);
			for (int i=1;i<=n;++i)
				if (a[i]%2==1)
				{
					for (int j=1;j<=n;++j)
						if (i!=j)
							printf("%d ",j);
					puts("");
					break;
				}
		}
	}
	return 0;
}