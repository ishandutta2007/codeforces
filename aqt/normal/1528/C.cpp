
// Problem : C. Trees of Tranquillity
// Contest : Codeforces - Codeforces Round #722 (Div. 1)
// URL : https://codeforces.com/contest/1528/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	int val;
};

int T, N;
vector<int> graph[300005];
vector<int> hgraph[300005];
int lft[300005], rht[300005], t;
set<pair<int, int>> st;
int ans = 0;
/*

Node seg[300005 * 8];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	seg[idx].val = 0;
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}
*/

void dfs1(int n){
	lft[n] = ++t;
	for(int e : hgraph[n]){
		dfs1(e);
	}
	rht[n] = ++t;
}

void dfs2(int n){
	bool added = 0;
	pair<int, int> rem = {0, 0};
	auto ptr = st.lower_bound(make_pair(lft[n], n));
	if(ptr != st.begin()){
		ptr--;
		int k = ptr->second;
		//cout << n << " " << k << "\n";
		if(lft[k] <= lft[n] && rht[k] >= rht[n]){
			rem = make_pair(lft[k], k);
			added = 1;
			st.erase(rem);
			st.insert(make_pair(lft[n], n));
		}
	}
	if(!added){ 
		ptr = st.lower_bound(make_pair(lft[n], n));
		if(ptr != st.end()){
			int k = ptr->second;
			//cout << "yo " << n << " " << k << "\n";
			if(lft[n] <= lft[k] && rht[n] >= rht[k]){
				
			}
			else{
				added = 1;
				st.insert(make_pair(lft[n], n));
			}
		}
		else{
			added = 1;
			st.insert(make_pair(lft[n], n));
		}
	}
	if(st.empty()){
		st.insert(make_pair(lft[n], n));
		added = 1;
	}
	ans = max(ans, (int) st.size());
	for(int e : graph[n]){
		dfs2(e);
	}
	if(added){
		st.erase(make_pair(lft[n], n));
		if(rem.first){
			st.insert(rem);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int n = 1; n <= N; n++){
			graph[n].clear();
			hgraph[n].clear();
		}
		for(int i = 2; i <= N; i++){
			int p;
			cin >> p;
			graph[p].push_back(i);
		}
		for(int i = 2; i <= N; i++){
			int p;
			cin >> p;
			hgraph[p].push_back(i);
		}
		t = 0;
		//build(1, 2 * N, 1);
		ans = 0;
		dfs1(1);
		dfs2(1);
		cout << ans << "\n";
	}
}