#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cassert>
#define N 50010
using namespace std;
int x[N],c[N],t[N],f[N*4],check[N];
bool vis[N*4];
bool onstk[N*4];
int low[N*4],od[N*4],stk[N*4],sz,now;
int top[N*4],tsz,ans;
int val[N*4];
bool in[N];
vector<int> g[N],h[N*4];
int gnum[N*4],gsz;
bool cmp(int i,int j){
	return c[i]<c[j];
}
bool cmpt(int i,int j){
	return t[i]>t[j];
}
void DFS(int u){
	stk[sz++]=u;
	onstk[u]=true;
	od[u]=now;
	low[u]=now;
	now++;
	vis[u]=true;
	for(int i=0;i<h[u].size();i++){
		int v=h[u][i];
		if(!vis[v]){
			DFS(v);
			if(low[v]<low[u]) low[u]=low[v];
		}
		else if(onstk[v]&&od[v]<low[u]) low[u]=od[v];
	}
	if(low[u]==od[u]){
		do{
			top[tsz++]=stk[sz-1];
			gnum[stk[sz-1]]=gsz;
			onstk[stk[sz-1]]=false;
		}while(stk[--sz]!=u);
		gsz++;
	}
}
bool get_subtree(int u,vector<int>& vec){
	if(val[u^1]){
		return false;
	}
	val[u]=true;
	vec.push_back(u);
	for(int i=0;i<h[u].size();i++){
		int v=h[u][i];
		if(!val[v]&&!get_subtree(v,vec)) return false;
	}
	return true;
}
int main(){
	int n,m,u,v,cnt;
	vector<int> ans;
	int mt=0;
	bool wrong=false;
	scanf("%d%d",&n,&m);
	cnt=m;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&u,&v,&c[i],&t[i]);
		x[i]=u^v;
		g[u].push_back(i);
		g[v].push_back(i);
		check[i]=i;
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end(),cmp);
		bool one=false;
		for(int j=1;j<g[i].size();j++){
			if(c[g[i][j]]==c[g[i][j-1]]){
				if(one){
					wrong=true;
					break;
				}
				else{
					in[g[i][j]]=in[g[i][j-1]]=true;
					h[g[i][j]<<1].push_back(g[i][j-1]<<1|1);
					h[g[i][j]<<1|1].push_back(g[i][j-1]<<1);
					h[g[i][j-1]<<1].push_back(g[i][j]<<1|1);
					h[g[i][j-1]<<1|1].push_back(g[i][j]<<1);
					one=true;
				}
			}
		}
	}
	if(!wrong){
		for(int i=1;i<=n;i++){
			bool flag=false;
			int pre;
			for(int j=0;j<g[i].size();j++){
				if(in[g[i][j]]){
					if(!flag) pre=g[i][j],flag=true;
					else{
						h[pre<<1|1].push_back(g[i][j]<<1);
						h[g[i][j]<<1|1].push_back(pre<<1);
						h[pre<<1|1].push_back(cnt<<1|1);
						h[g[i][j]<<1|1].push_back(cnt<<1|1);
						h[cnt<<1].push_back(pre<<1);
						h[cnt<<1].push_back(g[i][j]<<1);
						pre=cnt++;
					}
				}
			}
		}
		for(int i=0;i<cnt*2;i++){
			if(!vis[i]){
				DFS(i);
			}
		}
		for(int i=0;i<cnt;i++){
			if(gnum[i<<1]==gnum[i<<1|1]){
				wrong=true;
				break;
			}
		}
		if(!wrong){
			for(int i=0;i<m;i++){
				if(!in[i]){
					val[i<<1]=true;
				}
			}
			sort(check,check+m,cmpt);
			for(int i=0;i<m;i++){
				vector<int> v;
				int u=check[i];
				if(val[u<<1]) continue;
				else if(val[u<<1|1]) break;
				else if(!get_subtree(u<<1,v)){
					for(int i=0;i<v.size();i++) val[v[i]]=false;
					break;
				}
			}
			for(int i=0;i<tsz;i++){
				int u=top[i];
				if(!val[u]&&!val[u^1]){
					val[u]=true;
				}
			}
			for(int i=0;i<m;i++){
				if(val[i<<1|1]){
					ans.push_back(i+1);
					if(t[i]>mt) mt=t[i];
				}
			}
		}
	}
	if(wrong) puts("No");
	else{
		puts("Yes");
		printf("%d %u\n",mt,ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}