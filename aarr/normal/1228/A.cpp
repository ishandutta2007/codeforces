#include <iostream>
using namespace std;

int mark[12];
bool chck(int n) {
	for (int i = 0; i < 10; i++) 
		mark[i] = 0;
	while (n > 0) {
		mark[n % 10]++;
		n /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (mark[i] > 1)
			return false;
	}
	return true;
}
int main() {
	int l, r;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (chck(i)) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}