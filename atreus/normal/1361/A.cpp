#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;

vector<int> g[maxn], vec[maxn];
int t[maxn];
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; i++){
		cin >> t[i];
		vec[t[i]].push_back(i);
	}
	vector<int> answer;
	for (int i = 1; i <= n; i++){
		for (auto v : vec[i]){
			for (auto u : g[v])
				mark[t[u]] = true;
			for (int j = 1; j < i; j++)
				if (mark[j] == false)
					return cout << -1 << endl, 0;
			if (mark[i] == true)
				return cout << -1 << endl, 0;
			for (auto u : g[v])
				mark[t[u]] = false;
			answer.push_back(v);
		}
	}
	for (auto it : answer)
		cout << it << " ";
	cout << endl;
}