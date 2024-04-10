
// Problem : E. Tree
// Contest : Codeforces - CodeCraft-19 and Codeforces Round #537 (Div. 2)
// URL : https://codeforces.com/contest/1111/problem/E
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int K, M, R;
vector<int> graph[100005];
vector<int> cgraph[100005];
int par[20][100005];
int st[100005], ed[100005], t = 0;
int dep[100005];
const long long MOD = 1e9+7;
bool sp[100005];
long long dp[2][305];

vector<int> v;
vector<int> nd;
vector<int> lst;
set<pair<int, int>> sts;

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	for(int d = 16; d>=0; d--){
		if(dep[par[d][u]] >= dep[v]){
			u = par[d][u];
		}
	}
	if(u == v){
		return u;
	}
	for(int d = 16; d>=0; d--){
		if(par[d][u] != par[d][v]){
			u = par[d][u];
			v = par[d][v];
		}
	}
	return par[0][u];
}

void dfs1(int n){
	st[n] = ++t;
	for(int e : graph[n]){
		if(e != par[0][n]){
			par[0][e] = n;
			dep[e] = dep[n] + 1;
			dfs1(e);
		}
	}
	ed[n] = ++t;
}

void dfs2(int n, int p, int c){
	//cout << "  " << n << "\n";
	if(sp[n]){
		//cout << " " << n << "\n";
		t++;
		dp[t&1][0] = 0;
		for(int k = 1; k<=M; k++){
			dp[t&1][k] = (dp[t&1^1][k] * max(0, (k - c)) + dp[t&1^1][k-1]) % MOD;
		}
		c++;
	}
	for(int e : cgraph[n]){
		if(e != p){
			//cout << n << " " << e << "\n";
			dfs2(e, n, c);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dep[1] = 1;
	dfs1(1);
	for(int d = 1; d<=16; d++){
		for(int n = 1; n<=N; n++){
			par[d][n] = par[d-1][par[d-1][n]];
		}
	}
	while(Q--){
		cin >> K >> M >> R;
		nd = {R};
		lst = {R};
		for(int k = 1; k<=K; k++){
			int n;
			cin >> n;
			v.emplace_back(n);
			nd.emplace_back(n);
			lst.emplace_back(n);
			sp[n] = 1;
		}
		sort(nd.begin(), nd.end(), [](int a, int b) {return st[a] < st[b];});
		for(int k = 1; k<=K; k++){
			//cout << "lca: " << nd[k] << " " << nd[k-1] << " " << lca(nd[k], nd[k-1]) << "\n";
			lst.emplace_back(lca(nd[k], nd[k-1]));
		}
		sort(lst.begin(), lst.end(), [](int a, int b) {return make_pair(dep[a],a) > make_pair(dep[b],b);});
		lst.erase(unique(lst.begin(), lst.end()), lst.end());
		for(int k : lst){
			//cout << "bing: " << k << "\n";
			for(auto ptr = sts.lower_bound({st[k], 0}); ptr != sts.end(); ptr = sts.erase(ptr)){
				if(st[ptr->second] > ed[k]){
					break;
				}
				//cout << "initial: " << k << " " << ptr->second << "\n";
				cgraph[k].push_back(ptr->second);
				cgraph[ptr->second].push_back(k);
			}
			sts.insert({st[k], k});
		}
		t = 0;
		fill(dp[0], dp[0]+1+M, 0);
		dp[0][0] = 1;
		dfs2(R, 0, 0);
		long long ans = 0;
		for(int k = 1; k<=M; k++){
			ans += dp[t&1][k];
			ans %= MOD;
		}
		cout << ans << "\n";
		for(int n : lst){
			//cout << n << "\n";
			sp[n] = 0;
			cgraph[n].clear();
		}
		sts.clear();
		v.clear();
		nd.clear();
		lst.clear();
	}
}