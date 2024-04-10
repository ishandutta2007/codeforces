#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(1e6) + 200, mod = int(1e9)  + 7;
int n;
int q,p[N];
vi g[N];
int tin[N],tout[N],T;
int up[N][22];
bool used[N];
int dep[N];
int D = 1;
int CURDEP = 1,V = 2;

void dfs(int v){
	used[v] = 1;
	tin[v] = ++T;
	for(int i=0;i<g[v].size();i++){
		int to = g[v][i];
		up[to][0] = v;
		dep[to] = dep[v] + 1;
		dfs(to);
	}
	tout[v] = ++T;
}

bool ok(int u,int v){
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

void precalc(){
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			if(up[i][j-1] != -1){
				up[i][j] = up[up[i][j-1]][j-1];
			}
		}
	}
}

int LCA(int u,int v){
	if(ok(u,v)) return u;
	if(ok(v,u)) return v;
	for(int i=20;i>=0;i--){
		if(up[v][i] != -1 && !ok(up[v][i],u)) v = up[v][i];
	}
	return up[v][0];
}

int get(int u,int v){
	if(ok(u,v)) return dep[v] - dep[u];
	if(ok(v,u)) return dep[u] - dep[v];
	int x = LCA(u,v);
	return dep[u] - dep[x] + dep[v] - dep[x];
}

void add(int v,int u){
	if(CURDEP == dep[v]){
		D++;
	}
	else{
		D = max(get(V,u),D);		
	}
	if(CURDEP < dep[u]){
		V = u;
		CURDEP = dep[u];
	}
}

int main () {
	int q,v;
	memset(up,-1,sizeof(up));
	scanf("%d",&q);
	n = 1;
	for(int i=1;i<q;i++){
		scanf("%d",&p[i]);
		g[p[i]].pb(++n);
	}
	dfs(1);
	precalc();
	for(int i=1;i<q;i++){
		add(p[i],i + 1);
		printf("%d ",D);
	}
return 0;
}