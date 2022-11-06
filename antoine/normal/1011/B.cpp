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

int f(int ans, map<int, int> occ) {
	int cnt = 0;
	for (auto &&x : occ)
		cnt += x.second / ans;
	return cnt;
}

int main() {

	int n, m;
	cin >> n >> m;
	
	map<int, int> occ;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}
	int ans = 100;
	while (ans && f(ans, occ) < n)
		ans--;
	cout << ans;
	return 0;
}