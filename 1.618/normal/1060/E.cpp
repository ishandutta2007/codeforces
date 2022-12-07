#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define maxn 200005
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector <int> adj[maxn];
ll siz0[maxn],sum0[maxn],siz[maxn],sum[maxn],ans[maxn];
void dfs(int u,int f){
	vector <int> lisgs,liss;
	lisgs.clear();
	liss.clear();
	siz0[u] = siz[u] = 1;
	ans[u] = sum0[u] = sum[0] = 0;
	bool son = 0;
	for(int i=0;i<(int)adj[u].size();i++){
		int v = adj[u][i];
		if(v == f) continue;
		son = 1;
		liss.push_back(v);
		dfs(v,u);
		for(int j=0;j<adj[v].size();j++){
			int w = adj[v][j];
			if(w != u) lisgs.push_back(w);
		}
	}
	if(!son) return;
	for(int i=0;i<lisgs.size();i++){
		int v = lisgs[i];
		siz0[u] += siz0[v];
		sum0[u] += siz0[v] + sum0[v];
	}
	siz[u] = siz0[u];
	sum[u] = sum0[u];
	for(int i=0;i<liss.size();i++){
		int v = liss[i];
		sum[u] += sum0[v] + siz0[v];
		siz[u] += siz0[v];
	}
	ans[u] = sum[u];
	for(int i=0;i<liss.size();i++){
		int v = liss[i];
		ans[u] += ans[v];
	}
	ll subsiz0 = siz0[u] - 1;
	ll subsiz1 = siz[u] - siz0[u];
	ll edge11 = 0;
	for(int i=0;i<liss.size();i++){
		int v = liss[i];
		ll siz1 = siz[v] - siz0[v];
		ll sum1 = sum[v] - sum0[v];
		ans[u] += sum1 * (subsiz0 - siz1);
		ans[u] += sum0[v] * (subsiz1 - siz0[v]);
		edge11 += siz0[v] * (subsiz1 - siz0[v]);
		ans[u] += sum1 * (subsiz1 - siz0[v]);
		ans[u] += (sum0[v] + siz0[v]) * (subsiz0 - siz1);
	}
	ans[u] += edge11 / 2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	printf("%I64d\n",ans[1]);
	return 0;
}