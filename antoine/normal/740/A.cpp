#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	n %= 4;
	long long ans = 1e15;
	for (int i = 0; i < 1000; ++i) {
		int x = i % 10;
		int y = (i / 10) % 10;
		int z = (i / 100) % 10;
		if ((n + x + y * 2 + z * 3) % 4 != 0)
			continue;
		ans = min(ans, x*a + y*b + z*c);
	}
	cout << ans;
	return 0;
}