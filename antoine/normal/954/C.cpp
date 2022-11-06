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
#include <memory>

using namespace std;

int y = 1;

pair<int, int> getCell(int z) {
	if (!y) return{ -999, 0};
	--z;
	return{ z / y, z % y };
}

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i + 1 < n; ++i)
		if (abs(a[i + 1] - a[i]) != 1)
			y = abs(a[i + 1] - a[i]);

	for(int i = 0; i + 1 < n; ++i)
		if (dist(getCell(a[i]), getCell(a[i + 1])) != 1) {
			cout << "NO";
			return 0;
		}

	cout << "YES\n" << (int)1e9 << ' ' << y;
	return 0;
}