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

	vector<int> f = { 1, 1 };
	for (int i = 0;; ++i) {
		int sum = *(f.end() - 1) + *(f.end() - 2);
		f.push_back(sum);
		if (sum > 1000)
			break;
	}


	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		auto it = lower_bound(f.begin(), f.end() - 1, i);
		if (*it == i)
			cout << 'O';
		else
			cout << 'o';
	}
	return 0;
}