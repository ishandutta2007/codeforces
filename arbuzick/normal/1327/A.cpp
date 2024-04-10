#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		if (n % 2 != k % 2 || (1 + k * 2 - 1) * k / 2 > n)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}