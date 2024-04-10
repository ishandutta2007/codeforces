#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s;
	int a, b;
	cin >> n >> s;
	int ans = s;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans = max(ans, a + b);
	}
	cout << ans << endl;
}