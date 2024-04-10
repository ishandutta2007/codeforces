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
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	string res(n, 'A');

	map<int, vector<int>> occ;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		occ[a[i]].push_back(i);
	}

	int diff = 0;

	for (auto &&x : occ) {
		if (x.second.size() == 1) {
			res[x.second.front()] = 'A' + diff;
			diff ^= 1;
		}
	}

	if (diff) {
		auto it = find_if(occ.begin(), occ.end(), [](const pair<int, vector<int>> &p) {
			return p.second.size() > 2;
		});
		if (it == occ.end()) {
			cout << "NO\n";
			return 0;
		}
		res[it->second.front()] = 'B';
	}

	cout << "YES\n" << res << '\n';
	return 0;
}