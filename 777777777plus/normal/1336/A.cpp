#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,k,fa[N],d[N],sz[N],w[N];
vector<int> g[N];

void dfs(int x){
	sz[x]=1;
	for(int i=0;i<g[x].size();++i)
	if(g[x][i]!=fa[x]){
		int y=g[x][i];
		fa[y]=x;
		d[y]=d[x]+1;
		dfs(y);
		sz[x]+=sz[y];
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	for(int i=1;i<=n;++i)w[i]=d[i]-sz[i]+1;
	sort(w+1,w+n+1);
	reverse(w+1,w+n+1);
	ll ans=0;
	for(int i=1;i<=k;++i)ans+=w[i];
	printf("%lld\n",ans);
}