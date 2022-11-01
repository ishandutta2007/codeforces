#include <iostream>
using namespace std;

const int LG = 38;

const long long N = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 7;

long long po3[LG + 5];
int a[LG + 5];
int main() {
	po3[0] = 1;
	for (int i = 1; i <= LG + 1; i++) {
		po3[i] = po3[i - 1] * 3;
	//	cout << i << " " << po3[i] << endl;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long n, ans = 0, x = -1;
		cin >> n;
		long long m = n;
		for (int j = LG; j >= 0; j--) {
			a[j] = n / po3[j];
			n %= po3[j];
		//	cout << j << " " << a[j] << endl;
		}
		for (int j = 0; j <= LG; j++) {
			if (a[j] == 2)
				x = j;
		}
		for (int j = x; j <= LG + 1; j++) {
			if (a[j] > 1) {
				a[j] = 0;
				a[j + 1]++;
			}
			ans += po3[j] * a[j];
		}
	//	for (int j = 0; j <= LG + 1; j++) {
	//		ans += po3[j] * a[j];
	//	}
		if (x == -1)
			cout << m << endl;
		else
			cout << ans << endl;
	}
	return 0;
}