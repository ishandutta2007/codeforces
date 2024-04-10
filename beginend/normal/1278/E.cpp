#include<bits/stdc++.h>
#define pb push_back

const int N=1000005;

int n,lef[N],rig[N],id,son[N];
std::vector<int> e[N],ls[N],rs[N];

void dfs(int x,int fa)
{
	int tot=0;
	for (auto to:e[x])
		if (to!=fa) son[++tot]=to;
	for (int i=1;i<=tot;i++) ls[x*2-1].pb(son[i]*2-1);
	for (int i=tot;i>=1;i--) rs[x*2-1].pb(son[i]*2);
	for (auto to:e[x])
		if (to!=fa) dfs(to,x);
}

void solve(int x)
{
	for (auto to:ls[x]) solve(to);
	if (x)
	{
		id++;
		if (x&1) lef[x/2+1]=id;
		else rig[x/2]=id;
	}
	for (auto to:rs[x]) solve(to);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
	}
	dfs(1,0);
	ls[0].pb(1);rs[0].pb(2);
	solve(0);
	for (int i=1;i<=n;i++) printf("%d %d\n",lef[i],rig[i]);
	return 0;
}