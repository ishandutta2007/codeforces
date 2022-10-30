#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N][4];
int csum[N];
int g[N][2];
bool vis[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		map<pair<int,int>,vector<int> > edge;
		memset(vis,0,sizeof(vis));
		memset(csum,0,sizeof(csum));
		memset(g,0,sizeof(g));
		for(int i=0;i<n-2;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
			}
			a[i][3]=a[i][0];
			for(int j=0;j<3;j++){
				pair<int,int> tmp(a[i][j],a[i][j+1]);
				if(tmp.first>tmp.second) swap(tmp.first,tmp.second);
				edge[tmp].push_back(i);
			}
		}
		for(auto x:edge){
			if(x.second.size()==1){
				int u=x.first.first,v=x.first.second;
				if(!g[u][0]) g[u][0]=v;
				else g[u][1]=v;
				if(!g[v][0]) g[v][0]=u;
				else g[v][1]=u;
			}
		}
		for(int u=1;!vis[u];u=vis[g[u][0]]?g[u][1]:g[u][0]){
			printf("%d ",u);
			vis[u]=true;
		}
		puts("");
		memset(vis,0,sizeof(vis));
		queue<int> side;
		for(int i=0;i<n-2;i++){
			for(int j=0;j<3;j++){
				pair<int,int> tmp(a[i][j],a[i][j+1]);
				if(tmp.first>tmp.second) swap(tmp.first,tmp.second);
				csum[i]+=edge[tmp].size();
			}
			if(csum[i]<=4) side.push(i),vis[i]=true;
		}
		while(!side.empty()){
			int i=side.front();
			side.pop();
			printf("%d ",i+1);
			for(int j=0;j<3;j++){
				pair<int,int> tmp(a[i][j],a[i][j+1]);
				if(tmp.first>tmp.second) swap(tmp.first,tmp.second);
				for(auto x:edge[tmp]){
					csum[x]--;
					if(csum[x]<=4&&!vis[x]){
						vis[x]=true;
						side.push(x);
					}
				}
			}
		}
		puts("");
	}
	return 0;
}