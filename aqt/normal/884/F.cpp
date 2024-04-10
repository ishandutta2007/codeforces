
// Problem : F. Anti-Palindromize
// Contest : Codeforces - Educational Codeforces Round 31
// URL : https://codeforces.com/problemset/problem/884/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
string s;
vector<int> graph[100005];
int u[100005], v[100005], wt[100005], f[100005];
int arr[100005];
int dist[100005];
int par[100005];
int fre[30];

void add(int _u, int _v, int _w, int _f){
	u[M] = _u;
	v[M] = _v;
	wt[M] = _w;
	f[M] = _f;
	graph[u[M]].push_back(M);
	M++;
	u[M] = _v;
	v[M] = _u;
	wt[M] = -_w;
	graph[u[M]].push_back(M);
	M++;
}

int spfa(){
	queue<int> qu;
	qu.push(0);
	fill(dist, dist+26+26*(N/2)+N+2, INT_MAX/2);
	dist[0] = 0;
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		for(int e : graph[n]){
			if(f[e] && dist[v[e]] > dist[n] + wt[e]){
				dist[v[e]] = dist[n] + wt[e];
				par[v[e]] = e;
				qu.push(v[e]);
			}
		}
	}
	if(dist[26+26*(N/2)+N+1] != INT_MAX/2){
		return dist[26+26*(N/2)+N+1];
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	for(char c : s){
		fre[c-'a'+1]++;
	}
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int k = 1; k<=26; k++){
		add(0, k, 0, fre[k]);
		for(int n = 1; n<=N/2; n++){
			add(k, 26+n+(N/2)*(k-1), 0, 1);
			add(26+n+(N/2)*(k-1), 26+26*(N/2)+n, (s[n-1]-'a' != k-1)*arr[n], 1);
			add(26+n+(N/2)*(k-1), 26+26*(N/2)+N-n+1, (s[N-n]-'a' != k-1)*arr[N-n+1], 1);
		}
	}
	for(int n = 1; n<=N; n++){
		add(26+26*(N/2)+n, 26+26*(N/2)+N+1, 0, 1);
	}
	int v;
	int ans = accumulate(arr+1, arr+1+N, 0);
	while((v = spfa()) != -1){
		ans -= v;
		int crnt = 26+26*(N/2)+N+1;
		while(crnt){
			f[par[crnt]]--;
			f[par[crnt]^1]++;
			crnt = u[par[crnt]];
		}
	}
	cout << ans;
}