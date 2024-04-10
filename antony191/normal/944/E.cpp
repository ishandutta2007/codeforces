#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <bitset>


using namespace std;

const int inf = 1e9;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, bool>>> s(m + 1);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		s[x].push_back({ i, 0 });
		s[y].push_back({ i, 1 });
	}
	int stack = 0;
	vector<int> a(m, 0);
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < (int)s[i].size(); ++j)
			if (!s[i][j].second)
				stack++;
		a[i - 1] = stack;
		for (int j = 0; j < (int)s[i].size(); ++j)
			if (s[i][j].second)
				stack--;
	}
	vector<int> sum1(m), sum2(m);
	vector<int> b1(m + 1, inf);
	b1[0] = 0 - inf;
	int t = 0;
	for (int i = 0; i < m; ++i) {
		int l = 0, r = m + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (b1[mid] > a[i])
				r = mid;
			else
				l = mid;
		}
		b1[l + 1] = a[i];
		sum1[i] = max(t, l + 1);
		t = l + 1;
	}
	vector<int> b2(m + 1, inf);
	b2[0] = 0 - inf;
	t = 0;
	for (int i = m - 1; i >= 0; --i) {
		int l = 0, r = m + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (b2[mid] > a[i])
				r = mid;
			else
				l = mid;
		}
		b2[l + 1] = a[i];
		sum2[i] = max(t, l + 1);
		t = l + 1;
	}
	int max = 0;
	for (int i = 0; i < m - 1; ++i)
		if (sum1[i] + sum2[i + 1] > max)
			max = sum1[i] + sum2[i + 1];
	cout << max;
	return 0;
}