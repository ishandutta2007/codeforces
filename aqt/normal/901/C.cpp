
// Problem : C. Bipartite Segments
// Contest : Codeforces - Codeforces Round #453 (Div. 1)
// URL : https://codeforces.com/contest/901/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r, mx, mn;
};

int N, M, Q;
Node seg[1500000];
bool vis[300005];
int dep[300005];
int lim[300005];
long long pre1[300005];
long long pre2[300005];
vector<int> graph[300005];

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(seg[idx].l == seg[idx].r){
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int p, int v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mn = seg[idx].mx = v;
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(p <= mid){
		upd(p, v, 2*idx);
	}
	else{
		upd(p, v, 2*idx+1);
	}
	seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
}

pair<int, int> query(int l, int r, int idx){
	//cout << l << " " << r << " " << idx << endl;
	if(seg[idx].l == l && seg[idx].r == r){
		return make_pair(seg[idx].mx, seg[idx].mn);
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		auto p = query(l, mid, 2*idx);
		auto q = query(mid+1, r, 2*idx+1);
		p.first = max(p.first, q.first);
		p.second = min(p.second, q.second);
		return p;
	}
}

void dfs(int n, int p){
	//cout << n << endl;
	vis[n] = 1;
	upd(dep[n], n, 1);
	for(int e : graph[n]){
		if(e != p){
			if(vis[e] && dep[e] < dep[n]){
				auto p = query(dep[e], dep[n], 1);
				//cout << n << " " << e << " " << p.first << " " << p.second << "\n";
				lim[p.first] = max(lim[p.first], p.second);
			}
			else if(!vis[e]){
				dep[e] = dep[n] + 1;
				dfs(e, n);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	build(1, N, 1);
	//cout << "here" << endl;
	for(int i =1 ; i<=N; i++){
		if(!vis[i]){
			dep[i] = 1;
			dfs(i, 0);
		}
	}
	//cout << "here" << endl;
	for(int i = 1; i<=N; i++){
		lim[i] = max(lim[i], lim[i-1]);
		pre1[i] = i + pre1[i-1];
		pre2[i] = pre2[i-1] + i - lim[i];
		//cout << i << " " << lim[i] << endl; 
	}
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		int idx = lower_bound(lim+1, lim+1+N, l) - lim - 1;
		if(idx > r){
			cout << pre1[r] - pre1[l-1] - 1LL * (l - 1) * (r - l + 1) << "\n";
		}
		else if(idx < l){
			cout << pre2[r] - pre2[l-1] << "\n";
		}
		else{
			//cout << "hi\n";
			//cout << pre1[idx] - pre1[l-1] - 1LL * (l - 1) * (idx - l + 1) << "\n";
			cout << pre2[r] - pre2[idx] + pre1[idx] - pre1[l-1] - 1LL * (l - 1) * (idx - l + 1) << "\n";
		}
	}
	
}