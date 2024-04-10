
// Problem : F2. The Hidden Pair (Hard Version)
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/F2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1005];
int ord[1005], dep[1005], t;

pair<int, int> query(vector<int> v){
	cout << "? " << v.size() << " ";
	for(int n : v){
		cout << n << " ";
	}
	cout << endl;
	int a, b;
	cin >> a >> b;
	return make_pair(a, b);
}

void dfs(int n, int p = 0){
	for(int e : graph[n]){
		if(e != p){
			dep[e] = dep[n] + 1;
			dfs(e, n);
		}
	}
	ord[++t] = n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> qu;
		for(int i = 1; i<=N; i++){
			graph[i].clear();
			qu.push_back(i);
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		auto p = query(qu);
		int d = p.second;
		t = 0;
		dfs(p.first);
		int l = 1, r = N, u = p.first;
		while(l <= r){
			int mid = l+r>>1;
			qu.clear();
			for(int i = l; i<=mid; i++){
				qu.push_back(ord[i]);
			}
			auto q = query(qu);
			if(q.second == d){
				u = q.first;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		dep[u] = 0;
		t = 0;
		dfs(u);
		qu.clear();
		for(int i = 1; i<=N; i++){
			if(dep[i] == d){
				qu.push_back(i);
			}
		}
		auto k = query(qu);
		cout << "! " << u << " " << k.first << endl;
		string s;
		cin >> s;
		assert(s == "Correct");
	}	
}