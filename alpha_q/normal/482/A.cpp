#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n - k; i++) cout << i << " ";
	int i = n, j = n - k + 1;
	for (int t = 1; t <= k; t++) {
		if (t & 1) cout << i-- << " ";
		else cout << j++ << " ";
	}
	cout << endl;
	return 0;
}