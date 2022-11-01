#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, k; cin >> n >> k;
	long long h = (n / 2) + (n % 2);
	if (k <= h) cout << 2 * k - 1;
	else cout << 2 * (k - h);
	return 0;
}