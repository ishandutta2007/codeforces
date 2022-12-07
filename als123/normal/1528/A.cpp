#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=100005;
vector<LL> vec[N];
LL l[N],r[N];
LL f[N][2];
void dfs (LL x,LL fa)
{
	f[x][0]=f[x][1]=0;
	LL siz=vec[x].size();
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa) continue;
		dfs(y,x);
		f[x][0]=f[x][0]+max(f[y][0]+abs(l[x]-l[y]),f[y][1]+abs(l[x]-r[y]));
		f[x][1]=f[x][1]+max(f[y][0]+abs(r[x]-l[y]),f[y][1]+abs(r[x]-r[y]));
	}
}
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
	LL n;
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) vec[u].clear();
	for (LL u=1;u<=n;u++) scanf("%lld%lld",&l[u],&r[u]);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld\n",max(f[1][0],f[1][1]));
	}
	return 0;
}