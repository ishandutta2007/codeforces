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
	vector<int> p(n/2);
	for (int i = 0; i < n/2; ++i)
		cin >> p[i];
	sort(p.begin(), p.end());

	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n / 2; ++i) {
		ans1 += abs(p[i] - (2 * i + 1));
		ans2 += abs(p[i] - (2 * i + 2));
	}
	cout << min(ans1, ans2);
	return 0;
}