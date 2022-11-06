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

using namespace std;

long long f(const string &s) {
	long long count = 0;
	long long ans = 0;
	for (char c : s)
		if (c == 's')
			++count;
		else if (c == 'h')
			ans += count;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n, { 0, 0 });

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ans += f(s);
		for (char c : s)
			if (c == 's')
				++v[i].first;
			else if (c == 'h')
				++v[i].second;
	}
	sort(v.begin(), v.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
		return (long long)lhs.first * rhs.second > (long long)rhs.first * lhs.second;
	});
	long long count = 0;
	for (auto &&p : v) {
		ans += p.second * count;
		count += p.first;
	}
	cout << ans;
	return 0;
}