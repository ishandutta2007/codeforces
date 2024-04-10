/*input
6
0 0 1
0 1 1
1 0 2
2 0 2
1 1 3
2 1 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<array<int, 3>> a(n);
	for (auto &arr : a) for (auto &x : arr) cin >> x;

	vector<int> p = {1, 2, 3};

	int max_select = 0;
	ordered_set<pair<int, int>> lhs, rhs;
	do {
		for (int xy_swap = 0; xy_swap < 2; ++xy_swap) {
			for (auto &arr : a) swap(arr[0], arr[1]);

			for (int y_rev = 0; y_rev < 2; ++y_rev) {
				for (auto &arr : a) arr[0] = -arr[0];

				{
					lhs.clear(), rhs.clear();
					int cnt_up = (int) count_if(a.begin(), a.end(), [&](const auto &arr) {
						return arr[2] == p[0];
					});
					int cnt_split = 0;

					sort(a.begin(), a.end());
					for (int i = 0; i < n; ++i) {
						if (a[i][2] == p[0]) --cnt_up;
						else if (a[i][2] == p[1]) lhs.insert({a[i][1], a[i][0]});
						else rhs.insert({-a[i][1], a[i][0]});

						if (i == n - 1 || a[i][0] != a[i + 1][0]) {
							while (cnt_split > 0 and lhs.find_by_order(cnt_split - 1)->first >= -rhs.find_by_order(cnt_split - 1)->first) {
								--cnt_split;
							}
							while (cnt_split < (int) min(lhs.size(), rhs.size()) and lhs.find_by_order(cnt_split)->first < -rhs.find_by_order(cnt_split)->first) {
								++cnt_split;
							}
						}
						max_select = max(max_select, min(cnt_split, cnt_up));
					}
				}

				{
					lhs.clear(), rhs.clear();
					int cnt_up = (int) count_if(a.begin(), a.end(), [&](const auto &arr) {
						return arr[2] == p[0];
					});
					int cnt_split = 0;

					sort(a.begin(), a.end());
					for (int i = 0; i < n; ++i) {
						if (a[i][2] == p[0]) --cnt_up;
						else if (a[i][2] == p[1]) lhs.insert({a[i][0], a[i][1]});
						else rhs.insert({-a[i][0], a[i][1]});

						if (i == n - 1 || a[i][0] != a[i + 1][0]) {
							while (cnt_split > 0 and lhs.find_by_order(cnt_split - 1)->first >= -rhs.find_by_order(cnt_split - 1)->first) {
								--cnt_split;
							}
							while (cnt_split < (int) min(lhs.size(), rhs.size()) and lhs.find_by_order(cnt_split)->first < -rhs.find_by_order(cnt_split)->first) {
								++cnt_split;
							}
						}
						max_select = max(max_select, min(cnt_split, cnt_up));
					}
				}
			}
		}
	} while (next_permutation(p.begin(), p.end()));

	cout << max_select * 3 << endl;
}