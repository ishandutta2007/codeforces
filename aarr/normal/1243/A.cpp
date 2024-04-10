#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];

int main() {
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, min(n - i, a[i]));
		}
		cout << ans << endl;
	}	
	return 0;
}