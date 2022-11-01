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

ll f[N];

void solve() {
	ll n;
	cin >> n;
	ll m;
	cin >> m;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] * i % m;
	}

	ll ans = 0;
	for (int l = 1; l <= n; l++) {
		ll ad = (n - l + 1) * (n - l + 1) % m * f[l] % m * f[n - l] % m;
		ans = (ans + ad) % m;
	}
	cout << ans << endl;
}

int main() {
	//auto trash = freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}