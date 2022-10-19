#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],f[N],g[N],f1[N],g1[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=2;i<=n;++i)
		if (a[i]>a[i-1])
			f[i]=f[i-1]+1;
	for (int i=n-1;i;--i)
		if (a[i]>a[i+1])
			g[i]=g[i+1]+1;
	for (int i=1;i<=n;++i)
		f1[i]=max(f1[i-1],max(f[i],g[i]));
	for (int i=n;i;--i)
		g1[i]=max(g1[i+1],max(g[i],f[i]));
	int ans=0;
	for (int i=3;i<=n-2;++i)
		if (f[i]>=2&&g[i]>=2)
		{
			if (max(f1[i-f[i]],g1[i+g[i]])>=max(f[i],g[i]))
				continue;
			if (max(f[i],g[i])-min(f[i],g[i])>=2)
				continue;
			if (f[i]==g[i]&&f[i]%2==0)
			{
				ans=1;
				break;
			}
		}
	printf("%d",ans);
	return 0;
}