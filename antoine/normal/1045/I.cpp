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

int inputStr() {
	string s;
	cin >> s;

	int mask = 0;
	for (char c : s)
		mask ^= 1 << (c - 'a');
	return mask;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n;
	cin >> n;

	map<int, int> occ;


	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		const int mask = inputStr();
		ans += occ[mask];
		for (int m = 1; m <= (1 << 26); m <<= 1)
			ans += occ[mask ^ m];


		++occ[mask];
	}

	cout << ans << '\n';
	return 0;
}