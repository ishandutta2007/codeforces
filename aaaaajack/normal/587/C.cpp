#include<cstdio>
#include<vector>
#define N 100100
using namespace std;
int p[N][20],dep[N];
vector<int> mn[N][20];
vector<int> g[N];
vector<int> merge(vector<int>& l,vector<int>& r){
	vector<int> res;
	for(int i=0,j=0;res.size()<10&&(i<l.size()||j<r.size());){
		if(j==r.size()) res.push_back(l[i++]);
		else if(i==l.size()) res.push_back(r[j++]);
		else if(l[i]<r[j]) res.push_back(l[i++]);
		else if(r[j]<l[i]) res.push_back(r[j++]);
		else res.push_back(l[i++]),j++;
	}
	return res;
}
void build(int n){
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			p[j][i]=p[p[j][i-1]][i-1];
			if(dep[j]>=(1<<i)) mn[j][i]=merge(mn[p[j][i-1]][i-1],mn[j][i-1]);
		}
	}
}
void DFS(int u,int v,int d){
	p[u][0]=v;
	dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==v) continue;
		DFS(g[u][i],u,d+1);
	}
}
vector<int> qry(int u,int v){
	vector<int> res;
	if(dep[u]>dep[v]){
		int l=dep[u]-dep[v];
		for(int i=0;i<20;i++){
			if(l&(1<<i)){
				res=merge(res,mn[u][i]);
				u=p[u][i];
			}
		}
	}
	else if(dep[v]>dep[u]){
		int l=dep[v]-dep[u];
		for(int i=0;i<20;i++){
			if(l&(1<<i)){
				res=merge(res,mn[v][i]);
				v=p[v][i];
			}
		}
	}
	for(int i=19;i>=0;i--){
		if(p[u][i]!=p[v][i]){
			res=merge(res,mn[u][i]);
			res=merge(res,mn[v][i]);
			u=p[u][i];
			v=p[v][i];
		}
	}
	if(u!=v){
		res=merge(res,mn[u][0]);
		res=merge(res,mn[v][0]);
		u=p[u][0];
	}
	res=merge(res,mn[u][0]);
	return res;
}
int main(){
	int n,m,q,x,y,a;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,1,0);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		if(mn[x][0].size()<10) mn[x][0].push_back(i);
	}
	build(n);
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&x,&y,&a);
		vector<int> ans=qry(x,y);
		if(a<ans.size()){
			printf("%d",a);
			for(int i=0;i<a;i++) printf(" %d",ans[i]);
			puts("");
		}
		else{
			printf("%d",(int)ans.size());
			for(int i=0;i<ans.size();i++) printf(" %d",ans[i]);
			puts("");
		}
	}
	return 0;
}