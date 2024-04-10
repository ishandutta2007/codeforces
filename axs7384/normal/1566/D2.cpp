#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct dt
{
	int x,id;
	bool operator<(const dt &a)const
	{
		return x==a.x?id<a.id:x<a.x;
	}
}a[N];
int t,n,m;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n*m;++i)
		{
			scanf("%d",&a[i].x);
			a[i].id=i;
		}
		int ans=0;
		sort(a+1,a+1+n*m);
		// for (int i=1;i<=n*m;++i)
		// 	cout<<a[i].x<<' '<<a[i].id<<endl;
		for (int i=0;i<n*m;i+=m)
			for (int j=1;j<=m;++j)
				for (int k=j+1;k<=m;++k)
					if (a[i+j].id<a[i+k].id&&a[i+j].x!=a[i+k].x)
						++ans;
		printf("%d\n",ans);
	}
	return 0;
}