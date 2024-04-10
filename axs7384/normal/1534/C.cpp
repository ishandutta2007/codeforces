#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int t,n,x,y,fa[N],a[N],b[N];
const int mod=1e9+7;
inline int getfa(int x)
{
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
inline void _union(int x,int y)
{
	int fx=getfa(x),fy=getfa(y);
	if (fx!=fy)
		fa[fx]=fy;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			fa[i]=i;
		// for (int i=1;i<=n;++i)
		// {
		// 	scanf("%d%d",&x,&y);
		// 	_union(x,y);
		// }
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		for (int i=1;i<=n;++i)
			_union(a[i],b[i]);
		for (int i=1;i<=n;++i)
			getfa(i);
		int sum=0;
		for (int i=1;i<=n;++i)
			if (i==fa[i])
				++sum;
		int ans=1;
		for (int i=1;i<=sum;++i)
			(ans*=2)%=mod;
		cout<<ans<<endl;
	}
	return 0;
}