#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5;
int a[N];
int b[N];
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		for (int j = 0; j <= n; j++) {
			b[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			b[a[j]]++;
		}
		sort(b + 1, b + n + 1);
		int x = N, ans = 0;
		for (int j = n; j > 0; j--) {
			if(b[j] < x) {
				x = b[j];
				ans += x;
			}
			else {
				if (x > 1) {
					x--;
					ans += x;
				}
			}
			//cout << x << endl;
		}
		cout << ans << endl;
	}
	return 0;
}