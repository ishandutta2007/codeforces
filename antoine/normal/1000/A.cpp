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

	map<string, int> occ;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		++occ[s];
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (occ[s] && --occ[s] == 0)
			occ.erase(s);
	}
	cout << accumulate(occ.begin(), occ.end(), 0, [](const int acc, const pair<string, int> p) {
		return acc + p.second;
	});
	return 0;
}