#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nparts = 1, n;
int a[305];
int adj[305][305];
vector <int> ela[305];
vector <int> el[305];
int mark[305];
int ans[305];
void dfs(int v) {
	if (mark[v] != 0)
		return;
	mark[v] = nparts;
	ela[nparts].push_back(a[v]);
	el[nparts].push_back(v);
	for (int i = 1; i <= n; i++) {
		if (adj[v][i] == 1) {
			dfs(i);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//cout << 68;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			adj[i][j] = c - '0';
		}
	}
	//cout << 49;
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			dfs(i);
			nparts++;
		}
	}
	//cout << 73;
	for (int i = 1; i < nparts; i++) {
		sort(ela[i].begin(), ela[i].end());
		sort(el[i].begin(), el[i].end());
		for (int j = 0; j < el[i].size(); j ++) {
			ans[el[i][j]] = ela[i][j];
			//cout << el[i][j] << " " << ela[i][j] << endl;
		}
	}
	//cout << nparts << endl;
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}