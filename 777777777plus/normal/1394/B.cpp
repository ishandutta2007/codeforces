#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,m,k;
int head[N];
vector<pair<int,int>> g[N];
vector<int> f[10][10];
bool cross[10][10][10][10];
bool flag[10][10];
int ans;

void dfs(int x,int cnt=0){
	static int res[N];
	if(x>k){
		if(cnt==n){
			ans++;
		}
		return;
	}
	for(int i=1;i<=x;++i){
		if(flag[x][i])continue;
		bool flag=true;
		for(int j=1;j<x;++j)
		if(cross[x][i][j][res[j]]){
			flag=false;
		}
		if(flag){
			res[x]=i;
			dfs(x+1,cnt+f[x][i].size());
		}
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=1,x,y,w;i<=m;++i){
		scanf("%d%d%d",&x,&y,&w);
		g[x].push_back({w,y});
	}
	for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end());
	for(int i=1;i<=n;++i){
		int x=g[i].size();
		for(int j=0;j<x;++j){
			f[x][j+1].push_back(g[i][j].second);
		}
	}
	for(int i=1;i<=k;++i)
	for(int j=1;j<=i;++j){
		static int tot;
		static int vis[N];
		++tot;
		for(int t=0;t<f[i][j].size();++t){
			if(vis[f[i][j][t]]==tot)flag[i][j]=true;
			vis[f[i][j][t]]=tot;
		}
		if(flag[i][j])continue;
		for(int i1=1;i1<i;++i1)
		for(int j1=1;j1<=i1;++j1){
			for(int t=0;t<f[i1][j1].size();++t)
			if(vis[f[i1][j1][t]]==tot){
				cross[i][j][i1][j1]=true;
				break;
			}
		}
	}
	dfs(1);
	cout<<ans<<endl;
}