#include<bits/stdc++.h>

const int N=100005;

int n,a[N],b[N],tim[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),tim[b[i]]=i;
	int ans=0,mx=0;
	for (int i=1;i<=n;i++)
	{
		if (tim[a[i]]<mx) ans++;
		mx=std::max(mx,tim[a[i]]);
	}
	printf("%d\n",ans);
	return 0;
}