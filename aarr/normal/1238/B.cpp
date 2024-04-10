#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int32_t main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, r;
		cin >> n >> r;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		sort(a, a + n);
		int ans = 0, j = n - 1;
		while (j >= 0) {
			int x = a[j];
			while (a[j] >= 0 && a[j] == x)
				j--;
			ans++;
			if (j < 0 || a[j] - r * ans <= 0)
				break;
		}
		cout << ans << endl;
	}
	return 0;
}