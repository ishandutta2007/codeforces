#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<int> nums = { 4, 8, 15, 16, 23, 42 };
	sort(nums.begin(), nums.end());

	vector<int> q(4);
	for (int i = 0; i < 4; ++i) {
		cout << "? " << i + 1 << ' ' << i + 2 << endl;
		cin >> q[i];
	}
	for (;;) {
		bool ok = true;
		for (int i = 0; i < 4; ++i)
			ok &= nums[i] * nums[i + 1] == q[i];
		if (ok)
			break;
		assert(next_permutation(nums.begin(), nums.end()));
	}
	cout << "!";
	for (int x : nums)
		cout << ' ' << x;
	return 0;
}