#include <iostream>
using namespace std;

int a[1005];
int main() {
	int n, k, p, x, y, s = 0, q = 0;
	cin >> n;
	cin >> k;
	cin >> p;
	cin >> x;
	cin >> y;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		s += a[i];
		if (a[i] < y)
			q++;
	}
	//cout << s << endl;			
	//cout << q << endl;
	if (q > n / 2 || y > p) {
		cout << -1;
		return 0;
	}
	for (int i = k + 1; i <= n / 2 - q + k && i <= n; i++) {
		a[i] = 1;
		s++;
	}
	//cout << s << endl;
	for (int i = n / 2 - q + k + 1; i <= n; i++) {
		a[i] = y;
		s += y;
	}
	//cout << s << endl;
	if (s > x) {
		cout << -1;
	}
	else {
		for (int i = k + 1; i <= n; i++) {
			cout << a[i] << " ";
		}
	}
	return 0;
}