#include <bits/stdc++.h>
using namespace std;
const int INF=1e4;
void get_min(int &x,int y){
	if(x>y) x=y;
}
int n,K,id,mx;
int fa[110],dep[110],vis[110];
int tp=0;
int q[220];
vector<int> r[110];
void find(int x){
	q[++tp]=x;
	if(!vis[x]){
		--K;
		for(int i=0;i<r[x].size();++i){
			if(K>mx){
				find(r[x][i]);
				q[++tp]=x;
			}
		}
		return;
	}
	if(dep[x]==K) return;
	for(int i=0;i<r[x].size();++i){
		if(K>mx&&vis[r[x][i]]==0){
			find(r[x][i]);
			q[++tp]=x;
		}
	}
	for(int i=0;i<r[x].size();++i){
		if(vis[r[x][i]]==1){
			find(r[x][i]);
		}
	}
	return;
}
void MAIN(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i) r[i].clear();
	dep[1]=1;vis[1]=0;
	for(int i=2;i<=n;++i){
		scanf("%d",&fa[i]);
		r[fa[i]].push_back(i);
		dep[i]=dep[fa[i]]+1;
		vis[i]=0;
	}
	id=0;mx=0;
	for(int i=1;i<=n;++i){
		if(dep[i]>mx){
			mx=dep[i];
			id=i;
		}
	}
	while(id!=1){
		vis[id]=1;
		id=fa[id];
	}
	vis[id]=1;
	tp=0;
	find(1);
	printf("%d\n",tp-1);
	printf("%d",q[1]);
	for(int i=2;i<=tp;++i) printf(" %d",q[i]);
	puts("");
	return;
}
int main(){
	int T=1;scanf("%d",&T);
	while(T--) MAIN();
    return 0;
}