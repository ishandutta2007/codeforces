
// Problem : D. MEX Tree
// Contest : Codeforces - Codeforces Round #721 (Div. 2)
// URL : https://codeforces.com/contest/1527/problem/D
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
vector<int> graph[200005];
int lft[200005], rht[200005], sz[200005], par[200005], who[200005];
int t;
long long ans[200005];

void dfs(int n ,int p){
	sz[n] = 1;
	lft[n] = ++t;
	for(int e : graph[n]){
		if(e != p){
			par[e] = n;
			dfs(e, n);
			sz[n] += sz[e];
		}
	}
	rht[n] = ++t;
}

int clmb(int n, int k = -1){
	if(!n){
		return k;
	}
	else if(who[n] != -1){
		return who[n];
	}
	return who[n] = clmb(par[n], n);
}

bool anc(int a, int b){
	return lft[a] <= lft[b] && rht[a] >= rht[b];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		t = 0;
		for(int i = 0; i <= N; i++){
			graph[i].clear();
			ans[i] = 0;
			who[i] = -1;
		}
		ans[N + 1] = 0;
		for(int i = 1; i < N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].emplace_back(b);
			graph[b].emplace_back(a);
		}
		dfs(0, -1);
		ans[1] = 1LL * N * (N-1) / 2;
		for(int e : graph[0]){
			ans[1] -= 1LL* sz[e] * (sz[e] - 1) / 2;
		}
		pair<int, int> pr = {1, 0};
		long long a = sz[1], b = N - sz[clmb(1, 1)];
		bool good = 1;
		for(int k = 2; k <= N && good; k++){
			ans[k] = a * b;
			if(anc(pr.first, k)){
				pr.first = k;
				a = sz[k];
			}
			else if(anc(k, pr.first)){
				
			}
			else if(anc(pr.second, k)){
				pr.second = k;
				b = sz[k];
				if(clmb(pr.first) == clmb(pr.second)){
					good = 0;
				}
			}
			else if(anc(k, pr.second)){
				
			}
			else{
				good = 0;
			}
		}
		ans[0] = 1LL * N * (N - 1) / 2;
		for(int k = 0; k <= N; k++){
			ans[k] -= ans[k + 1];
		}
		for(int k = 0; k <= N; k++){
			cout << ans[k] << " ";
		}
		cout << "\n";
	}
}