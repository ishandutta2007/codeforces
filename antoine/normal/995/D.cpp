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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

// D

int c[1 << 18];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(10);

	int n, r;
	cin >> n >> r;
	for (int i = 0; i < (1 << n); ++i)
		cin >> c[i];

	ll sum = accumulate(c, c + (1 << n), 0ll);
	cout << (long double)sum / (1 << n) << '\n';
	while (r--) {
		int z, g;
		cin >> z >> g;
		sum += g - c[z];
		c[z] = g;
		cout << (long double)sum / (1 << n) << '\n';
	}
	return 0;
}