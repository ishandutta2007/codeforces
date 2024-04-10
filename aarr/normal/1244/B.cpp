#include <iostream>
using namespace std;

const int N = 1005;

int a[N];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int ans = n;
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
//			cin >> a[j];
			if (c == '1') {
				ans = max(ans, 2 * j);
				ans = max(ans, 2 * (n - j + 1));
//				cout << "73 " << j << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}