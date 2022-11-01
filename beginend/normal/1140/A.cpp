#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=10005;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for (int i=1,last;i<=n;i=last+1)
	{
		last=i;int mx=a[i];
		while (last<mx) last++,mx=std::max(mx,a[last]);
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}