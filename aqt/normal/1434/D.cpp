
// Problem : D. Roads and Ramen
// Contest : Codeforces - Codeforces Round #679 (Div. 1, based on Technocup 2021 Elimination Round 1)
// URL : https://codeforces.com/contest/1434/problem/D
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> graph[500005];
bool typ[500005];
int dist[500005];

void dfs(int n, int p){
	for(auto e : graph[n]){
		if(e.first != p){
			dist[e.first] = dist[n] + 1;
			dfs(e.first, n);
		}
	}
}

struct EulerTourSegTree{
	struct Node{
		int l, r, lzy;
		int mx[2];
	};
	
	vector<Node> seg;
	vector<int> lft;
	vector<int> rht;
	vector<int> et;
	vector<int> dep;
	int t, rt;
	
	void dfs(int n, int p){
		//cout << n << endl;
		lft[p] = ++t;
		et[t] = n;
		for(auto e : graph[n]){
			if(e.second == p){
				continue;
			}
			dep[e.first] = dep[n] + 1;
			dfs(e.first, e.second);
		}
		rht[p] = t;
	}
	
	void build(int l, int r, int idx){
		//cout << l << " " << r << endl;
		seg[idx].l = l;
		seg[idx].r = r;
		if(l == r){
			seg[idx].mx[0] = dep[et[l]];
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, 2*idx);
		build(mid+1, r, 2*idx+1);
		seg[idx].mx[0] = max(seg[2*idx].mx[0], seg[2*idx+1].mx[0]);
		//cout << seg[idx].mx[0] << "\n";
	}
	
	void upd(int l, int r, int idx){
		//cout << "upd: " << seg[idx].mx[0] << " " << seg[idx].mx[1] << "\n";
		if(seg[idx].l == l && seg[idx].r == r){
			seg[idx].lzy ^= 1;
			swap(seg[idx].mx[0], seg[idx].mx[1]);
			return;
		}
		if(seg[idx].lzy){
			for(int i = 2*idx; i<=2*idx+1; i++){
				seg[i].lzy ^= 1;
				swap(seg[i].mx[0], seg[i].mx[1]);
			}
			seg[idx].lzy = 0;
		}
		int mid = seg[idx].l + seg[idx].r >> 1;
		if(r <= mid){
			upd(l, r, 2*idx);
		}
		else if(l > mid){
			upd(l, r, 2*idx+1);
		}
		else{
			upd(l, mid, 2*idx);
			upd(mid+1, r, 2*idx+1);
		}
		//cout << seg[idx].mx[0] << " " << seg[idx].mx[1] << "\n";
		seg[idx].mx[0] = max(seg[2*idx].mx[0], seg[2*idx+1].mx[0]);
		seg[idx].mx[1] = max(seg[2*idx].mx[1], seg[2*idx+1].mx[1]);
	}
	
	void updhelper(int ed){
		//cout << lft[ed] << " " << rht[ed] << "\n";
		upd(lft[ed], rht[ed], 1);
	}
	
	EulerTourSegTree(int R){
		rt = R;
		seg.resize(4*N + 5);
		lft.resize(N + 5);
		rht.resize(N + 5);
		dep.resize(N + 5);
		et.resize(N + 5);
		t = 0;
		dfs(R, 0);
		build(1, N, 1);
	}
	
	EulerTourSegTree(){
		
	}
	
};

EulerTourSegTree etseg[2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b, t;
		cin >> a >> b >> t;
		typ[i] = t;
		graph[a].emplace_back(b, i);
		graph[b].emplace_back(a, i);
	}
	dfs(1, 0);
	int d1 = max_element(dist, dist+1+N) - dist;
	etseg[0] = EulerTourSegTree(d1);
	int d2 = max_element(etseg[0].dep.begin(), etseg[0].dep.end()) - etseg[0].dep.begin();
	etseg[1] = EulerTourSegTree(d2);
	for(int i= 1; i<N; i++){
		if(typ[i]){
			etseg[0].updhelper(i);
			etseg[1].updhelper(i);
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int ed;
		cin >> ed;
		etseg[0].updhelper(ed);
		etseg[1].updhelper(ed);
		//cout << etseg[0].seg[1].mx[0] << " " << etseg[1].seg[1].mx[0] << "\n";
		//cout << etseg[0].seg[1].mx[0] << " " << etseg[0].seg[1].mx[1] << "\n";
		cout << max(etseg[0].seg[1].mx[0], etseg[1].seg[1].mx[0]) << "\n";
	}
}