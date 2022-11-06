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
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}

	vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		set<int> s;
		int curr = i;
		for (; !s.count(curr) && ans[curr] == -1; curr = p[curr])
			s.insert(curr);
	
		for (; ans[curr] == -1; curr = p[curr])
			ans[curr] = curr;

		for (int j = i; ans[j] == -1; j = p[j])
			ans[j] = ans[curr];
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] +  1 << ' ';
	return 0;
}