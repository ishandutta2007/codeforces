#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;
int deg[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u;
		cin >> v;
		deg[u]++;
		deg[v]++;
	}
	bool b = true;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 2)
			b = false;
	}
	if (b)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}