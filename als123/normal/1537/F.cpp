#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
LL T;
LL n,m;
LL a[N],b[N];
vector<int> vec[N];
bool tf;
LL dep[N];
void dfs (LL x,LL fa)
{
	dep[x]=dep[fa]+1;
	LL siz=vec[x].size();
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa) continue;
		if (dep[y]==-1)
		{
			dfs(y,x);
			a[x]=a[x]+(b[y]-a[y]);
		}
		else
		{
			LL t=dep[x]-dep[y];
			if (t%2==0) tf=true;
		}
	}
}
int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&m);
		for (LL u=1;u<=n;u++) 
		{
			dep[u]=-1;
			vec[u].clear();
		}
		tf=false;
		for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
		for (LL u=1;u<=n;u++) scanf("%lld",&b[u]);
		for (LL u=1;u<=m;u++)
		{
			LL x,y;
			scanf("%lld%lld",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		dfs(1,0);
		if (a[1]==b[1]||(tf==true&&(a[1]-b[1])%2==0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}