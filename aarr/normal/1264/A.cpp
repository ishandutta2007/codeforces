#include <iostream>
#include <cmath>
using namespace std;


const int N = 400 * 1000 + 5;
int n;


/*bool isval(int x) {
	if (x == 0)
		return true;
	int i;
	for (i = 0; i < x || a[i] == a[i - 1]; i++) {
		
	}
	int y = i;
	for (i; i < )
}*/
int a[5 * N];
int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> n;
		for (int j = 0; j < 5 * n; j++) {
			a[j] = -1;
		}
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
	/*	int dw = 0, up = n / 2;
		while (up - dw > 1) {
			int md = (dw + up) / 2;
			if (isval(md)) {
				dw = up;
			}
			else {
				up = md;
			}
		}
		if (dw == 0) {
			cout << "0 0 0" << endl;
		}
		else {
				
		}*/
		int i;
		for (i = 1; i < n && a[i] == a[i - 1]; i++) {
			
		}
		int x = i;
		int j = i * 2 + 1;
		for (j; a[j] == a[j - 1]; j++) {
			
		}
		if (j == n) {
			cout << "0 0 0" << endl;
			continue;
		}
		int ans1 = i, ans2 = j - i;
	//	int k = j + i + 1;
	//	for (k; k * 2 < n; k++) {
	//		
	//	}
		int k = n / 2;
		while (a[k] == a[k - 1] && k > j) {
			k--;
		}
		int ans3 = k - j;
	//	cout << "73 " << i << " " << j << " " << k << endl;
		if (k <= n / 2 && ans2 > ans1 && ans3 > ans1) {
			cout << ans1 << " " << ans2 << " " << ans3 << "\n";
		}
		else {
			cout << "0 0 0" << "\n";
		}
	}
	return 0;
}