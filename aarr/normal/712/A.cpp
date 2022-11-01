#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N], b[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] + a[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		cout << b[i] << " ";
	}
	return 0;
}