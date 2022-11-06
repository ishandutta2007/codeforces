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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	string t = s;
	sort(t.begin(), t.end());
	bool cond = s == t;
	map<char, int> occ;
	for (auto &&c : s)
		++occ[c];
	cond &= occ.size() == 3;
	cond &= occ['c'] == occ['a'] || occ['c'] == occ['b'];
	cout << (cond ? "YES" : "NO");
	return 0;
}