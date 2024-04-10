#define _CRT_SECURE_NO_WARNINGS

#include <memory>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <sstream>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int M = 1010;
const int N = 1e6 + 10;

void solve() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	int bal = 0;
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			bal++;
		}
		else {
			bal--;
		}
		a.push_back(bal);
	}

	if (bal) {
		cout << -1 << endl;
		return;
	}

	int ans = 0;

	for (int i = 0; i < (int)a.size(); ++i) {
		if (a[i] < 0) {
			ans++;
		}
		if (a[i] == 0 && a[i - 1] < 0) {
			ans++;
		}

	}
	cout << ans << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("a.in", "r", stdin);

	int t = 1;
	while (t--) {
		solve();
	}

}