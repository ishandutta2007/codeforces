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
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;


bool f() {
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	if (s == t) return true;
	if (find(s.begin(), s.end(), '*') == s.end())
		return false;
	int i = 0;
	while (i < s.size() && i < t.size() && s[i] == t[i]) ++i;
	s = s.substr(i);
	t = t.substr(i);
	while (!s.empty() && !t.empty() && s.back() == t.back()) {
		s.pop_back();
		t.pop_back();
	}
	return s == "*";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << (f() ? "YES" : "NO") << endl;
	return 0;
}