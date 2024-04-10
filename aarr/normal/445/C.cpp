#include <iostream>
#include <iomanip>
using namespace std;


const int N = 505;

int a[N];
int main() {
	long double ans = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		ans = max(ans, (long double) (a[u] + a[v]) / c);
	}
	cout << fixed << setprecision(10);
	cout << ans;
	return 0;
}