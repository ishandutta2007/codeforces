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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int l, r, a;
	cin >> l >> r >> a;
	while (a--) {
		if (l < r)
			++l;
		else
			++r;
	}
	cout << 2 * min(l, r);
	return 0;
}