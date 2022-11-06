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

	string s;
	cin >> s;
	vector<int> zeros, ones, dp(s.size(), 1), choice(s.size(), -1);
	
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			if (zeros.empty()) {
				cout << -1;
				return 0;
			}
			choice[i] = zeros.back();
			dp[i] = dp[zeros.back()] + 1;
			zeros.pop_back();
			ones.push_back(i);
		}
		else {
			if (!ones.empty()) {
				choice[i] = ones.back();
				dp[i] = dp[ones.back()] + 1;
				ones.pop_back();
			}

			zeros.push_back(i);
		}
	}
	if (!ones.empty()) {
		cout << -1;
		return 0;
	}
	cout << zeros.size() << '\n';
	for (int x : zeros) {	
		cout << dp[x];
		vector<int> res;
		do {
			res.push_back(x);
			x = choice[x];
		} while (x != -1);
		reverse(res.begin(), res.end());
		for (auto &&x : res)
			cout << " " << x + 1;
		cout << '\n';
	}
	return 0;
}