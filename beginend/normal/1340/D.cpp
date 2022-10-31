#include<bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=100005;

int n,tot,deg[N];
vector<int> e[N];
pair<int,int> ans[1000005];

void dfs(int x,int fa,int t)
{
	ans[++tot]=make_pair(x,t);
	int k,tmp=t-1;
	if (x==1) k=deg[x];
	else k=deg[x]-t;
	if (k<0) k=0;
	int ret=deg[x]-1;
	for (auto to:e[x])
	{
		if (to==fa) continue;
		if (!k) t=t-ret-1,ans[++tot]=make_pair(x,t),k=n;
		dfs(to,x,t+1);
		t++;
		k--;
	}
	if (!fa) return;
	if (t>tmp) t=tmp,ans[++tot]=make_pair(x,t);
	ans[++tot]=make_pair(fa,t+1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
		deg[x]++;deg[y]++;
	}
	dfs(1,0,0);
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}