#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
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
#define eb emplace_back
#define endl '\n'
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const int inf = 1e9 + 228;

ll c2(ll n) {
	return n * (n + 1) / 2;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int z; cin >> z; 
	while (z--) {
		ll n, m;
		cin >> n >> m;
		ll ans = n * (n + 1) / 2;
		if (n == m) {
			cout << ans << '\n';
			continue;
		}
		if (n % (m + 1) == 0) {
			ll len = n / (m + 1) - 1;
			ans -= c2(len) * m + c2(len + 1);
		}
		else {
			ll nn = n + ((m + 1) - n % (m + 1));
			ll len = nn / (m + 1);
			assert((nn - n - 1) * (len - 1) + ((m + 1) - (nn - n) + 1) * len - 1 == n);
			ans -= (nn - n - 1) * c2(len - 2) + ((m + 1) - (nn - n) + 1) * c2(len - 1);
		}
		cout << ans << '\n';
	}
}