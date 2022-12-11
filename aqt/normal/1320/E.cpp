
// Problem : E. Treeland and Viruses
// Contest : Codeforces - Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : https://codeforces.com/contest/1320/problem/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct state{
	int n, d, w;
	state(int _n, int _d, int _w){
		n = _n;
		d = _d;
		w = _w;
	}
	bool operator < (const state s) const{
		if(d == s.d){
			return w > s.w;
		}
		return d > s.d;
	}
};

int N, Q;
vector<int> graph[200005];
vector<int> virt[200005];
int par[20][200005];
int lft[200005];
int rht[200005];
int dep[200005];
pair<int, int> dist[200005];
int sp[200005];
int t;

bool cmp(int u, int v){
	return lft[u] < lft[v];
}

void dfs(int n){
	lft[n] = ++t;
	for(int e : graph[n]){
		if(e != par[0][n]){
			par[0][e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
	rht[n] = t;
}

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	if(lft[v] <= lft[u] && rht[v] >= rht[u]){
		return v;
	}
	for(int d = 19; d>=0; d--){
		if(!par[d][u] || (lft[par[d][u]] <= lft[v] && rht[par[d][u]] >= rht[v])){
			
		}
		else{
			u = par[d][u];
		}
	}
	return par[0][u];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	dep[1] = 1;
	dfs(1);
	for(int d = 1; d<20; d++){
		for(int n = 1; n<=N; n++){
			par[d][n] = par[d-1][par[d-1][n]];
		}
	}
	cin >> Q;
	while(Q--){
		int K, M;
		cin >> K >> M;
		vector<int> src;
		vector<int> imp;
		vector<int> v;
		priority_queue<state> pq;
		for(int i = 1; i<=K; i++){
			int n;
			cin >> n;
			src.push_back(n);
			v.push_back(n);
			cin >> sp[i];
			pq.push(state(n, 0, i));
		}
		for(int i = 1; i<=M; i++){
			int n;
			cin >> n;
			imp.push_back(n);
			v.push_back(n);
		}
		sort(v.begin(), v.end(), cmp);
		//cout << "snap" << endl;
		for(int i = 1; i<M+K; i++){
			//cout << v[i-1] << " " << v[i] << " "<< lca(v[i-1], v[i]) << "\n";
			v.push_back(lca(v[i-1], v[i]));
		}
		sort(v.begin(), v.end(), cmp);
		v.erase(unique(v.begin(), v.end()), v.end());
		vector<int> stk;
		for(int n : v){
			//cout << "nd: " << n << "\n";
			dist[n] = make_pair(INT_MAX/2, 0);
			while(stk.size() && (!(lft[stk.back()] <= lft[n]) || !(rht[stk.back()] >= rht[n]))){
				stk.pop_back();
			}
			if(stk.size()){
				int p = stk.back();				
				//cout << n << " " << p << "\n";
				virt[p].emplace_back(n);
				virt[n].emplace_back(p);
			}
			stk.push_back(n);
		}
		//cout << "crackle" << endl;
		while(pq.size()){
			auto s = pq.top();
			pq.pop();
			if(make_pair(s.d, s.w) > dist[s.n]){
				continue;
			}
			//cout << s.n << " " << s.w << "\n";
			dist[s.n] = make_pair(s.d, s.w);
			for(auto e : virt[s.n]){
				int p = lca(e, src[s.w-1]);
				assert(sp[s.w]);
				int d = (dep[src[s.w-1]] + dep[e] - 2*dep[p] + sp[s.w] - 1)/sp[s.w];
				//cout << "adj: " << e << "\n";
				if(dist[e] > make_pair(d, s.w)){
					dist[e] = make_pair(d, s.w);
					pq.push(state(e, d, s.w));
				}
			}
		}
		//cout << "pop" << endl;
		for(int n : imp){
			cout << dist[n].second << " ";
		}
		cout << "\n";
		for(int n : v){
			virt[n].clear();
		}
	}
}