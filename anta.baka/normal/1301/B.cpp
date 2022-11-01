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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int z; cin >> z; 
	while (z--) {
		int n; cin >> n;
		deque<int> a(n);
		bool any = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			any |= (a[i] != -1);
		}
		if (!any) {
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}
		
		vi t;
		for (int i = 0; i < n; i++) {
			if (a[i] != -1) {
				if (i > 0 && a[i - 1] == -1 || i < n - 1 && a[i + 1] == -1) {
					t.pb(a[i]);
				}
			}
		}
		sort(all(t));
		int lf = (abs(t[0] - t.back()) + 1) / 2;
		int kek = (t[0] + t.back()) / 2;

		int hi = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] != -1 && a[i + 1] != -1) {
				hi = max(hi, (int)abs(a[i] - a[i + 1]));
			}
		}
		//cout << "! ";
		cout << max(lf, hi) << ' ' << kek << '\n';
	}
}