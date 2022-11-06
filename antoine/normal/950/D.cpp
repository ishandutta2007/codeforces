#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, q;
	cin >> n >> q;
	while (q-- > 0) {
		long long x;
		cin >> x;
		x = (n << 1) - x;
		while (!(x & 1))
			x >>= 1;
		x = (n << 1) - x;
		x = (x + 1) >> 1;
		cout << x << '\n';
	}
	return 0;
}