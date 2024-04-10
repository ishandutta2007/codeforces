#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
#define maxlog 16
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,id[maxn],dep[maxn],min_t[maxlog + 1][maxn],max_t[maxlog + 1][maxn];
int lis[maxn << 1],len,row[maxn << 1],t[maxlog + 2][maxn << 1];
int q;
vector <int> chi[maxn];
void dfs(int u,int f){
	dep[u] = f == -1 ? 0 : dep[f] + 1;
	lis[++len] = u;
	id[u] = len;
	for(int i=0;i<(int)chi[u].size();i++){
		dfs(chi[u][i],u);
		lis[++len] = u;
	}
}
int min_dep(int u,int v){//whose depth is smaller?
	return dep[u] < dep[v] ? u : v;
}
int min_id(int u,int v){
	return id[u] < id[v] ? u : v;
}
int max_id(int u,int v){
	return id[u] > id[v] ? u : v;
}
void rmq_ini(){
	for(int i=1;i<=len;i++) t[0][i] = lis[i];
	int st = 2;
	for(int i=1;i<=len - 1;i++){
		if(i == st){
			row[i] = row[i - 1] + 1;
			st <<= 1;
		}else{
			row[i] = row[i - 1];
		}
	}
	for(int i=1;i<=17;i++){
		for(int j=1;j<=len - (1 << i) + 1;j++){
			t[i][j] = min_dep(t[i - 1][j],t[i - 1][j + (1 << (i - 1))]);
		}
	}
	for(int i=1;i<=n;i++){
		min_t[0][i] = i;
		max_t[0][i] = i;
	}
	for(int i=1;i<=maxlog;i++){
		for(int j=1;j + (1 << i) - 1 <= n;j++){
			min_t[i][j] = min_id(min_t[i - 1][j],min_t[i - 1][j + (1 << (i - 1))]);
			max_t[i][j] = max_id(max_t[i - 1][j],max_t[i - 1][j + (1 << (i - 1))]);
		}
	}
}
int lca_dep(int u,int v){//return depth of the lca.
	int l = id[u],r = id[v];
	if(l > r) swap(l,r);
	if(l == r) return dep[lis[l]];
	int ro = row[r - l];
	return dep[min_dep(t[ro][l],t[ro][r - (1 << ro) + 1])];
}
int query_min_id(int l,int r){//return the node with min_id.
	if(l == r) return l;
	int ro = row[r - l];
	return min_id(min_t[ro][l],min_t[ro][r - (1 << ro) + 1]);
}
int query_max_id(int l,int r){
	if(l == r) return l;
	int ro = row[r - l];
	return max_id(max_t[ro][l],max_t[ro][r - (1 << ro) + 1]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++){
		int p;
		scanf("%d",&p);
		chi[p].push_back(i + 1);
	}
	dfs(1,-1);
	rmq_ini();
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int u = query_min_id(l,r),v = query_max_id(l,r);
		int u1,v1;
		if(u == l) u1 = query_min_id(u + 1,r);
		else if(u == r) u1 = query_min_id(l,u - 1);
		else u1 = min_id(query_min_id(l,u - 1),query_min_id(u + 1,r));
		if(v == l) v1 = query_max_id(v + 1,r);
		else if(v == r) v1 = query_max_id(l,v - 1);
		else v1 = max_id(query_max_id(l,v - 1),query_max_id(v + 1,r));
		
		int d1 = lca_dep(u1,v),d2 = lca_dep(u,v1);
		if(d1 > d2){
			printf("%d %d\n",u,d1);
		}else{
			printf("%d %d\n",v,d2);
		}
	}
	return 0;
}