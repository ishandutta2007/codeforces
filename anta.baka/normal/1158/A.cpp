#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <string>
#include <cassert>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//ifstream cin("in.txt");
	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	ll ans = 0;
	for (int& x : a) {
		cin >> x;
		ans += x;
	}
	ans *= m;
	for (int& x : b) {
		cin >> x;
	}
	sort(all(a));
	sort(all(b));
	if (a[n - 1] > b[0]) {
		return cout << -1, 0;
	}
	int pt = n - 1;
	for (int i = m - 1; i >= 0; i--) {
		while (pt > 0 && a[pt] > b[i]) {
			pt--;
		}
		if (pt == n - 1 && i == 0 && a[pt] != b[i]) {
			pt--;
		}
		if (pt == -1) {
			return cout << -1, 0;
		}
		ans += b[i] - a[pt];
	}
	cout << ans;
}