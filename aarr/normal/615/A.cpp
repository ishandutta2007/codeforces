#include <iostream>
using namespace std;

bool mark[105];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			int y;
			cin >> y;
			mark[y] = true;
		}
	} 
	for (int i = 1; i <= m; i++) {
		if (!mark[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}