#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;
int n;
long long k;

int a[N];

void f() {
	int maxi = -(2e9 + 40);
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, a[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] = maxi - a[i];
	}
}

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		f();
		if (k % 2 == 0) {
			f();
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}