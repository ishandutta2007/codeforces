
// Problem : D. Maximum Distributed Tree
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> graph[100005];
long long sz[100005];
const long long MOD = 1e9+7;

void dfs(int n, int p){
	sz[n] = 1;
	for(int e : graph[n]){
		if(e != p){
			dfs(e, n);
			sz[n] += sz[e];
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
		for(int i = 1; i<=N; i++){
			graph[i].clear();
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1, 0);
		for(int i = 1; i<=N; i++){
			sz[i] = sz[i] * (N-sz[i]);
		}
		sort(sz+1, sz+1+N);
		reverse(sz+1, sz+1+N);
		vector<long long> pr;
		int M;
		cin >> M;
		for(int i = 1; i<=M; i++){
			long long n;
			cin >> n;
			pr.push_back(n);
		}
		sort(pr.begin(), pr.end(), greater<long long>());
		if(M > N-1){
			long long k = 1;
			for(int i = 0; i<=M-N+1; i++){
				k *= pr[i];
				k %= MOD;
			}			
			pr.erase(pr.begin(), pr.begin()+M-N+2);
			pr.insert(pr.begin(), k);
		}
		else{
			while(pr.size() < N-1){
				pr.push_back(1);
			}
		}
		long long ans = 0;
		for(int i = 1; i<=pr.size(); i++){
			ans += (sz[i]%MOD * pr[i-1])%MOD;
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}