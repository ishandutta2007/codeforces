#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < (n + 1) / 2; i++) {
		int A = i + 1, B = n - i;
		deque<int> nums(m, 0);
		deque<int> rnums;
		iota(begin(nums), end(nums), 1);
		for(int j = 0; j < m; j++) {
			cout << (j % 2 ? B : A) << ' ' << (j % 2 ? nums.back() : nums.front()) << "\n";
			rnums.push_back((j % 2 ? nums.back() : nums.front()));
			if(j % 2) {
				nums.pop_back();
			} else {
				nums.pop_front();
			}
		}
		if(2 * i + 1 != n) {
			for(int j = m - 1; j >= 0; j--) {
				cout << (j % 2 ? A : B) << ' ' << rnums[j] << "\n";
			}
		}
	}
	return 0;
}