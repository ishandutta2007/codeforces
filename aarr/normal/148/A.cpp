#include <iostream>
using namespace std;

int a[5];
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		bool b = false;
		for (int j = 0; j < 4; j++) {
		//	cout << "73 " << i << " " << a[j] << endl;
			if (i % a[j] == 0) {
				b = true;
			}
		}
		if (b) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}