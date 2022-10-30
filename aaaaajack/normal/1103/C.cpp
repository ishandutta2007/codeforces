#include<bits/stdc++.h>
#define N 250010
using namespace std;
vector<int> g[N];
bool vis[N],isleaf[N];
int dep[N],par[N];
void DFS(int u,int p){
	par[u]=p;
	dep[u]=dep[p]+1;
	vis[u]=true;
	isleaf[u]=true;
	for(auto v:g[u]){
		if(!vis[v]){
			isleaf[u]=false;
			DFS(v,u);
		}
	}
}
int main(){
	int n,m,k,x,y;
	scanf("%d%d%d",&n,&m,&k);
	while(m--){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0);
	int mx=0;
	bool path=false;
	for(int i=1;i<=n;i++){
		if(dep[i]>=(n+k-1)/k){
			path=true;
			mx=i;
			break;
		}
	}
	if(path){
		puts("PATH");
		printf("%d\n",dep[mx]);
		while(mx){
			printf("%d ",mx);
			mx=par[mx];
		}
		puts("");
	}
	else{
		puts("CYCLES");
		for(int i=1;i<=n&&k>0;i++){
			if(isleaf[i]){
				k--;
				int a=-1,b=-1;
				for(auto v:g[i]){
					if(v!=par[i]){
						if(a<0) a=v;
						else b=v;
					}
				}
				if((dep[i]-dep[a]+1)%3==0){
					swap(a,b);
				}
				if((dep[i]-dep[a]+1)%3!=0){
					printf("%d\n",dep[i]-dep[a]+1);
					for(int v=i;v!=par[a];v=par[v]){
						printf("%d ",v);
					}
					puts("");
				}
				else{
					if(dep[a]>dep[b]) swap(a,b);
					printf("%d\n",dep[b]-dep[a]+2);
					printf("%d ",i);
					for(int v=b;v!=par[a];v=par[v]){
						printf("%d ",v);
					}
					puts("");
				}
			}
		}
	}
	return 0;
}