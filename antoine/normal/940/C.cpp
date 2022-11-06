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

	int n, k;
	string s;
	cin >> n >> k >> s;
	set<char> letters(s.begin(), s.end());
	if (k > n) {
		cout << s;
		for (int i = 0; i < k - n; ++i)
			cout << *letters.begin();
		return 0;
	}
	int i = k - 1;
	while (s[i] == *letters.rbegin())
		--i;
	cout << s.substr(0, i) << *letters.upper_bound(s[i]);
	for (++i; i < k; ++i)
		cout << *letters.begin();
	return 0;
}