#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;


const int N = 55;
int a[N][N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	bool ans = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != 1) {
				bool b = false;
				for (int k = 1; k <= n; k++) {
					for (int q = 1; q <= n; q++) {
						if (a[i][k] + a[q][j] == a[i][j]) {
						//	cout << i << " " << j << " " << k << " " << q << endl;
							b = true;
						}
					}
				}
				ans &= b;
			}
		}
	}
	if (ans) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}