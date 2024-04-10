#include <iostream>
using namespace std;

int a[30];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a[c - 'A']++;
	}
	int ans = n;
	for (int i = 0; i < k; i++) {
		ans = min(ans, a[i]);
	}
	cout << ans * k << endl;
	return 0;
}