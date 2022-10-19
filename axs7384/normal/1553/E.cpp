#include<bits/stdc++.h>
using namespace std;
int t,n,m;
const int N=300005;
int a[N],f[N],vis[N];
vector<int> v;
inline void dfs(int x,int y)
{
	vis[x]=1;
	int p=a[x]+y;
	if (p>n)
		p-=n;
	if (!vis[p])
		dfs(p,y);
}
inline bool check(int x)
{
	int sum=0;
	for (int i=1;i<=n;++i)
		vis[i]=0;
	for (int i=1;i<=n;++i)
		if ((a[i]+x)%n!=i%n)
		{
			if (vis[i])
				++sum;
			else
				dfs(i,x);
		}
	return sum<=m;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=0;i<n;++i)
			f[i]=0;
		for (int i=1;i<=n;++i)
		{
			int p=i-a[i];
			if (p<0)
				p+=n;
			++f[p];
		}
		v.clear();
		for (int i=0;i<n;++i)
			if (f[i]>=n-m*2)
			{
				if (check(i))
					v.push_back(i);
			}
		printf("%d",(int)v.size());
		for (int i=0;i<(int)v.size();++i)
			printf(" %d",v[i]);
		puts("");
	}
	return 0;
}