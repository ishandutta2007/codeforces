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
#include <ctime>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, c[2];
	cin >> n >> c[0] >> c[1];

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = 0;
	for (int i = 0, j = n - 1; i <= j; ++i, --j) {
		if (v[i] == v[j]) {
			if (v[i] == 2)
				ans += min(2, j - i + 1) * min(c[0], c[1]);
		}
		else {
			if (v[i] != 2 && v[j] != 2) {
				cout << "-1\n";
				return 0;
			}
			ans += c[min(v[i], v[j])];
		}
	}
	cout << ans << endl;
	return 0;
}