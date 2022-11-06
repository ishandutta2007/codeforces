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
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	s += s;
	int curr = 1, res = 1;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != s[i - 1])
			res = max(res, ++curr);
		else
			curr = 1;
	}
	cout << min(res, (int)s.size() >> 1) << '\n';
	return 0;
}