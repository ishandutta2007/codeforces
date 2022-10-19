#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, a[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i-= 2) {
		cout << a[i] << " ";
	}
	int s;
	if (n % 2) {
		s = 2;
	} else {
		s = 1;
	}
	for (int i = s; i <= n; i += 2) {
		cout << a[i] << " ";
	}
	return 0;
}