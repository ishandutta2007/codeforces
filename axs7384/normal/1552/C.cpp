#include<bits/stdc++.h>
using namespace std;
const int N=500;
int t,n,k,used[N],f[N];
pair<int,int> a[N];
inline bool pd(pair<int,int> x,pair<int,int> y)
{
	if (y.first<x.first)
		swap(x,y);
	return y.first<x.second&&x.second<y.second;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n*2;++i)
			used[i]=0;
		for (int i=1;i<=k;++i)
		{
			scanf("%d%d",&a[i].first,&a[i].second);
			if (a[i].first>a[i].second)
				swap(a[i].first,a[i].second);
			used[a[i].first]=used[a[i].second]=1;
		}
		int cnt=0;
		for (int i=1;i<=n*2;++i)
			if (!used[i])
				f[++cnt]=i;
		for (int i=1;i<=n-k;++i)
			a[k+i]=make_pair(f[i],f[i+n-k]);
		int ans=0;
		// for (int i=1;i<=n;++i)
		// 	cout<<a[i].first<<' '<<a[i].second<<endl;
		for (int i=1;i<=n;++i)
			for (int j=i+1;j<=n;++j)
				if (pd(a[i],a[j]))
					++ans;
		printf("%d\n",ans);
	}
	return 0;
}