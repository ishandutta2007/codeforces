#define _CRT_SECURE_NO_WARNINGS

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

const int inf = 1e9;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vi fac(n + 1);
	fac[0] = 1;
	for (int i = 1; i < n + 1; i++) {
		fac[i] = (ll)fac[i - 1] * i % m;
	}
	ll ans = 0;
	for (int len = 1; len <= n; len++) {
		ans = (ans + (ll)fac[len] * fac[n - len] % m * (n - len + 1) % m * (n - len + 1)) % m;
	}
	cout << ans;
}