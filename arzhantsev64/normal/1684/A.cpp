#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> nums;
	int minn = 100;
	while (n > 0) {
		minn = min(minn, n % 10);
		nums.push_back(n % 10);
		n /= 10;
	}
	if (nums.size() == 2) {
		cout << nums[0] << '\n';
	} else {
		cout << minn << '\n';
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    	 solve();

    return 0;
}