#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, i; cin >> n;
	if (n % 2) {cout << -1; return 0;}
	for (i = 2; i <= n; i += 2)
		cout << i << " " << i - 1 << " ";
	return 0;
}