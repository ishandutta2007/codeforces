#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e5 + 1;
const int EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

int a[N];
int b[N];

pair<int, int> solve2(int n) {
	for (int i = 0; i < n; i++) {
		a[i] -= i;
	}
	int min_el = 0;
	pair<int, int> ans = { -1, -1 };
	for (int i = 1; i < n; i++) {
		if (a[min_el] < a[i]) {
			ans = { min_el, i };
		}
		if (a[min_el] > a[i]) {
			min_el = i;
		}
	}
	for (int i = 0; i < n; i++) {
		a[i] += i;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto ans = solve2(n);
	reverse(a, a + n);
	auto ans2 = solve2(n);
	if (ans == make_pair(-1, -1) && ans2 != make_pair(-1, -1)) {
		ans = { n - ans2.second - 1, n - 1 - ans2.first };
	}

	if (ans == make_pair(-1, -1)) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		cout << ans.first + 1 << " " << ans.second + 1 << "\n";
	}
}


int main() {
	//auto trash = freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	solve();
}