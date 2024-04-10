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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;

	int cs = 0;
	map<int, int> mp = { {0, -1} };
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		cs += (s[i] == '1' ? 1 : -1);
		if (mp.count(cs))
			ans = max(ans, i - mp[cs]);
		else
			mp[cs] = i;
	}
	cout << ans;
	return 0;
}