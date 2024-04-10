
// Problem : F. AB Tree
// Contest : Codeforces - Codeforces Round #699 (Div. 2)
// URL : https://codeforces.com/contest/1481/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<int> graph[200005];
int dep[200005];
int fre[200005];
vector<int> fresz[200005];
vector<int> sz;
bool dp[200005];
bool tmp[200005];
pair<int, int> par[200005];
bool a[200005];
int ord[200005];
char ans[200005];

void dfs(int n){
	for(int e : graph[n]){
		dep[e] = dep[n] + 1;
		dfs(e);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> X;
	for(int i = 2; i<=N; i++){
		int p;
		cin >> p;
		graph[p].push_back(i);
	}
	dfs(1);
	for(int i = 1; i<=N; i++){
		fre[dep[i]]++;
	}
	for(int i = 0; i<=N; i++){
		fresz[fre[i]].push_back(i);
	}
	for(int i = 1; i<=N; i++){
		if(fresz[i].size()){
			sz.push_back(i);
		}
	}
	dp[0] = 1;
	for(int k = 1; k<=sz.size(); k++){
		int s = sz[k-1];
		for(int r = 0; r<s; r++){
			int ptr = r;
			for(int n = r; n<=N; n+=s){
				while(ptr < n && ((n - ptr)/s > fresz[s].size() || !dp[ptr])){
					ptr += s;
				}
				if(!dp[n] && dp[ptr] && ptr != n){
					tmp[n] = 1;
					par[n] = make_pair(s, (n-ptr)/s);
				}
			}
		}
		for(int n = 1; n<=N; n++){
			dp[n] = tmp[n];
		}
	}
	int hgt = *max_element(dep, dep+1+N);
	if(dp[X]){
		cout << hgt+1<< "\n";
		int crnt = X;
		while(crnt){
			//cout << crnt << endl;
			//cout << " " << crnt << "\n";
			for(int i = 0; i<par[crnt].second; i++){
				//cout << par[crnt].second << endl;
				a[fresz[par[crnt].first][i]] = 1;
				//cout << fresz[par[crnt].first][i] << "\n";
			}
			crnt -= par[crnt].second * par[crnt].first;
		}
		for(int i = 1; i<=N; i++){
			if(a[dep[i]]){
				ans[i] = 'a';
			}
			else{
				ans[i] = 'b';
			}
		}
	}
	else{
		cout << hgt+2 << "\n";
		queue<int> qu;
		int idx = 0;
		qu.push(1);
		while(qu.size()){
			int n = qu.front();
			qu.pop();
			ord[++idx] = n;
			for(int e : graph[n]){
				qu.push(e);
			}
		}
		int Y = N-X;
		int sp = 0;
		for(int i = 0; i<=hgt; i++){
			if(X > fre[i]){
				X -= fre[i];
				a[i] = 1;
			}
			else if(Y > fre[i]){
				Y -= fre[i];
			}
			else{
				sp = i;
			}
		}
		for(int i = 1; i<=N; i++){
			if(a[dep[i]]){
				ans[i] = 'a';
			}
			else if(dep[i] != sp){
				ans[i] = 'b';
			}
		}
		vector<int> leaf;
		for(int i = 1; i<=N; i++){
			if(dep[i] == sp && graph[i].empty()){
				leaf.push_back(i);
			}
		}
		for(int i = 1; i<=N; i++){
			if(dep[i] == sp && graph[i].size()){
				leaf.push_back(i);
			}
		}
		if(Y < X){
			for(int n : leaf){
				if(Y){
					ans[n] = 'b';
					Y--;
				}
				else{
					ans[n] = 'a';
				}
			}
		}
		else{
			for(int n : leaf){
				if(X){
					ans[n] = 'a';
					X--;
				}
				else{
					ans[n] = 'b';
				}
			}
		}
	}
	for(int i = 1; i<=N; i++){
		cout << ans[i];
	}
}