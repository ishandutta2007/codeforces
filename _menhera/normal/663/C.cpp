#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int, char> > conn[101010];
vector<int> ans;
bool valid;
int visit[101010];
vector<int> c1;
vector<int> c2;
void dfs(int a, int v)
{
//	printf("%d %d\n",a,v);
	if(visit[a]==v) return;
	if(visit[a]+v==3)
	{
		valid=false;
		return;
	}
	visit[a]=v;
	if(v==1) c1.push_back(a);
	else c2.push_back(a);
	for(auto x: conn[a])
	{
		if(x.second=='B')v=3-v;
		dfs(x.first, v);
		if(x.second=='B') v= 3-v;
	}
}
void solve()
{
	memset(visit, 0, sizeof(visit));
	for(int i=1; i<=N; i++)
		if(!visit[i])
		{
			c1.clear();
			c2.clear();
			dfs(i, 1);
			if(!valid) return;
			if(c1.size() > c2.size())
				c1 = c2;
			for(int i: c1)
				ans.push_back(i);
		}
//	printf("%d\n",ans.size());
	return;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0; i<M; i++)
	{
		int u, v; char c;
		scanf("%d%d %c",&u,&v,&c);
		conn[u].emplace_back(v, c);
		conn[v].emplace_back(u, c);
	}
	valid=true;
	solve();
	bool validv= false;
	vector<int> ansv(N+1);
	if(valid)
	{
		validv= true;
		ansv = ans;
//		puts("ok");
	}
//	printf("<%d>\n",ansv.size());
	ans.clear();
//	printf("<%d>\n",ansv.size());
	for(int i=1; i<=N; i++)
		for(auto& x: conn[i])
			x.second = 'B'^'R'^x.second;
	valid = true;
	solve();
	if(valid)
	{
//		puts("ok");
		validv=true;
		if(ansv.size()>ans.size())
			ansv=ans;
	}
	if(validv)
	{
		printf("%d\n",ansv.size());
		for(int i: ansv)
			printf("%d ", i);
		puts("");
	}
	else
	{
		puts("-1");
	}
	return 0;
}