#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;

int a[N];
int b[N];
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int x = 0, ans = 0;
		for (int j = 0; j < i; j++) {
			b[j] = a[j];
			x += a[j];
		}
		sort(b, b + i);
		x += a[i];
		int j = i - 1;
		//cout << i << " " << j << " " << x << endl;
		while (x > m) {
			x -= b[j];
			j--;
		}
		cout << i - j - 1 << " ";
	}
	return 0;
}