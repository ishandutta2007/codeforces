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

const int MaxX = (int)1.5e7 + 999;

int sieve[MaxX + 1];

vector<pair<int, int>> getFact(int x) {
	vector<pair<int, int>> v;

	while (x > 1) {
		v.emplace_back(sieve[x], 0);
		do {
			x /= sieve[x];
			++v.back().second;
		} while (sieve[x] == v.back().first);
	}
	return v;
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i <= MaxX; ++i) {
		if (!sieve[i]) {
			for (int j = i; j <= MaxX; j += i)
				sieve[j] = i;
		}
	}

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	const int g = accumulate(a.begin(), a.end(), 0, gcd);
	auto gcdFactVec = getFact(g);
	map<int, int> gcdFact;
	for (auto &&x : gcdFactVec)
		gcdFact[x.first] = x.second;


	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		auto fact = getFact(a[i]);
		for (auto &&x : fact) {
			assert(x.second > 0);
			auto it = gcdFact.find(x.first);
			if (it == gcdFact.end() || x.second > it->second)
				++mp[x.first];
		}
	}

	int ans = n;
	for (auto &&x : mp)
		ans = min(ans, n - x.second);

	cout << (ans == n ? -1 : ans) << '\n';
	return 0;
}