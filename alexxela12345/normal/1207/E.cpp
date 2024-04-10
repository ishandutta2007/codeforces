#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "?" << " ";
	for (int i = 1; i <= 100; i++) {
		cout << i << " ";
	}
	cout << endl;
	cout << "?" << " ";
	for (int i = 1; i <= 100; i++) {
		cout << (i << 7) << " ";
	}
	cout << endl;
	int a, b;
	cin >> a >> b;
	int ans = a & (((1 << 7) - 1) << 7);
	ans |= b & ((1 << 7) - 1);
	cout << "! ";
	cout << ans << endl;
}