#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());

const int P = 1e9 + 7;

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<ll> h(m);

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		vector<int> g;
		for (int j = 0; j < k; ++j) {
			int a;
			cin >> a;
			--a;
			g.push_back(a);
		}

		vector<vector<int>> f(k + 1);
		sort(all(g));

		int cnt = 1;
		for (int j = 1; j <= k; ++j) {
			if (!(j == k) && g[j] == g[j - 1])  {
				++cnt;
			} else {
				f[cnt].push_back(g[j - 1]);
				cnt = 1;
			}
		}

		for (int j = 0; j <= k; ++j) {
			ll x = rr() * 1e9 + rr();
			for (int l = 0; l < sz(f[j]); ++l)
				h[f[j][l]] ^= x;
		}
	}

	sort(all(h));

	ll ans = 1;
	int k = 1;

	for (int i = 1; i <= m; ++i) {
		if (!(i == m) && h[i] == h[i - 1]) {
			++k;
		} else {
			for (ll j = 1; j <= k; ++j)
				ans = ans * j % P;
			k = 1;
		}
	} 

	cout << ans << endl;
}