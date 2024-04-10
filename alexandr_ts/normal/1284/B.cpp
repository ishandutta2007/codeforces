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
#include <numeric>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e5 + 1;
const int EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const ld PI = acosl(-1);
const int N = 2e6 + 10;

vector<int> g[N];
int mx[N], mn[N];
bool incr[N];
int pref[N];

void solve() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		g[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> g[i][j];
		}
		mn[i] = *min_element(g[i].begin(), g[i].end());
		mx[i] = *max_element(g[i].begin(), g[i].end());
		incr[i] = false;
		for (int j = 0; j < k - 1; j++) {
			if (g[i][j] < g[i][j + 1]) {
				incr[i] = true;
			}
		}
		if (!incr[i]) {
			pref[mx[i]]++;
		}
		else {
			cnt++;
		}
	}

	for (int i = N - 10; i >= 0; i--) {
		pref[i] += pref[i + 1];
	}

	ll ans = 2 * (ll)cnt * (n - cnt) + (ll)cnt * cnt;
	for (int i = 0; i < n; i++) {
		if (incr[i]) {
			continue;
		}
		ans += pref[mn[i] + 1];
	}
	cout << ans << endl;
}

int main() {
	//auto trash = freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}