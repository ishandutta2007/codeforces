
// Problem : C. Array and Operations
// Contest : Codeforces - Codeforces Round #284 (Div. 1)
// URL : https://codeforces.com/problemset/problem/498/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> pr;
int arr[105];
vector<int> graph[105];
int u[20005], v[20005], f[20005];
int lvl[20005];
int ptr[20005];

bool bfs(){
	fill(lvl, lvl+2+N, 0);
	lvl[0] = 1;
	queue<int> qu;
	qu.push(0);
	while(qu.size()){
		int n = qu.front();
		//cout << "bfs: " << n << " " << lvl[n] << endl;
		qu.pop();
		for(int e : graph[n]){
			//cout << f[e] << endl;
			if(f[e] && !lvl[v[e]]){
				lvl[v[e]] = lvl[u[e]] + 1;
				qu.push(v[e]);
			}
		}
	}
	return lvl[N+1];
}

int dfs(int n, int p){
	//cout << n << endl;
	if(!p || n == N+1){
		return p;
	}
	for(int &i = ptr[n]; i<graph[n].size(); i++){
		int e = graph[n][i];
		if(f[e] && lvl[v[e]] > lvl[u[e]]){
			//cout << n << " " << u[e] << " " << v[e] << " " << e << endl;
			int k = dfs(v[e], min(p, f[e]));
			if(!k){
				continue;
			}
			f[e] -= k;
			f[e^1] += k;
			return k;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i= 1; i<=N; i++){
		cin >> arr[i];
		int n = arr[i];
		for(int j = 2; j<=sqrt(n); j++){
			if(n%j == 0){
				pr.push_back(j);
				while(n%j == 0){
					n /= j;
				}
			}
		}
		if(n-1){
			pr.push_back(n);
		}
	}
	for(int i = 1; i<=N; i++){
		if(i%2 == 1){
			u[K] = 0;
			v[K] = i;
			u[K^1] = i;
			v[K^1] = 0;
		}
		else{
			u[K] = i;
			v[K] = N+1;
			u[K^1] = N+1;
			v[K^1] = i;
		}
		//cout << K << " " << (K^1) << " " << u[K] << " " << u[K^1] << endl;
		graph[u[K]].push_back(K);
		graph[u[K^1]].push_back(K^1);
		K += 2;
	}
	sort(pr.begin(), pr.end());
	pr.erase(unique(pr.begin(), pr.end()), pr.end());
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		if(a%2 == 0){
			swap(b, a);
		}
		u[K] = a;
		v[K] = b;
		u[K^1] = b;
		v[K^1] = a;
		graph[u[K]].push_back(K);
		graph[u[K^1]].push_back(K^1);
		//cout << "e: " << u[K^1] << endl;
		//cout << "ee : " << u[K] << endl;
		//cout << a << " " << b << endl;
		K+=2;
	}
	long long ans = 0;
	for(int p : pr){
		//cout << "prime: " << p << "\n";
		for(int i= 1; i<=N; i++){
			int k = 2*i-2;
			f[k] = 0;
			f[k^1] = 0;
			while(arr[i]%p == 0){
				f[k]++;
				arr[i] /= p;
			}
		}
		for(int k = 2*N; k<K; k+=2){
			f[k] = INT_MAX/2;
			f[k^1] = 0;
		}
		while(1){
			if(!bfs()){
				break;
			}
			//cout << lvl[N+1] << endl;
			fill(ptr, ptr+2+N, 0);
			int k;
			while((k = dfs(0, INT_MAX/2))){
				//cout << k << endl;
				ans += k;
			}
		}
	}
	cout << ans;
}