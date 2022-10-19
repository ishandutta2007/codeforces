#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cur = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cur = cur - a + b;
		ans = max(cur, ans);
	}
	cout << ans << endl;
}