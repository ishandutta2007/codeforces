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
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	multiset<int> ms(a.begin(), a.end());
	sort(a.begin(), a.end());
	

	int ans = 0;
	for (auto&&x : a) {
		auto it = ms.upper_bound(x);
		if (it != ms.end()) {
			ans++;
			ms.erase(it);
		}
	}
	cout << ans;

	// system("pause"); /////////////////////////////////////////////////////////////
	return 0;
}