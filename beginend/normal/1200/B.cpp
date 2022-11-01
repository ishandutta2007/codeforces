#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n,m,k,a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		bool flag=0;
		for (int i=1;i<n;i++)
		{
			int x=a[i],y=std::max(0,a[i+1]-k);
			if (x>=y) m+=x-y;
			else if (y-x<=m) m-=y-x;
			else {flag=1;break;}
		}
		puts(!flag?"YES":"NO");
	}
	return 0;
}