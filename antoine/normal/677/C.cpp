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

const int mod = (int)1e9 + 7;

vector<bool> f(char c) {
	int i;
	if (c >= '0' && c <= '9') i = c - '0';
	else if (c >= 'A' && c <= 'Z') i = c - 'A' + 10;
	else if (c >= 'a' && c <= 'z') i = c - 'a' + 36;
	else if (c == '-') i = 62;
	else if (c == '_') i = 63;
	else assert(false);

	vector<bool> v;
	for (int mask = 1; mask < (1 << 6); mask <<= 1) {
		v.push_back(i & mask);
	}
	return v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	string s;
	cin >> s;

	ll ans = 1;
	for(char c : s)
		for (bool b : f(c))
			if (!b)
				ans = (ans * 3) % mod;
	cout << (ans) % mod;
	return 0;
}