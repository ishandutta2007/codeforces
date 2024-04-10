#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <map>
#include <stack>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int n;
vector<int> adj[300001];
int sz[300001],pa[300001];

int dfs(int cur,int p) {
	pa[cur]=p;
	sz[cur]=1;
	for(auto &it:adj[cur]) if(it!=p) {
		sz[cur]+=dfs(it,cur);
	}
	return sz[cur];
}
int find_path(int cur,int t) {
	if(cur==0) return 0;

	if(cur==t) return -2;

	int tt=find_path(pa[cur],t);
	if(tt==-2) return cur;
	else return tt;
}
int main() {
	int x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	if(n<=2) {
		printf("1\n");
		return 0;
	}
	int r=1;
	for(;r<=n && (r==x || r==y);r++);

	lli ans=1ll*n*(n-1);
	dfs(r,0);
	int v=find_path(x,y);
	if(v!=0) {
		int a=sz[x],b=sz[r]-sz[v];
		ans-=1ll*a*b;
	}
	else {
		v=find_path(y,x);
		if(v!=0) {
			int a=sz[y],b=sz[r]-sz[v];
			ans-=1ll*a*b;
		}
		else ans-=1ll*sz[x]*sz[y];
	}
	printf("%lld\n",ans);
	
	return 0;
}