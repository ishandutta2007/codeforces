#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 5e3+5;

int n,m,c[3],ans[N];
int cnt;
bool col[N],vis[N];
vector<int> g[N],a[N],b[N];
int f[N][N],pre[N][N];

void dfs(int x){
	vis[x]=1;
	if(col[x])a[cnt].push_back(x);
	else b[cnt].push_back(x);
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(!vis[y]){
			col[y]=col[x]^1;
			dfs(y);
		}
		else if(col[y]==col[x]){
			puts("NO");
			exit(0);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<3;++i)scanf("%d",&c[i]);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	if(!vis[i]){
		col[i]=0;
		++cnt;
		dfs(i);
		for(int j=0;j<=n;++j){
			if(j>=a[cnt].size()&&f[cnt-1][j-a[cnt].size()]){
				f[cnt][j]=1;
				pre[cnt][j]=1;
			}
			if(j>=b[cnt].size()&&f[cnt-1][j-b[cnt].size()]){
				f[cnt][j]=1;
				pre[cnt][j]=0;
			}
		}
	}
	if(!f[cnt][c[1]]){
		puts("NO");
		return 0;
	}
	for(int i=cnt,tot=c[1];i>=1;--i){
		bool type=pre[i][tot];
		if(type){
			for(int j=0;j<a[i].size();++j){
				ans[a[i][j]]=2;
			}
			tot-=a[i].size();
		}
		else{
			for(int j=0;j<b[i].size();++j){
				ans[b[i][j]]=2;
			}
			tot-=b[i].size();
		}
	}
	for(int i=1;i<=n;++i)
	if(!ans[i]){
		if(c[0]){
			ans[i]=1;
			c[0]--;
		}
		else{
			ans[i]=3;
		}
	}
	puts("YES");
	for(int i=1;i<=n;++i)printf("%d",ans[i]);
}