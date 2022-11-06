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
#undef NDEBUG
#include <assert.h>
#include <random>

using namespace std;
typedef long long ll;


void A() {
	map<string, string> mp = {
		{"purple", "Power"},
		{"green", "Time"},
		{ "blue", "Space"},
		{ "orange", "Soul"},
		{ "red",  "Reality"},
		{ "yellow", "Mind"}
	};

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		mp.erase(s);
	}
	cout << mp.size();
	for (auto &&x : mp)
		cout << '\n' << x.second;
}

ll _pow(ll x, ll y) {
	ll res = 1;
	while (y--)
		res *= x;
	return res;
}

void B() {
	int x, y;
	cin >> x >> y;
	if (x == y)
		cout << '=';
	else if (x == 1)
		cout << '<';
	else if (y == 1)
		cout << '>';
	else if (max(x, y) <= 20) {
		ll diff = _pow(x, y) - _pow(y, x);
		cout << (diff < 0 ? '<' : diff ? '>' : '=');
	} else
		cout << (x < y ? '>' : '<');
}

void C() {
	int n;
	cin >> n;
	vector<int> s(n), c(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		cin >> c[i];

	vector<int> dp = c;

	for (int round = 0; round < 2; ++round) {
		for (int i = 0; i < n; ++i) {
			dp[i] = 1e9;
			for (int j = i + 1; j < n; ++j)
				if (s[i] < s[j])
					dp[i] = min(dp[i], c[i] + dp[j]);
		}
	}

	int ans = *min_element(dp.begin(), dp.end());
	cout << (ans == 1e9 ? -1 : ans);
}

void D() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	if (!a[0]) {
		cout << 1;
		return;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	A();

	return 0;
}