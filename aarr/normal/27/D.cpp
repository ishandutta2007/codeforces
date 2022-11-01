#include <iostream>
#include <vector>
using namespace std;

const int N = 107;
bool b = true;

vector <int> adj[N];
int s[N], e[N];
int part[N];

void dfs(int v) {
	for (auto u : adj[v]) {
		if (part[u] == part[v]) {
			b = false;
			return;
		}
		if (!part[u]) {
			part[u] = 3 - part[v];
			dfs(u);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s[i] >> e[i];
		if (s[i] > e[i]) {
			swap(s[i], e[i]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (i != j && ((s[i] < s[j] && s[j] < e[i] && e[i] < e[j]) || (s[j] < s[i] && s[i] < e[j] && e[j] < e[i]))) {
				adj[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!part[i]) {
			part[i] = 1;
			dfs(i);
		}
	}
/*	for (int i = 1; i <= m; i++) {
		for (auto u : adj[i]) {
			if (part[i] == part[u]) {
				b = false;
			}
		}
	}*/
	if (b) {
		for (int i = 1; i <= m; i++) {
			if (part[i] == 1) {
				cout << 'i';
			}
			else {
				cout << 'o';
			}
		}
	}
	else {
		cout << "Impossible";
	}
	return 0;
}