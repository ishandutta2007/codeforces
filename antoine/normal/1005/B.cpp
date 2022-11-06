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
	int i = s.size() - 1, j = t.size() - 1;
	while (i >= 0 && j >= 0 && s[i] == t[j]) {
		--i, --j;
	}
	cout << i + j + 2;
	return 0;
}