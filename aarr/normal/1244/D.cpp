#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;

int c[5][N];
vector <int> adj[N];
int a[N];
int b[N];
bool mark[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int v = 0;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() > 2) {
			cout << -1 << endl;
			return 0;
		}
		if (adj[i].size() == 1) {
			v = i;
		}
	}
//	cout << v << endl;
	for (int i = 1; i <= n; i++) {
		a[i] = v;
		mark[v] = true;
		for (auto u : adj[v]) {
			if (!mark[u]) {
				v = u;
				break;
			}
		}
	}
//	cout << v << endl;
	long long ans = 0, ansfor = 1;
	for (int i = 1; i <= n; i++) {
		int v = a[i];
		ans += c[i % 3][v];
//		cout << "45 " << i << " " << v << " " << c[i % 3][v] << endl;
		b[v] = i % 3;
		if (i % 3 == 0) {
			b[v] = 3;
		}
	}
	long long finans = ans;
//	cout << "28 " << finans << endl;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		int v = a[i];
		if (i % 3 == 0) {
			ans += c[1][v];
		}
		if (i % 3 == 1) {
			ans += c[2][v];
		}
		if (i % 3 == 2) {
			ans += c[0][v];
		}
	}
//	cout << "73 " << finans << endl;
	if (ans <= finans) {
		for (int i = 1; i <= n; i++) {
			int v = a[i];
			if (i % 3 == 0) {
				b[v] = 1;
			}
			if (i % 3 == 1) {
				b[v] = 2;
			}
			if (i % 3 == 2) {
				b[v] = 3;
			}
		}
		finans = ans;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		int v = a[i];
		if (i % 3 == 0) {
			ans += c[2][v];
		}
		if (i % 3 == 1) {
			ans += c[0][v];
		}
		if (i % 3 == 2) {
			ans += c[1][v];
		}
	}
	if (ans <= finans) {
		for (int i = 1; i <= n; i++) {
			int v = a[i];
			if (i % 3 == 0) {
				b[v] = 2;
			}
			if (i % 3 == 1) {
				b[v] = 3;
			}
			if (i % 3 == 2) {
				b[v] = 1;
			}
		}
		finans = ans;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		int v = a[i];
		if (i % 3 == 0) {
			ans += c[1][v];
		}
		if (i % 3 == 1) {
			ans += c[0][v];
		}
		if (i % 3 == 2) {
			ans += c[2][v];
		}
	}
	if (ans <= finans) {
		for (int i = 1; i <= n; i++) {
			int v = a[i];
			if (i % 3 == 0) {
				b[v] = 1;
			}
			if (i % 3 == 1) {
				b[v] = 3;
			}
			if (i % 3 == 2) {
				b[v] = 2;
			}
		}
		finans = ans;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		int v = a[i];
		if (i % 3 == 0) {
			ans += c[2][v];
		}
		if (i % 3 == 1) {
			ans += c[1][v];
		}
		if (i % 3 == 2) {
			ans += c[0][v];
		}
	}
	if (ans <= finans) {
		for (int i = 1; i <= n; i++) {
			int v = a[i];
			if (i % 3 == 0) {
				b[v] = 2;
			}
			if (i % 3 == 1) {
				b[v] = 1;
			}
			if (i % 3 == 2) {
				b[v] = 3;
			}
		}
		finans = ans;
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		int v = a[i];
		if (i % 3 == 0) {
			ans += c[0][v];
		}
		if (i % 3 == 1) {
			ans += c[2][v];
		}
		if (i % 3 == 2) {
			ans += c[1][v];
		}
	}
	if (ans <= finans) {
		for (int i = 1; i <= n; i++) {
			int v = a[i];
			if (i % 3 == 0) {
				b[v] = 3;
			}
			if (i % 3 == 1) {
				b[v] = 2;
			}
			if (i % 3 == 2) {
				b[v] = 1;
			}
		}
		finans = ans;
	}
	cout << finans << endl;
	for (int i = 1; i <= n; i++) {
		if (b[i] < 3) {
			b[i]++;
		}
		else {
			b[i] = 1;
		}
		cout << b[i] << " ";
	}
	return 0;
}