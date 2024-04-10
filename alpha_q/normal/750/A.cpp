#include <bits/stdc++.h> 

using namespace std;

int main (int argc, char const *argv[]) {
	int n, k; cin >> n >> k;
	k = 240 - k;
	int l = 0, r = n;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		int tym = (5 * m * (m + 1))/2;
		if (tym <= k) l = m;
		else r = m - 1;
	}
	cout << l << endl;
	return 0;
}