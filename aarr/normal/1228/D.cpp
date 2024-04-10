#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;

vector <int> l[3];
vector <int> adj[N];
int part[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].push_back(n + 1);
	}
	int v = 0;
	part[1] = 1;
	int k = 0;
	for (int j = 2; j <= n; j++) {
		if (adj[1][k] == j) {
			v = j;
			k++;
		}
		else {
			part[j] = 1;
		}
	}
	long long x = 0, y = 0, z = 0;
	if (v != 0) {
		part[v] = 2;
		k = 0;
	//	cout << v << endl;
		for (int j = 1; j <= n; j++) {
	//		cout << "49 " << j << " " << adj[v][k] << endl;
			if (part[j] != 0 && adj[v][k] == j) {
				k++;
				continue;
			}
			if (adj[v][k] == j && part[j] == 0) {
	//			cout << 73 << " " << j << endl;
				part[j] = 3;
				k++;
			}
			if (part[j] != 0)
				continue;		
			if (part[j] == 0) {
				part[j] = 2;
			}
		}
		//	for (int i = 1; i <= n; i++) {
		//		cout << part[i] << " ";
		//	}	
		for (int i = 1; i <= n; i++) {
			if (part[i] == 1)
				x++;
			if (part[i] == 2)
				y++;
			if (part[i] == 3)
				z++;
			for (auto v : adj[i]) {
				if (part[i] == part[v]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	else {
		cout << -1 << endl;
		return 0;
	}
	if (x * y + y * z + x * z == m && x > 0 && y > 0 && z > 0) {
		for (int i = 1; i <= n; i++) {
			cout << part[i] << " ";
		}
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}