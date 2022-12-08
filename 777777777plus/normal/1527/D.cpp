#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T;
int n,totw,fa[N],st[N],ed[N],sz[N];
ll ans[N];
bool vis[N];
vector<int> g[N];

void dfs(int x){
	sz[x]=1;
	st[x]=++totw;
	for(int i=0;i<g[x].size();++i){
		int y=g[x][i];
		if(fa[x]==y)continue;
		fa[y]=x;
		dfs(y);
		sz[x]+=sz[y];
	}
	ed[x]=totw;
}

void go(int &prex,int &x,int y,bool flag=0){
	vis[x]=1;
	if(x==y)return;
	for(int i=0;i<g[x].size();++i){
		int t=g[x][i];
		if(fa[x]==t)continue;
		if(st[t]<=st[y]&&st[y]<=ed[t]){
			if(flag&&x==1)prex=t;
			x=t;
			go(prex,x,y,flag);
			return;
		}
	}
}

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n+1;++i){
			g[i].clear();
			fa[i]=0;
			vis[i]=0;
			ans[i]=0;
		}
		totw=0;
		for(int i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			++x;++y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1);
		int x=1,prex=1,y=1;
		for(int i=0;i<g[1].size();++i){
			int y=g[1][i];
			ans[1]+=1ll*sz[y]*(sz[y]-1)/2;
		}
		vis[1]=1;
		ans[2]=1ll*n*(n-1)/2-ans[1];
		for(int i=2;i<=n;++i){
			if(vis[i]){
				ans[i+1]=ans[i];
				continue;
			}
			if(st[y]<=st[i]&&st[i]<=ed[y]){
				go(prex,y,i,1);
			}
			else{
				if(x!=1){
					if(st[x]<=st[i]&&st[i]<=ed[x]){
						go(prex,x,i);
					}
					else break;
				}
				else{
					if(!(st[prex]<=st[i]&&st[i]<=ed[prex])){
						go(prex,x,i);
					}
					else break;
				}
			}
			if(x!=1)ans[i+1]=1ll*sz[y]*sz[x];
			else ans[i+1]=1ll*sz[y]*(n-sz[prex]);
		}
		for(int i=2;i<=n;++i)ans[i]-=ans[i+1];
		for(int i=1;i<=n+1;++i)printf("%lld ",ans[i]);
		printf("\n");
	}
}