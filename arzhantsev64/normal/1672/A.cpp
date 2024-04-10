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
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s += x - 1;
	}
	cout << (s % 2 == 1 ? "errorgorn" : "maomao90") << "\n";
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