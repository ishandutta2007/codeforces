#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int l=n,r=0;
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<n;++i)
			if (a[i]==a[i+1])
			{
				if (l==n)
					l=i;
				r=i;
			}
		if ((l==n&&r==0)||l==r)
			puts("0");
		else
			printf("%d\n",max(1,r-l-1));
	}
	return 0;
}