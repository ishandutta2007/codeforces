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
	
	int n;
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
		ans ^= x;
	}

	vi pref(n + 1);
	pref[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		pref[i] = pref[i - 1] ^ i;
	}

	for (int j = 1; j <= n; j++) {

		int comp = n / j;

		if (comp & 1) {

			ans ^= pref[j - 1];
		}

		int rem = n % j;

		if (rem > 0) {

			ans ^= pref[rem];
		}
	}

	cout << ans;
}