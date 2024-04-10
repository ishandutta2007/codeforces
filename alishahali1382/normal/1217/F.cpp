#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
typedef pair<int, int> pii;

#define pb push_back

const int MAXN = 200010;

int par[MAXN], R[MAXN];
stack<pair<int*, int>> stk;

int get(int x){
	while (par[x]!=x) x=par[x];
	return x;
}

int join(pii p){
	int x=get(p.first);
	int y=get(p.second);
	if (x==y) return 0;
	if (R[x]>R[y]) swap(x, y);
	stk.push({&par[x], par[x]});
	stk.push({&R[y], R[y]});
	par[x]=y;
	R[y]+=(R[x]==R[y]);
	return 2;
}
	
void undo(){
	auto it=stk.top();
	stk.pop();
	*it.first=it.second;
}

int n, m, k, u, v, x, y, a, b, last;
int T[MAXN], X[MAXN], Y[MAXN];
map<pii, vector<int>> mp;
vector<pii> seg[MAXN<<2];
map<pii, bool> edge;

int f(int x){
	if (x==n) return 1;
	return x+1;
}

pii ff(int x, int y){
	if (x>y) swap(x, y);
	return {x, y};
}

void Add(int id, int tl, int tr, int l, int r, pii p){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(p);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, p);
	Add(id<<1 | 1, mid, tr, l, r, p);
}

void handle(int i){
	if (last) X[i]=f(X[i]), Y[i]=f(Y[i]);
	edge[ff(X[i], Y[i])]^=1;
}

void dfs(int id, int tl, int tr){
	if ((id&1) && T[tl]==1) handle(tl);
	int cnt=0;
	for (pii p:seg[id]) if (edge[p]) cnt+=join(p);
	if (tr-tl==1){
		if (T[tl]==2){
			int i=tl;
			if (last) X[i]=f(X[i]), Y[i]=f(Y[i]);
			cout<<(last=(get(X[i])==get(Y[i])));		
		}
	}
	else{
		int mid=(tl+tr)>>1;
		dfs(id<<1, tl, mid);
		dfs(id<<1 | 1, mid, tr);
	}
	while (cnt--) undo();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) par[i]=i;
	for (int i=1; i<=m; i++){
		cin>>T[i]>>X[i]>>Y[i];
		mp[ff(X[i], Y[i])].pb(i);
		mp[ff(f(X[i]), f(Y[i]))].pb(i);
	}
	for (auto it:mp){
		it.second.pb(m+1);
		for (int i=0; i<it.second.size()-1; i++) Add(1, 1, m+1, it.second[i], it.second[i+1], it.first);
	}
	dfs(1, 1, m+1);
	
	return 0;
}