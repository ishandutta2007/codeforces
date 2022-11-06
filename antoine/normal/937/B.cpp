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

	int p, y;
	cin >> p >> y;

	for (; y > p; --y) {
		bool valid = true;
		for (int i = 2; i <= min(p, (int)1e5); ++i)
			if (y%i == 0) {
				valid = false;
				break;
			}
		if (valid) {
			cout << y;
			return 0;
		}
	}
	cout << -1;
	return 0;
}