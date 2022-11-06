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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	int ans = (n & 1) && a[(n - 1) / 2] != b[(n - 1) / 2];

	for (int i = 0; i < ((n & 1) ? (n - 1) / 2 : n / 2); ++i) {
		map<char, int> occ;
		++occ[a[i]];
		++occ[b[i]];
		++occ[a[n - 1 - i]];
		++occ[b[n - 1 - i]];
		if (occ.size() == 2 && occ.begin()->second != 2) {
			assert(occ.begin()->second == 1 || occ.begin()->second == 3);
			++ans;
		}
		if (occ.size() == 3) {
			ans += (a[i] == a[n - 1 - i] ? 2 : 1);
		}
		if (occ.size() == 4)
			ans += 2;
	}
	cout << ans;
	// system("pause");
	return 0;
}