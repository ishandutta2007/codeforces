#include <iostream>
using namespace std;


int a[1005];
int ans[2];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1, r = n, i = 0;
	while (r - l >= 0) {
		if (a[l] > a[r]) {
			ans[i % 2] += a[l];
			l++;
		}
		else {
			ans [i % 2] += a[r];
			r--;
		}
		i++;
	}
	cout << ans[0] << " " << ans[1];
	return 0;
}