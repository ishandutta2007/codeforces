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
	cin >> n;

	int d = 1e7;
	const int mid = (1e6) / 2;
	while (n-- > 0) {
		int a;
		cin >> a;
		if (a <= mid)
			d = min(d, mid - a);
		else
			d = min(d, a - (mid + 1));
	}
	cout << (mid - 1 - d);
	return 0;
}