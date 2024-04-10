#include <iostream>
using namespace std;

int get(int x, int y) {
	return (x >> y) & 1;
}
int a[4];
int main() {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	int s = a[0] + a[1] + a[2] + a[3];
	for (int i = 0; i < (1 << 4); i++) {
		int ans = 0;
		for (int j = 0; j < 4; j++) {
			if (get(i, j))
				ans += a[j];
		}
		if (ans * 2 == s) {
		//	cout << i << endl;
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}