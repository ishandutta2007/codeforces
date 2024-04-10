#include<bits/stdc++.h>
using namespace std;
int N, M, K;
int c[1010];
bool vis[1010];
vector<int> conn[1010];
vector<int> sz;
int dfs(int a)
{
	if(vis[a]) return 0;
	vis[a]=true;
	int ans = 1;
	for(int c: conn[a])
		ans += dfs(c);
	return ans;
}
int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0; i<K; i++)
		scanf("%d",c+i);
	for(int i=0; i<M; i++)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	for(int i=0; i<K; i++)
		sz.push_back(dfs(c[i]));	
	sort(sz.begin(), sz.end());
	reverse(sz.begin(), sz.end());
	int sum =0;
	for(int c: sz) sum += c;
	sz[0] += N-sum;
	sum = 0;
	for(int c: sz) sum += c*(c-1)/2;
	printf("%d\n",sum-M);
	return 0;
}