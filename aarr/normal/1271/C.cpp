#include <iostream>
using namespace std;


const int N = 200 * 1000 + 5;

int x[N];
int y[N];
int main() {
	int n, sx, sy;
	cin >> n >> sx >> sy;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] < sx) {
			a1++;
		}
		if (x[i] > sx) {
			a2++;
		}
		if (y[i] < sy) {
			a3++;
		}
		if (y[i] > sy) {
			a4++;
		}
	}
	int z = max(a1, a2);
	z = max(z, a3);
	z = max(z, a4);
	if (a1 == z) {
		cout << a1 << endl;
		cout << sx - 1 << " " << sy << endl;
		return 0;
	}
	if (a2 == z) {
		cout << a2 << endl;
	/*	for (int i = 0; i < n; i++) {
			if (x[i] > sx) {
				cout << i + 1 << endl;
			}
		}*/
		cout << sx + 1 << " " << sy << endl;
		return 0;
	}
	if (a3 == z) {
		cout << a3 << endl;
	/*	for (int i = 0; i < n; i++) {
			if (y[i] < sy) {
				cout << i + 1 << endl;
			}
		}*/
		cout << sx << " " << sy - 1 << endl;
		return 0;
	}
	if (a4 == z) {
		cout << a4 << endl;
	/*	for (int i = 0; i < n; i++) {
			if (y[i] > sy) {
				cout << i + 1 << endl;
			}
		}
		*/
		cout << sx << " " << sy + 1 << endl;
		return 0;
	}
	return 0;
}