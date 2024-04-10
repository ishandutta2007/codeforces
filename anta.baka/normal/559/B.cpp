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

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

string a, b;

bool solve(int l1, int r1, int l2, int r2) {
	int n = (r1 - l1 + 1);
	bool ok = true;
	for (int d = 0; d < n && ok; d++) {
		ok &= (a[l1 + d] == b[l2 + d]);
	}
	if (ok) {
		return true;
	}
	if (n & 1) {
		return false;
	}
	int m1 = (l1 + r1) >> 1;
	int m2 = (l2 + r2) >> 1;
	if (solve(l1, m1, l2, m2)) {
		if (solve(m1 + 1, r1, m2 + 1, r2)) {
			return true;
		}
		bool ok = true;
		for (int d = 0; d < (n >> 1) && ok; d++) {
			ok &= (b[l2 + d] == b[m2 + 1 + d]);
		}
		if (ok) {
			return solve(m1 + 1, r1, l2, m2);
		}
		return false;
	}
	else {
		return (solve(l1, m1, m2 + 1, r2) && solve(m1 + 1, r1, l2, m2));
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> a >> b; int n = sz(a);
	cout << (solve(0, n - 1, 0, n - 1) ? "YES" : "NO");
}