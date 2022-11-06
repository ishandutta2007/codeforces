#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] > a[j])
				ans ^= 1;
	int m;
	cin >> m;
	for (; m > 0; --m) {
		int l, r;
		cin >> l >> r;
		if (l != r) {
			int side = r - l + 1;
			int x = side * side - side;
			x /= 2;
			ans ^= x;
		}
		cout << ((ans & 1) ? "odd" : "even") << '\n';
	}
	return 0;
}