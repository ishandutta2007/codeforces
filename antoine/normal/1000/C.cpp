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

	ll n;
	cin >> n;


	map<ll, ll> mp1, mp2;
	set<ll> all;

	for (ll i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		mp1[l]++;
		mp2[r]++;
		all.insert({ l, r });
	}

	vector<ll> res(n + 1, 0);
	ll last = 0;
	ll cnt = 0;
	for (auto &&x : all) {
		res[cnt] += x - last - 1;
		cnt += mp1[x];
		++res[cnt];
		cnt -= mp2[x];
		last = x;
	}
	for (ll i = 1; i <= n; ++i)
		cout << res[i] << ' ';
	return 0;
}