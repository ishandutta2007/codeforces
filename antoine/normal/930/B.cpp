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

string s;

double g(const vector<int> &indexes, const int &i) {
	static int occ[26];
	memset(occ, 0, sizeof occ);
	for (const int &k : indexes)
		++occ[s[(k + i) % s.size()] - 'a'];
	int count = 0;
	for (int j = 0; j < 26; ++j)
		count += occ[j] == 1;
	return (double)count / indexes.size();
}

double f(const vector<int> &indexes) {
	double res = 0;
	for (int i = 0; i < s.size(); ++i)
		res = max(res, g(indexes, i));
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed;
	cout << setprecision(10);


	cin >> s;

	vector<int> indexes[26];
	for (int i = 0; i < s.size(); ++i)
		indexes[s[i] - 'a'].push_back(i);

	double ans = 0;

	for (int i = 0; i < 26; ++i)
		ans += (double)f(indexes[i]) * indexes[i].size() / s.size();
	cout << ans;
	return 0;
}