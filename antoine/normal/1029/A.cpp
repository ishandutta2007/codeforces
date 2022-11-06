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
#include <fstream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	int n, k;
	string t;
	cin >> n >> k >> t;
	string s = t;
	while (--k) {
		for (int i = (int)s.size() - (int)t.size() + 1; i <= s.size(); ++i)
			if (s.substr(i, s.size() - i) == t.substr(0, s.size() - i)) {
				s += t.substr(s.size() - i);
				break;
			}
	}
	cout << s;
	return 0;
}