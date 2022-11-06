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

	string s;
	int k;
	cin >> s >> k;
	int w[26];
	for (int i = 0; i < 26; ++i)
		cin >> w[i];
	
	ll ans = accumulate(s.begin(), s.end(), pair<int, ll>{1, 0}, [&](const pair<int, ll> &acc, const char &c) {
		return pair<int, ll>{ acc.first + 1, acc.second + w[c - 'a'] * acc.first };
	}).second;

	for (int i = s.size() + 1; i <= s.size() + k; ++i)
		ans += *max_element(w, w + 26) * (ll)i;
	cout << ans;
	return 0;
}