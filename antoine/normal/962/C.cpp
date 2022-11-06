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
typedef long long ll;


string n;

bool f(const string &s) {
	for (int i = 0, j = 0; i < n.length(); ++i)
		if (n[i] == s[j] && ++j == s.length())
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = sqrt(2e9); i >= 1; --i) {
		string s = to_string(i*i);
		if (f(s)) {
			cout << n.length() - s.length();
			return 0;
		}
	}
	cout << -1;
	return 0;
}