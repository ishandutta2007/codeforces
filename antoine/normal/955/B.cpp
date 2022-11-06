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
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	map<int, int> occ;
	for (char c : s)
		++occ[c];

	bool ans;

	if (occ.size() >= 5 || occ.size() <= 1)
		ans = false;
	else if (occ.size() == 4) {
		ans = true;
	}
	else if (occ.size() == 3) {
		ans = false;
		for (auto &&x : occ)
			if (x.second >= 2)
				ans = true;
	}
	else if (occ.size() == 2) {
		ans = true;
		for (auto &&x : occ)
			if (x.second < 2)
				ans = false;
	}
	cout <<( ans ? "Yes" : "No");
	return 0;
}