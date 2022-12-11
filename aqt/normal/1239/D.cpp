
// Problem : D. Catowice City
// Contest : Codeforces - Codeforces Round #594 (Div. 1)
// URL : https://codeforces.com/contest/1239/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N, M, C;
vector<int> graph[1000005];
vector<int> stk;
int dfn[1000005], low[1000005], t;
bool instk[1000005];
vector<vector<int>> cmp;
int who[1000005];
bool tkn[1000005];

void dfs(int n){
	//cout << n << endl;
	dfn[n] = low[n] = ++t;
	instk[n] = 1;
	stk.push_back(n);
	for(int e : graph[n]){
		if(!dfn[e]){
			dfs(e);
			low[n] = min(low[n], low[e]);
		}
		else if(instk[e]){
			low[n] = min(low[n], low[e]);
		}
	}
	if(low[n] == dfn[n]){
		int c;
		C++;
		vector<int> v;
		do{
			c = stk.back();
			stk.pop_back();
			who[c] = C;
			v.push_back(c);
			instk[c] = 0;			
		}
		while(c != n);
		cmp.push_back(v);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		cmp.clear();
		for(int i = 1; i<=N; i++){
			graph[i].clear();
			dfn[i] = low[i] = 0;
			tkn[i] = 0;
		}
		for(int i = 1; i<=M; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}
		C = t = 0;
		for(int i = 1; i<=N; i++){
			if(!dfn[i]){
				dfs(i);
			}
		}
		/*
		cout << C << "\n";
		for(auto v : cmp){
			for(int n : v){
				cout << n << " ";
			}
			cout << "\n";
		}
		*/
		if(C == 1){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
			for(auto v : cmp){
				//cout << cmp.size() << "\n";
				bool chk = 1;
				for(int n : v){
					for(int e : graph[n]){
						if(who[e] != who[n]){
							chk = 0;
						}
					}
				}
				if(chk){
					cout << v.size() << " " << N - v.size() << "\n";
					for(int n : v){
						cout << n << " ";
						tkn[n] = 1;
					}
					cout << "\n";
					for(int i = 1; i<=N; i++){
						if(!tkn[i]){
							cout << i << " ";
						}
					}
					cout << "\n";
					break;
				}
			}
		}
	}
}