#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> conn[101010];
int C[101010];
bool vis[101010];

int solve(int a)
{
	int ans = C[a];
	for(auto x: conn[a]) if(!vis[x])
	{
		vis[x] = true;
		ans=min(ans, solve(x));
	}
	return ans;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; ++i) scanf("%d", C+i);
	for(int i=0; i<M; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	long long ans = 0;
	for(int i=1; i<=N; ++i)
		if(!vis[i])
		{
			vis[i] = true;
			ans += solve(i);
		}
	printf("%lld\n", ans);
}