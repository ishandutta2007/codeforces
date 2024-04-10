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

set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'y' };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	vector<char> v;
	for (int i = 0; i < n; ++i) {
		auto c = s[i];
		if (!v.empty() && vowels.count(c) && vowels.count(v.back()))
			continue;
		v.push_back(c);
	}
	cout << string(v.begin(), v.end());
	return 0;
}