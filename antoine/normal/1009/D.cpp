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


int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	if (m < n - 1) {
		cout << "Impossible\n";
		return 0;
	}

	vector<pair<int, int>> res;
	for(int i = 2; i <= n; ++i)
		res.emplace_back(i, 1);

	for (int i = 2; i <= n && res.size() < m; ++i) {
		for(int j = 2; j < i && res.size() < m; ++j)
			if (gcd(i, j) == 1)
				res.emplace_back(i, j);
	}
	
	if (res.size() < m) {
		cout << "Impossible\n";
	}
	else {
		cout << "Possible\n";
		for (auto &&e : res)
			cout << e.first << ' ' << e.second << '\n';
	}
	return 0;
}