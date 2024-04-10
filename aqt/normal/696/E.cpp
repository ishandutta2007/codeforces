
// Problem : E. ...Wait for it...
// Contest : Codeforces Round #362 (Div. 1)
// URL : https://codeforces.com/contest/696/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long lzy;
	pair<long long, pair<int, int>> mn;
};

int N, M, Q;
node seg[400005];
vector<int> graph[100005];
vector<int> girls[100005];
int par[100005];
int id[100005];
int dep[100005];
int hvy[100005];
int lft[100005];
int rhtn[100005];
int rht[100005];
int sz[100005];
int top[100005];
int home[100005];
int idinv[100005];
int cntr = 0;
priority_queue<pair<pair<long long, pair<int, int>>, int>, 
vector<pair<pair<long long, pair<int, int>>, int>>, 
greater<pair<pair<long long, pair<int, int>>, int>>> pq;

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[2*idx].mn.first += seg[idx].lzy;
		seg[2*idx+1].mn.first += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(l == r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void ins(int p, pair<long long, pair<int, int>> v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mn = v;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	ins(p, v, 2*idx+(p > mid));
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
}

void upd(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].lzy += v;
		seg[idx].mn.first += v;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l, r, v, 2*idx);
	}
	else if(l > mid){
		upd(l, r, v, 2*idx+1);
	}
	else{
		upd(l, mid, v, 2*idx);
		upd(mid+1, r, v, 2*idx+1);
	}
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
}

pair<long long, pair<int, int>> query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mn;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

void dfs(int n){
	sz[n]++;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
			hvy[n] = (sz[e] > sz[hvy[n]] ? e : hvy[n]);
			sz[n] += sz[e];
		}
	}
}

void hld(int n, int t){
	lft[n] = cntr;
	top[n] = t;
	for(int k : girls[n]){
		id[k] = ++cntr;
		idinv[cntr] = k;
	}
	rhtn[n] = cntr;
	if(hvy[n]){
		hld(hvy[n], t);
	}
	for(int e : graph[n]){
		if(e != par[n] && e != hvy[n]){
			hld(e, e);
		}
	}
	rht[n] = cntr;
}

void pathquery(int u, int v, int k){
	cntr = 0;
	vector<pair<int, int>> chains;
	while(top[u] != top[v]){
		if(dep[top[v]] > dep[top[u]]){
			swap(u, v);
		}
		if(lft[top[u]] < rhtn[u]){
			auto p = query(lft[top[u]]+1, rhtn[u], 1);
			if(p.first < LLONG_MAX/2){
				chains.emplace_back(make_pair(lft[top[u]]+1, rhtn[u]));
				pq.push(make_pair(p, cntr++));
			}
		}
		u = par[top[u]];
	}
	if(dep[v] > dep[u]){
		swap(u, v);
	}
	if(lft[v] < rhtn[u]){
		auto p = query(lft[v]+1, rhtn[u], 1);
		if(p.first < LLONG_MAX/2){
			chains.emplace_back(make_pair(lft[v]+1, rhtn[u]));
			pq.push(make_pair(p, cntr++));
		}
	}
	vector<int> ans;
	while(k-- && pq.size()){
		auto p = pq.top();
		pq.pop();
		int n = p.first.second.second;
		ans.push_back(idinv[n]);
		ins(n, {LLONG_MAX/2, {0, 0}}, 1);
		auto q = query(chains[p.second].first, chains[p.second].second, 1);
		if(q.first < LLONG_MAX/2){
			pq.push({q, p.second});
		}
	}
	cout << ans.size() << " ";
	for(int n : ans){
		cout << n << " ";
	}
	cout << "\n";
	while(pq.size()){
		pq.pop();
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i<=M; i++){
		int n;
		cin >> n;
		girls[n].push_back(i);
		home[i] = n;
	}
	dfs(1);
	hld(1, 1);
	build(1, M, 1);
	for(int i = 1; i<=M; i++){
		ins(id[i], {i, {home[i], id[i]}}, 1);
	}
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			int u, v, k;
			cin >> u >> v >> k;
			pathquery(u, v, k);
		}
		else{
			int n, v;
			cin >> n >> v;
			if(lft[n] < rht[n]){
				upd(lft[n]+1, rht[n], v, 1);
			}
		}
	}
}