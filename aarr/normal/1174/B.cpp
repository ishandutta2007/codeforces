#include <iostream>
#include <algorithm>
using namespace std;


int a[100005];
int main() {
	bool c = false, b = false;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			b = true;
		}
		else
			c = true;
	}
	if (b && c)
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	return 0;
}