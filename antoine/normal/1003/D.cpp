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

int n, q;
map<int, int> occ;

int query(array<int, 31> &need) {
	int res = 0;
	for (int i = 30; i >= 0; --i) {
		if (need[i] > n) return -1;
		const int &occ_i = occ[1 << i];
		res += min(need[i], occ_i);
		if(need[i] > occ_i) {
			if (!i) return -1;
			need[i - 1] += (need[i] - occ_i) << 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}

	while (q--) {
		int x;
		cin >> x;
		array<int, 31> need;
		for (int i = 30; i >= 0; --i)
			need[i] = (x & (1 << i)) ? 1 : 0;
		cout << query(need) << '\n';
	}
	return 0;
}