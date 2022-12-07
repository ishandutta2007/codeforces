#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,k;
vector<int> vec[N];
int sta[N],top;
int f1[N],f2[N];
void dfs (int x,int fa)
{
	sta[++top]=x;
	if (vec[x].empty())
	{
		f1[x]++;
		if (top>k) f1[sta[top-k]]--;
	}
	for (auto y:vec[x])
	{
		if (y==fa) continue;
		dfs(y,x);
	}
	top--;
}
int ans=0;
int f[N],g[N];//    
void solve (int x,int fa)
{
	if (vec[x].empty()) f[x]=1,g[x]=1;
	for (auto y:vec[x])
	{
		if (y==fa) continue;
		solve(y,x);
		f1[x]+=f1[y];
	}
	for (auto y:vec[x])
	{
		if (y==fa) continue;
		//if (x==1) printf("OK:%d %d %d\n",y,f1[y],f[y]);
		if (f1[y]>0) f[x]=f[x]+f[y];
	}
//	printf("z:%d %d\n",x,f[x]);
	for (auto y:vec[x])
	{
		if (y==fa) continue;
		if (f1[y]>0) g[x]=max(g[x],f[x]-f[y]+g[y]);
		else 		 g[x]=max(g[x],f[x]+g[y]);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=2;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		vec[x].push_back(u);
	}
	dfs(1,0);
	solve(1,0);
	printf("%d\n",g[1]);
	return 0;
}