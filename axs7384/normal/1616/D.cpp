#include<bits/stdc++.h>
using namespace std;
int t,n,x;
const int N=100005;
int a[N],f[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		scanf("%d",&x);
		for (int i=1;i<=n;++i)
			a[i]-=x;
		int sum=0;
		for (int i=1;i<=n;++i)
			f[i]=0;
		for (int i=2;i<=n;++i)
		{
			if ((a[i]+a[i-1]<0&&!f[i-1])||(i>=3&&a[i]+a[i-1]+a[i-2]<0&&!f[i-1]&&!f[i-2]))
			{
				f[i]=1;
				++sum;
			}
		}
		printf("%d\n",n-sum);
	}
}