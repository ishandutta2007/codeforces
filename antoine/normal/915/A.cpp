#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int ans = 10000;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (k%a == 0)
			ans = min(ans, k / a);
	}cout << ans;
	return 0;
}