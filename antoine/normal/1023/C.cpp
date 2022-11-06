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

	int n, k;
	string s;
	cin >> n >> k >> s;
	assert(k % 2 == 0 && n == s.size());
	
	stack<int> sta;
	vector<int> match(n);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			sta.push(i);
		else {
			assert(s[i] == ')');
			match[i] = sta.top();
			match[sta.top()] = i;
			sta.pop();
		}
	}

	assert(sta.empty());
	vector<bool> removed(n, 0);
	int remCnt = 0;
	for (int i = 0; i < n; ++i) {
		if (removed[i]) continue;
		if (remCnt < (n - k) / 2) {
			++remCnt;
			removed[match[i]] = true;
		} else {
			cout << s[i];
		}
	}
	return 0;
}