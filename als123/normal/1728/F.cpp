#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000005;
int n;
int a[N];
vector<int> vec,e[N];
bool used[N];
int f[N];
bool dfs (int x)
{
	if (used[x]) return false;
	used[x]=true;
	for (auto y:e[x])
	{
		if (f[y]==-1||dfs(f[y]))
		{
			f[y]=x;
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
		for (int i=1;i<=n;i++) vec.push_back(a[u]*i);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	int m=vec.size();
	for (int u=1;u<=n;u++)
	for (int i=1;i<=n;i++)
	e[lower_bound(vec.begin(),vec.end(),a[u]*i)-vec.begin()].push_back(u);
	memset(used,false,sizeof(used));
	memset(f,-1,sizeof(f));
	LL ans=0;
	for (int u=0;u<m;u++)
		if (dfs(u))
		{
			ans=ans+vec[u];
			memset(used,false,sizeof(used));
		}
	printf("%lld\n",ans);
	return 0;
}