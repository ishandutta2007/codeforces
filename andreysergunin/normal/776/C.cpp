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
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const ll INF = 1e16 + 10;

int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("arithmetic.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) 
		cin >> a[i];

	ll x = 1;

	map<ll, int> mp;
	vector<ll> pref(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; ++i) 
		pref[i + 1] = pref[i] + a[i];

	++mp[0];

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (abs(k) > 1) {
			ll x = 1;
			for (; abs(x) < INF; x *= k) {
				ans += mp[pref[i] - x];
			}
		} else if (k == -1) {
			ans += mp[pref[i] - 1];
			ans += mp[pref[i] + 1];
		} else {
			ans += mp[pref[i] - 1];
		}
		++mp[pref[i]];
	}
	cout << ans << endl;
}