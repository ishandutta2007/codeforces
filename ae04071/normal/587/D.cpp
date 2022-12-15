#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#ifndef AECODE
#define eprint if(false) printf
#else
#define eprint printf
#endif
using namespace std;

const int MAXN = 50000, INF = 1e9;

struct Edge{
	int u,v,c,t,i;
	bool operator<(const Edge& rhs)const {
		return c < rhs.c;
	}
}arr[MAXN];
int n,m,vis[MAXN*6+1];
vector<int> adj[MAXN*6+1],radj[MAXN*6+1],tadj[MAXN+1],ans;

inline int NOT(int cur){ return cur<m*3 ? cur+m*3 : cur-m*3; }
void addCla(int u,int v) {
	adj[NOT(u)].push_back(v); adj[NOT(v)].push_back(u);
	radj[v].push_back(NOT(u)); radj[u].push_back(NOT(v));
}

stack<int> stk;
void dfs(int cur) {
	vis[cur] = 1;
	for(auto &it:adj[cur]) if(!vis[it]) dfs(it);
	stk.push(cur);
}
void rdfs(int cur,int val) {
	vis[cur] = val;
	for(auto &it:radj[cur]) if(!vis[it]) rdfs(it,val);
}

bool check(int val,bool rec = false) {
	for(int i=0;i<m*6;i++) adj[i].clear(),radj[i].clear(),vis[i] = 0;
	
	int pc=m;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<sz(tadj[i]);j++) {
			addCla(NOT(tadj[i][j]), pc);
			if(j!=0) {
				addCla(NOT(pc-1), pc);
				addCla(NOT(pc-1), NOT(tadj[i][j]));
				if(arr[tadj[i][j-1]].c == arr[tadj[i][j]].c) addCla(tadj[i][j-1],tadj[i][j]);
			}

			if(arr[tadj[i][j]].t > val && arr[tadj[i][j]].u == i) addCla(NOT(tadj[i][j]), NOT(tadj[i][j]));
			pc++;
		}
	}

	while(!stk.empty()) stk.pop();
	for(int i=0;i<m*6;i++) if(!vis[i]) dfs(i);
	fill(vis,vis+m*6,0);

	int dfn=1;
	while(!stk.empty()) {
		int cur=stk.top(); stk.pop();
		if(!vis[cur]) rdfs(cur,dfn++);
	}
	for(int i=0;i<m*3;i++) if(vis[i] == vis[NOT(i)]) return false;
	
	if(rec) {
		ans.clear();
		for(int i=0;i<m;i++) if(vis[i] > vis[NOT(i)]) ans.push_back(arr[i].i);
	}
	return true;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d%d%d%d",&arr[i].u,&arr[i].v,&arr[i].c,&arr[i].t);
		arr[i].i = i+1;
	}
	sort(arr,arr+m);

	for(int i=0;i<m;i++) {
		tadj[arr[i].u].push_back(i);
		tadj[arr[i].v].push_back(i);
	}

	for(int i=1;i<=n;i++) {
		int f=1;
		for(int j=0,k=0;j<sz(tadj[i]);j=k) {
			for(k=j;k<sz(tadj[i]) && arr[tadj[i][j]].c == arr[tadj[i][k]].c;k++);
			if(k-j>2 || (k-j==2 && f==2)) { puts("No"); return 0; }
			if(k-j==2) f=2;
		}
	}

	int lo=-1,up=INF+1;
	while(up-lo>1) {
		int md=(lo+up)>>1;
		if(check(md)) up=md;
		else lo=md;
	}
	if(lo==INF) puts("No");
	else {
		puts("Yes");
		check(up,true);
		printf("%d %d\n",up,sz(ans));
		sort(ans.begin(),ans.end());
		for(auto &v:ans) printf("%d ",v);
	}

	return 0;
}