#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, t, c;
	cin >> n >> t >> c;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	multiset<int> setik;
	for (int i = 0; i < c - 1; i++) {
		setik.insert(a[i]);
	}
	int ans = 0;
	for (int i = c - 1; i < n; i++) {
		setik.insert(a[i]);
		if (*(--setik.end()) <= t) {
			ans++;
		}
		setik.erase(setik.find(a[i - c + 1]));
	}
	cout << ans;
}