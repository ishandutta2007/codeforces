#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
 
const int N = 1000;
 
vector<int> adj[N], cmpnt[N];
int a[N], poz[N], h[N], comp, n;
bool mark[N], m_ark[N][N];
 
void dfs(int v) {
	poz[v] = comp;
	cmpnt[comp].push_back(a[v]);
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i];
		if (!mark[u])
			dfs(u);
	}
}
 
int main() {
	//---
		int i, j, x, y;
	//---
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
 
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (j = 0; j < n; j++) {
	//		cout << s[j] << ' ';
			if (s[j] == '1') {
	//			cout << 'd' << endl;
				adj[i].push_back(j);
				adj[j].push_back(i);
	//			cout << i << j << '\n';
				m_ark[i][j] = true;
			}
		}
	//	cout << '\n';
	}
 
	for (i = 0; i < n; i++) { 
		if (!mark[i]) {
			dfs(i);
			comp++;
			sort(cmpnt[comp - 1].begin(), cmpnt[comp - 1].end());
		}
	}
 
	for (i = 0; i < n; i++) {
		x = poz[i];
		y = cmpnt[x][h[x]];
	//	cout << i << ' ' << x << ' ' << h[x] << ' ' << y << endl; 
		cout << y << ' ';
		h[x]++;
	}
 	cout << '\n';
	return 0;
}