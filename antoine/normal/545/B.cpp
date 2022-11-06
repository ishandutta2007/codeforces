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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	cin >> s >> t;
	const int n = s.size();

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt += s[i] != t[i];
	if (cnt & 1) {
		cout << "impossible";
		return 0;
	}
	for (int i = 0; cnt; ++i)
		if (s[i] != t[i]) {
			s[i] = t[i];
			cnt -= 2;
		}
	cout << s;
	return 0;
}