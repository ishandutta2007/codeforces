#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	vector<pair<char, int>> pts;
	for (char c : s) {
		if (!pts.empty() && pts.back().first == c)
			++pts.back().second;
		else
			pts.push_back({ c, 1 });
	}

	int ans = 0;
	for (; pts.size() > 1; ++ans) {
		--pts[0].second;
		--pts.back().second;
		for (int i = 1; i < pts.size() - 1; ++i)
			pts[i].second -= 2;
		vector<pair<char, int>> pts2;
		for (auto &&pt : pts)
			if (pt.second > 0)
				pts2.push_back(pt);

		pts.clear();
		for (auto &&pt : pts2) {
			if (!pts.empty() && pts.back().first == pt.first)
				pts.back().second += pt.second;
			else
				pts.push_back(pt);
		}
	}

	cout << ans;
	return 0;
}