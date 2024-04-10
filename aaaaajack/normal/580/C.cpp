#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N],ans;
vector<int> g[N];
void DFS(int u,int p,int k,int m){
	int cc=0;
	if(a[u]) k++;
	else k=0;
	if(k>m) return;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		DFS(v,u,k,m);
		cc++;
	}
	if(cc==0){
		ans++;
	}
}
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0,0,m);
	printf("%d\n",ans);
	return 0;
}