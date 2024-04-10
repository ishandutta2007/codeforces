#include <iostream>
using namespace std;


const int N = 105;

int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool x, y;
			cin >> x >> y;
			ans += x | y;
		}
	}
	cout << ans << endl;
	return 0;
}