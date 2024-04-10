#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
const int MAXN = 5010;

int n, m, k, u, v, x, y, t, a, b, ans;
int C[MAXN], P[MAXN], D[MAXN], match[MAXN], out[MAXN];
bitset<MAXN> mark, abcd;
vector<int> G[MAXN];

bool dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (match[v]==-1 || !mark[match[v]] && dfs(match[v])){
		match[v]=node;
		return 1;
	}
	return 0;
}

void addedge(int id){
	G[P[id]].push_back(C[id]);
	mark.reset();
	while (dfs(ans)) ans++, mark.reset();
}

int main(){
	memset(match, -1, sizeof(match));
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%d", P+i);
	for (int i=1; i<=n; i++) scanf("%d", C+i);
	scanf("%d", &k);
	for (int i=1; i<=k; i++){
		scanf("%d", D+i);
		abcd[D[i]]=1;
	}
	for (int i=1; i<=n; i++) if (!abcd[i]) addedge(i);
	
	for (int i=k; i; i--){
		out[i]=ans;
		addedge(D[i]);
	}
	
	for (int i=1; i<=k; i++) printf("%d\n", out[i]);
	
	return 0;
}