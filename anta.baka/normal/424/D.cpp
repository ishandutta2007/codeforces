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
	
	int n, m, t;
	cin >> n >> m >> t;

	int tp, tu, td;
	cin >> tp >> tu >> td;

	vector<vi> a(n, vi(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	auto go = [&]( int i, int j, int ito, int jto ) {
		
		if (a[i][j] == a[ito][jto]) {
			return tp;
		}

		if (a[i][j] < a[ito][jto]) {
			return tu;
		}

		if (a[i][j] > a[ito][jto]) {
			return td;
		}

	};

	vector<vi> up(n, vi(m, 0));
	vector<vi> down(n, vi(m, 0));
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			up[i][j] = up[i - 1][j] + go(i, j, i - 1, j);
			down[i][j] = down[i - 1][j] + go(i - 1, j, i, j);
		}
	}

	vector<vi> left(n, vi(m, 0));
	vector<vi> right(n, vi(m, 0));
	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {

			left[i][j] = left[i][j - 1] + go(i, j, i, j - 1);
			right[i][j] = right[i][j - 1] + go(i, j - 1, i, j);
		}
	}

	int dif = 1e9 + 228;
	int A, B, C, D;

	auto upd = [&](int x) {

		if (abs(t - x) < dif) {

			dif = abs(t - x);
			return true;
		}
		return false;
	};

	for (int j = 0; j < m; j++) {
		for (int j1 = j + 2; j1 < m; j1++) {

			map<int, int> kek;
			kek[right[0][j1] - right[0][j]] = 0;

			for (int i = 2; i < n; i++) {

				int cur = up[i][j] + down[i][j1] + left[i][j1] - left[i][j];

				auto it = kek.lower_bound(t - cur);

				if (it != kek.end() && upd(cur + it->first)) {

					A = it->second;
					B = j;
					C = i;
					D = j1;
				}

				if (it != kek.begin()) {

					--it;

					if (upd(cur + it->first)) {

						A = it->second;
						B = j;
						C = i;
						D = j1;
					}
				}

				kek[ -up[i - 1][j] - down[i - 1][j1] +  right[i - 1][j1] - right[i - 1][j]] = i - 1;
			}
		}
	}

	cout << A + 1 << ' ' << B + 1 << ' ' << C + 1 << ' ' << D + 1;
}