// Problem : E. NN country
// Contest : Codeforces Round #483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]
// URL : https://codeforces.com/problemset/problem/983/E
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

struct qu{
	int l, r, x, id; //-1 f, 0 upd, 1 s
	bool operator < (qu q) const{
		if(q.x == x){
			return id < q.id;
		}
		return x < q.x;
	}
};

int N, M, Q;
vector<int> graph[200005];
int par[20][200005], tbl[20][200005];
int lft[200005], rht[200005], et[400005], t;
int dep[200005];
pair<int, int> bus[200005];
int ans[200005], lst[200005];
int bit[400005];
vector<qu> v;

void upd(int n){
	while(n <= 2*N){
		bit[n]++;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

void dfs1(int n){
	et[++t] = n;
	lft[n] = t;
	for(int e : graph[n]){
		dep[e] = dep[n] + 1;
		dfs1(e);
	}
	et[++t] = n;
	rht[n] = t;
}

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	for(int d = 19; d>=0; d--){
		if(dep[par[d][u]] >= dep[v]){
			u = par[d][u];
		}
	}
	if(u == v){
		return u;
	}
	for(int d = 19 ;d>=0; d--){
		if(par[d][u] != par[d][v]){
			u = par[d][u];
			v = par[d][v];
		}
	}
	return par[0][u];
}

void dfs2(int n){
	for(int e : graph[n]){
		dfs2(e);
		if(dep[tbl[0][e]] < dep[tbl[0][n]]){
			tbl[0][n] = tbl[0][e];
		}
	}
}

pair<int, int> query(int n, int t){
	int ret = 0;
	for(int d = 19; d>=0; d--){
		//cout << n << " " << tbl[d][n] << endl;
		if(dep[tbl[d][n]] > dep[t]){
			n = tbl[d][n];
			ret += (1<<d);
		}
	}
	return {ret, n};
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 2; i<=N; i++){
		int p;
		cin >> p;
		graph[p].push_back(i);
		par[0][i] = p;
		tbl[0][i] = i;
	}
	tbl[0][1] = 1;
	dep[1] = 1;
	dfs1(1);
	for(int d = 1; d<20; d++){
		for(int n =1 ; n<=N; n++){
			par[d][n] = par[d-1][par[d-1][n]];
		}
	}
	cin >> M;
	for(int i = 1; i<=M; i++){
		cin >> bus[i].first >> bus[i].second;
		int l = lca(bus[i].first, bus[i].second);
		if(dep[tbl[0][bus[i].first]] > dep[l]){
			//cout << bus[i].first << endl;
			tbl[0][bus[i].first] = l;
		}
		if(dep[tbl[0][bus[i].second]] > dep[l]){
			//cout << bus[i].second << endl;
			tbl[0][bus[i].second] = l;
		}
		v.push_back({rht[bus[i].first], 0, lft[bus[i].second], 0});
		v.push_back({rht[bus[i].second], 0, lft[bus[i].first], 0});
	}
	dfs2(1);
	for(int d = 1; d<20; d++){
		for(int n = 1; n<=N; n++){
			tbl[d][n] = tbl[d-1][tbl[d-1][n]];
		}
	}
	cin >> Q;
	for(int q = 1; q<=Q; q++){
		int u, w;
		cin >> u >> w;
		int l = lca(u, w);
		if(u == l){
			ans[q] = query(w, l).first + 1;
		}
		else if(w == l){
			ans[q] = query(u, l).first + 1;
		}
		else{
			auto x = query(u, l), y = query(w, l);
			//cout << x.first << " " << y.first << " " << l << endl;
			//cout << x.second << " " << y.second << " " << endl;
			//cout << tbl[0][2] << endl;
			ans[q] = x.first + y.first;
			v.push_back({lft[x.second], rht[x.second], lft[y.second], -q});
			v.push_back({lft[x.second], rht[x.second], rht[y.second], q});
		}
	}
	sort(v.begin(), v.end());
	for(auto q : v){
		if(q.id < 0){
			lst[-q.id] = query(q.r) - query(q.l-1);
		}
		else if(q.id > 0){
			int t = query(q.r) - query(q.l-1);
			if(t > lst[q.id]){
				ans[q.id]++;
			}
			else{
				ans[q.id] += 2;
			}
		}
		else{
			upd(q.l);
		}
	}
	for(int q = 1; q<=Q; q++){
		if(ans[q] > M){
			ans[q] = -1;
		}
		cout << ans[q] << "\n";
	}
}