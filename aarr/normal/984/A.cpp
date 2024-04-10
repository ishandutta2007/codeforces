#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;
int a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[(n - 1) / 2];
	return 0;
}