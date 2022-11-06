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
#include <memory>
#include <assert.h>
#include <numeric>

using namespace std;
typedef long long ll;

int f(string s, int n) {
	if (count(s.begin(), s.end(), s[0]) == s.size())
		return s.size() - (n == 1);
	map<char, int> occ;
	int res = 0;
	for (char &c : s)
		res = max(res, min(++occ[c] + n, (int)s.size()));
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int res[3];
	for (int i = 0; i < 3; ++i) {
		string s;
		cin >> s;
		res[i] = f(s, n);
	}
	int i = max_element(res, res + 3) - res;
	if (count(res, res + 3, res[i]) > 1)
		cout << "Draw";
	else
		cout << vector<string>{"Kuro", "Shiro", "Katie"}[i];
	return 0;
}