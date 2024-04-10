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
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	vector<pair<int, int>> v = { {0, 0} };
	for (char c : s) {
		auto x = v.back().first;
		auto y = v.back().second;
		if (c == 'U')
			v.push_back({ x + 1, y });
		else
			v.push_back({ x, y + 1 });
	}
	int ans = 0;
	for(int i = 1; i < v.size() - 1; ++i)
		if(v[i].first == v[i].second) {
			bool test1 = v[i - 1].first < v[i - 1].second;
			bool test2 = v[i + 1].first < v[i + 1].second;
			ans += test1 != test2;
		}
	cout << ans;
	return 0;
}