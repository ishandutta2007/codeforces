#include <iostream>
using namespace std;

int a[1005];
int main() {
	int n, d, ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j < i; j++) {
			if (abs(a[i] - a[j]) <= d) {
				ans++;
			}
		}
	}
	cout << ans * 2;
	return 0;
}