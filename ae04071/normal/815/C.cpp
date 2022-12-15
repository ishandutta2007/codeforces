#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

typedef long long lli;
const lli INF=1e9+7;
int n,b;
std::vector<int> child[5001];
int sz[5001],c[5001],d[5001];
lli ft[5001],gt[5001],f[5001][5001],g[5001][5001];

bool cmp(int a, int b) {
	return sz[a]<sz[b];
}
void Cal(int a, int b) {
	int s=sz[a]+sz[b];
	for(int i=1;i<=s;i++) ft[i]=gt[i]=INF;
	for(int i=0;i<=sz[a];i++) for(int j=0;j<=sz[b];j++) {
		ft[i+j]=std::min(ft[i+j],std::min(f[a][i],g[a][i])+std::min(f[b][j],g[b][j]));
		gt[i+j]=std::min(gt[i+j],g[a][i]+g[b][j]);
	}
	for(int i=0;i<=s;i++) {
		f[a][i]=ft[i];
		g[a][i]=gt[i];
	}
	sz[a]=s;
}
void DFS(int node) {
	for(auto &it:child[node]) DFS(it);
	std::sort(child[node].begin(),child[node].end(), cmp);	
	for(auto &it:child[node]) Cal(node,it);
	
	sz[node]++;
	for(int i=sz[node];i>0;i--) {
		f[node][i]=std::min(f[node][i-1],g[node][i-1])+c[node]-d[node];
		g[node][i]=std::min(g[node][i],g[node][i-1]+c[node]);
	}
}

int main() {
	scanf("%d %d",&n,&b);
	int p;
	for(int i=1;i<=n;i++) {
		scanf("%d %d",c+i,d+i);
		if(i!=1) {
			scanf("%d",&p); child[p].push_back(i);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=g[i][j]=INF;
	DFS(1);
	int res=0;
	for(int i=0;i<=n;i++) {
		if(f[1][i]<=b||g[1][i]<=b) res=i;
	}
	printf("%d\n",res);

	return 0;
}