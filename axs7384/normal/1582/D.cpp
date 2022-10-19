#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=1000005;
int a[N],b[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if (n%2==1)
		{
			b[1]=a[3];
			b[2]=a[3];
			b[3]=-(a[1]+a[2]);
			if (b[3]==0)
			{
				b[1]=a[2];
				b[3]=a[2];
				b[2]=-(a[1]+a[3]);
				if (b[2]==0)
				{
					b[2]=b[3]=a[1];
					b[1]=-(a[2]+a[3]);
				}
			}
			for (int i=4;i<=n;i+=2)
			{
				b[i]=a[i+1];
				b[i+1]=-a[i];
				int p=__gcd(b[i],b[i+1]);
				b[i]/=p;
				b[i+1]/=p;
			}
		}
		else
		{
			for (int i=1;i<=n;i+=2)
			{
				b[i]=a[i+1];
				b[i+1]=-a[i];
				int p=__gcd(b[i],b[i+1]);
				b[i]/=p;
				b[i+1]/=p;
			}
		}
		for (int i=1;i<=n;++i)
			printf("%d ",b[i]);
		puts("");
	}
	return 0;
}