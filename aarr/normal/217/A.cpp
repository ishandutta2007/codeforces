#include <iostream>
#include <vector>
using namespace std;

int nparts = 1;
pair<int, int> cor[105];
vector<int> adj[105];
int mark[105];
void dfs(int v) {
	if(mark[v] != 0)
		return;
	mark[v] = nparts;
	for (int i = 0; i < adj[v].size(); i++) {
		dfs(adj[v][i]);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cor[i].first;
		cin >> cor[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if(cor[i].first == cor[j].first || cor[i].second == cor[j].second) {
					adj[i].push_back(j);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (mark[i] == 0) {
			dfs(i);
			nparts ++;
		}
	}
	cout << nparts - 2;
	return 0;
}