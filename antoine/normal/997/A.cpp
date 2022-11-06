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

	ll n, x, y;
	string s;
	cin >> n >> x >> y >> s;

	ll cnt = 0;
	for (int i = 0; i < s.size(); ++i)
		cnt += s[i] == '0' && (i == 0 || s[i] != s[i - 1]);
	cout << (cnt == 0 ? 0 : y + (cnt - 1) * min(x, y));
	return 0;
}