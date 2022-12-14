/**
 *    author:  Atreus
 *    created: 31.01.2019 16:05
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
vector <int> g[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	set<int> s;
	s.insert(1);
	for (int _ = 0; _ < n; _++){
		int v = *s.begin();
		s.erase(s.begin());
		cout << v << " ";
		mark[v] = 1;
		for (auto u : g[v]){
			if (!mark[u]){
				s.insert(u);
			}
		}
	}
	cout << endl;
}