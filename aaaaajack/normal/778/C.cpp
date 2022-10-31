#include<bits/stdc++.h>
#define N 300100
using namespace std;
int sz[N];
int to[N][26];
vector<int> g[N],gc[N];
vector<int> h[N];
void DFS(int u, int p, int d){
	sz[u]=1;
	h[d].push_back(u);
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==p){
			g[u].erase(g[u].begin()+i);
			gc[u].erase(gc[u].begin()+i);
			break;
		}
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		to[u][gc[u][i]]=v;
		DFS(v,u,d+1);
		sz[u]+=sz[v];
	}
}
int grow(int u,int v,vector<int>& er,vector<int>& ei){
	int res=1;
	//printf("%d %d\n",u,v);
	for(int i=0;i<g[v].size();i++){
		int w=g[v][i],c=gc[v][i];
		if(to[u][c]){
			res+=grow(to[u][c],w,er,ei);
		}
		else{
			er.push_back(u);
			ei.push_back(c);
			to[u][c]=w;
		}
	}
	return res;
}
void rev(const vector<int>& er, const vector<int>& ei){
	for(int i=0;i<er.size();i++){
		to[er[i]][ei[i]]=0;
	}
}
int main(){
	int n,x,y,ans=0,ai=1,tmp;
	char c;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d %c",&x,&y,&c);
		g[x].push_back(y);
		g[y].push_back(x);
		gc[x].push_back(c-'a');
		gc[y].push_back(c-'a');
	}
	DFS(1,0,0);
	for(int i=n-2;i>=0;i--){
		tmp=0;
		//if(tmp) printf("%d %d\n",i+1,tmp);
		for(int j=0;j<h[i].size();j++){
			int u=h[i][j];
			if(!g[u].empty()) tmp++;
			int mx=-1;
			for(int k=0;k<g[u].size();k++){
				if(mx<0 || sz[g[u][k]]>sz[mx]) mx=g[u][k];
			}
			vector<int> eu,ei;
			for(int k=0;k<g[u].size();k++){
				if(g[u][k]!=mx) tmp+=grow(mx,g[u][k],eu,ei);
			}
			rev(eu,ei);
		}
		if(tmp>=ans){
			ans=tmp;
			ai=i;
		}
	}
	printf("%d\n%d\n",n-ans,ai+1);
	return 0;
}