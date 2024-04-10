#include <bits/stdc++.h>
using namespace std;

const int N = 27;

long long a[N][N];

long long get(long long x, int y) {
	return (x >> y) & 1;
}

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2) {
				a[i][j] = (1ll << (i + j));	
			}
			else {
				a[i][j] = 0;
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	for (int ii = 0; ii < q; ii++) {
		long long k;
		cin >> k;
		cout << "1 1" << endl;		
		int x = 1, y = 1;
		while (x + y != n * 2) {
			if (get(k, x + y + 1) ^ (x % 2)) {
				x++;
			}
			else {
				y++;
			}
			cout << x << " " << y << endl;
		}
	}

	
	return 0;
}