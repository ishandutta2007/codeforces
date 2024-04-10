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
#include <fstream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	int ans = 1, cnt = 1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i) {
			if (a[i] <= a[i - 1] * 2)
				ans = max(ans, ++cnt);
			else
				cnt = 1;
		}
	}
	cout << ans;
	return 0;
}