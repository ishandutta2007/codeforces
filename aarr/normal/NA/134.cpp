#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, t, n;
		cin >> n >> s >> t;
		int x = s + t - n;
		int ans = min(n, n);
		ans = min(ans, max(t - x, s - x) + 1);
		cout << ans << endl;
	}
	return 0;
}