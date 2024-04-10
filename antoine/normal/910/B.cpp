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

int f() {

	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v = { a,a,a,a,b,b };
	sort(v.begin(), v.end());
	int ans = 6;
	do {
		int used = 1;
		int left = n;
		for (auto &&x : v) {
			if (x <= left)
				left -= x;
			else {
				++used;
				left = n - x;
			}
		}
		ans = min(ans, used);
	} while (next_permutation(v.begin(), v.end()));
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << f();
	return 0;
}