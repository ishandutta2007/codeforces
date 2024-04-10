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
	n += n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i += 2) {
		int j = i + 1;
		while (a[j] != a[i])
			assert(++j < n);
		for (; j != i + 1; --j)
			swap(a[j], a[j - 1]), ++ans;
	}
	cout << ans;
	return 0;
}