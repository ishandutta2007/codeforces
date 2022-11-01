#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int h, n, ans = 0;
		cin >> h >> n;
		int last = h;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		a[n + 1] = -N;
		bool b = true;
		for (int j = 1; j < n; j++) {
		//	cout << "45 " << j << " " << a[j] << endl;
			a[j] = a[j + 1] + 1;
			if (a[j] <= 2)
				break;
			if (a[j + 1] == a[j] - 1) {
				if (a[j + 2] == a[j] - 2)
					j++;
				else {
					ans++;
					a[j + 1]--;
				}
			}
		//	else {
		//		a[j + 1] = a[j + 2] + 1;
		//	}
		//	if (a[j + 1] == a[j] - 1 && a[j + 2] != a[j] - 2) {
		//		cout << "23 " << j << endl;
		/*		if (!b) {
					b = true;
				}
				else {
					ans++;
					if (a[j + 2] == a[j] - 3)
				//		b = false;
				}
				a[j + 1] = a[j] - 2;
			//	continue;*/
		//		ans++;
		//		a[j + 1] = a[j] - 2;
		//	}
		//	else {
		//		if (a[j + 1] == a[j] - 1) {
		//			j++;
		//		}
		//	}
	//		cout << "49 " << j << " " << ans << endl;
		}
	//	cout << "73 " << ans << endl;
	//	if (a[n] == a[n - 1] - 1 && a[n] != 1)
	//		ans++;
		cout << ans << endl;
	}
	return 0;
}