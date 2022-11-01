#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <random>
#include <queue>
#include <numeric>
#include <ctime>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <iomanip>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto& x : a) {
			cin >> x;
		}
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] <= a[i + 1]) continue;
			int b = 0;
			while (a[i] > a[i + 1] + (1LL << b)) {
				b++;
			}
			bool fst = true;
			for (int j = b; j >= 0 && a[i] > a[i + 1]; j--) {
				if (a[i] <= a[i + 1] + (1LL << j) - 1) continue;
				if (fst) {
					fst = false;
					ans = max(ans, j + 1);
				}
				a[i + 1] += (1LL << j);
			}
			assert(a[i] <= a[i + 1]);
		}
		cout << ans << '\n';
	}
}