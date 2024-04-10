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

bool f() {
	long long x, y;
	cin >> x >> y;
	if (!y)
		return false;
	if (y == 1)
		return !x;
	x -= y - 1;
	if (x < 0)
		return false;
	if (x & 1)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << (f() ? "Yes" : "No");

	return 0;
}