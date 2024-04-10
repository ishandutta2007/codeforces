#include<bits/stdc++.h>

const int N=1005;

int n,m,a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=2;i<=n;i++)
		{
			int k=std::min(m-a[1],a[i]);
			a[i]-=k;a[1]+=k;
		}
		printf("%d\n",a[1]);
	}
	return 0;
}