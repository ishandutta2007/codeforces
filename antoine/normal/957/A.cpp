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
typedef long long ll;

bool contains(string s, string t) {
	for (int i = 0; i + t.size() <= s.size(); ++i)
		if (s.substr(i, t.size()) == t)
			return true;
	return false;
}

bool f() {
	int n;
	string s;
	cin >> n >> s;
	if (contains(s, "CC") || contains(s, "MM") || contains(s, "YY"))
		return false;
	if (s[0] == '?' || s[n - 1] == '?' || contains(s, "??"))
		return true;
	if (contains(s, "C?C") || contains(s, "M?M") || contains(s, "Y?Y"))
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << (f() ? "Yes" : "No");
	return 0;
}