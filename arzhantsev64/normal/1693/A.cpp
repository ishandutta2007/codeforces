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
	int b = 0;
	bool flag = false;
	bool was_zero = false;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		b += x;
		if (b < 0)
			flag = 1;
		if (b == 0)
			was_zero = 1;
		if (b != 0 && was_zero)
			flag = 1;
	}

	if (b != 0 || flag)
		cout << "No\n";
	else
		cout << "Yes\n";
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