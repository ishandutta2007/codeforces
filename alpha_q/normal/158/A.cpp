#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, a[100];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int pos = 0;
	for (int i = 1; i <= k; i++) {
		if (a[i]) pos++;
		else {
			cout << pos << endl;
			return 0;
		}
	}
	while (pos < n and a[pos] == a[pos + 1]) pos++;
	cout << pos << endl;
	return 0;
}