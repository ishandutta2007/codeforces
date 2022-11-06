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


	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	multiset<int> ms(a.begin(), a.end());
	while (ms.size() > k)
		ms.erase(ms.begin());
	
	cout << accumulate(ms.begin(), ms.end(), 0) << '\n';

	vector<int> ans;
	for(int i = 0; i < n; ++i)
		if (ms.count(a[i])) {
			ans.push_back(i);
			ms.erase(ms.find(a[i]));
		}
	assert(ans.size() == k);
	ans.back() = n - 1;
	cout << ans[0] + 1 << ' ';
	for (int i = 1; i < ans.size(); ++i)
		cout << ans[i] - ans[i - 1] << ' ';

	// system("pause");
	return 0;
}