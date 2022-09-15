#include<bits/stdc++.h>
using namespace std;

const int MAXN = 202020;
int N, K;
vector<int> conn[MAXN];
int sz[MAXN];
int hh[MAXN];
int dfs(int a, int pa, int h)
{
	sz[a] = 1;
	hh[a] = h;
	for(auto x: conn[a])
		if(x != pa)
			sz[a] += dfs(x, a, h+1);
	return sz[a];
}
int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i<N-1; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	dfs(1, 0, 0);
	vector<int> V;
	for(int i=1; i<=N; ++i)
		V.push_back(hh[i]-sz[i]+1);
	sort(V.rbegin(), V.rend());
	long long ans = 0;
	for(int i=0; i<K; ++i)
		ans += V[i];
	printf("%lld\n", ans);
}