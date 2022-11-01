#include <iostream>
#include <vector>
using namespace std;


const int N = 200 * 1000 + 5;
int nparts = 0;

string s[N];
bool b[N][30];
vector <int> adj[N];
int part[N];
void dfs(int v) {
	for (auto u : adj[v]) {
		if (part[u] == 0) {
			part[u] = part[v];
			dfs(u);
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			b[i][s[i][j] - 'a'] = true;
		}
	}
	for (int j = 0; j < 26; j++) {
		int x = -1;
		for (int i = 1; i <= n; i++) {
			if (b[i][j]) {
				if (x != -1) {
					adj[x].push_back(i);
					adj[i].push_back(x);
				}
				x = i;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (part[i] == 0) {
			nparts++;
			part[i] = nparts;
			dfs(i);
		}
	}
	cout << nparts << endl;
	return 0;
}