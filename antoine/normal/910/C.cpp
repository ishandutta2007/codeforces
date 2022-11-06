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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<char> allLetters;
	set<char> leadingLetters;
	map<char, long long> coeff;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		leadingLetters.insert(s[0]);
		for (int j = 0; j < s.size(); ++j) {
			allLetters.insert(s[j]);
			coeff[s[j]] += pow(10, s.size() - 1 - j);
		}
	}

	map<int, char> mp;

	const int leastDigit = allLetters.size() == leadingLetters.size() ? 1 : 0;
	const int maxDigit = leastDigit + (int)allLetters.size() - 1;
	for (int d = leastDigit; d <= maxDigit; ++d) {
		long long bestCoeff = -1;
		for (auto &&x : allLetters) {
			if (!d && leadingLetters.count(x))
				continue;
			if (coeff[x] > bestCoeff) {
				bestCoeff = coeff[x];
				mp[d] = x;
			}
		}
		allLetters.erase(mp[d]);
	}
	long long ans = 0;
	for (int d = leastDigit; d <= maxDigit; ++d)
		ans += d * coeff[mp[d]];
	cout << ans;
	return 0;
}