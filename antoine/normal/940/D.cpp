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

	int lLo = -1e9, rLo = -1e9, lHi = 1e9, rHi = 1e9, n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	string b;
	cin >> b;
	for (int i = 4; i < n; ++i) {
		if (b[i - 1] != b[i - 2] || b[i - 2] != b[i - 3] || b[i - 3] != b[i - 4])
			continue;
		if (b[i] != b[i - 1]) {
			if (b[i - 1] == '1')
				rHi = min(rHi, *min_element(a.begin() + i - 4, a.begin() + i + 1) - 1);
			else
				lLo = max(lLo, *max_element(a.begin() + i - 4, a.begin() + i + 1) + 1);
			continue;
		}
		if (b[i] == '0') {
			if (b[i - 1] == '0') {
				lHi = min(lHi, *max_element(a.begin() + i - 4, a.begin() + i + 1));
			}
		}
		else {
			if(b[i-1] == '1')
				rLo = max(rLo, *min_element(a.begin() + i - 4, a.begin() + i + 1));
		}
	}
	cout << lLo << ' ' << rHi;
	return 0;
}