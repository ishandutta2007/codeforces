#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n,sz[N],f[N];
vector<int> g[N],b[N];

void dfs(int x,int k,int fa,int &ret,int &retfa,int &retson){
	sz[x]=1;
	for(int i=0;i<g[x].size();++i)
	if(!b[x][i]&&g[x][i]!=fa){
		int y=g[x][i];
		dfs(y,k,x,ret,retfa,retson);
		sz[x]+=sz[y];
		if(sz[y]==f[k-1]||sz[y]==f[k-2])ret=y,retfa=x,retson=i;
	}
}

int main(){
	f[0]=f[1]=1;
	for(int i=2;i<=30;++i)f[i]=f[i-1]+f[i-2];
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		b[x].push_back(0);
		g[y].push_back(x);
		b[y].push_back(0);
	}
	for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end());
	queue<pair<int,int>> q;
	int k=0;
	for(int i=1;i<=30;++i)
	if(f[i]==n)k=i;
	if(!k){
		puts("NO");
		return 0;
	}
	q.push({1,k});
	while(!q.empty()){
		int x=q.front().first,k=q.front().second;q.pop();
		int y=0,fa=0,son=0;
		if(k<=2)continue;
		dfs(x,k,-1,y,fa,son);
		//assert(sz[x]==f[k]);
		if(!y){
			puts("NO");
			return 0;
		}
		b[fa][son]=1;
		int p=lower_bound(g[y].begin(),g[y].end(),fa)-g[y].begin();
		b[y][p]=1;
		//assert(g[y][p]==fa);
		if(sz[y]==f[k-1]){
			q.push({y,k-1});
			q.push({fa,k-2});
		}
		else{
			q.push({y,k-2});
			q.push({fa,k-1});
		}
	}
	puts("YES");
}