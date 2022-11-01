#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	const int N = 5e5;
	vi lg(N);
	int val = 0;
	for (int k = 1; k < N; k +=k) {
		val++;
		for (int i = k + 1; i < min(N, k + k + 1); i++) {
			lg[i] = val;
		}
	}
	int n, I; cin >> n >> I;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; cnt[x]++;
	}
	vi b;
	for (auto el : cnt) {
		b.pb(el.second);
	}
	vi p(sz(b));
	for (int i = 0; i < sz(b); i++) {
		p[i] = (i ? p[i - 1] : 0) + b[i];
	}
	int ans = 0;
	for (int l = 0, r = -1; l < sz(b); l++) {
		while (r < sz(b) - 1 && 1LL * n * lg[r - l + 2] <= 8 * I) {
			r++;
		}
		ans = max(ans, p[r] - (l ? p[l - 1] : 0));
	}
	cout << n - ans;
}