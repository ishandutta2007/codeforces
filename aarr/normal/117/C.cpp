#include <iostream>
using namespace std;

const int N = 5005;

bool adj[N][N];
int outdeg[N];
int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '1') {
				adj[i][j] = true;
				outdeg[i]++;
			}
		}
	}
	bool b = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (outdeg[i] <= outdeg[j] && adj[i][j]) {
				for (int k = 1; k <= n; k++) {
					if (adj[j][k] && adj[k][i]) {
						cout << i << " " << j << " " << k << endl;
						return 0;
					}
				}
			//	cout << 73 << endl;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}