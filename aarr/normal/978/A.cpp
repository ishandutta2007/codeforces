#include <iostream>
using namespace std;

int b[1005];
int a[55];
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (b[a[i]] == 0) {
			ans++;
		}
		b[a[i]] = i;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		if (b[a[i]] == i) {
			cout << a[i] << " ";
		}
	}
	return 0;
}