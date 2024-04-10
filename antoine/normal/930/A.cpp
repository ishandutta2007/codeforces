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

int p[(int)1e5];
int h[(int)1e5];

int height(int i) {
	if (h[i] != -1)
		return h[i];
	return h[i] = height(p[i]) + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(h, -1, sizeof h);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}

	h[0] = 0;

	vector<int> mp(n+2);
	for (int i = 0; i < n; ++i)
		++mp[height(i)];

	int ans = 0;
	for (auto &&x : mp)
		ans += x & 1;
	cout << ans;
	return 0;
}