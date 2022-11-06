#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Seg {
	int id, l, r;
	bool operator<(const Seg &other) const {
		return r < other.r;
	}
};

Seg a[(int) 2e5 + 9];
int dp[(int) 2e5 + 9];
int ans[(int) 2e5 + 9];

void f() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].l >> a[i].r;
		a[i].id = i;
	}

	sort(a, a + n);
	dp[n] = (int) 1e9 + 9;
	for (int i = n - 1; i >= 0; --i)
		dp[i] = min(dp[i + 1], a[i].l);

	for (int i = 0; i < n - 1; ++i)
		if (a[i].r < dp[i + 1]) {
			for (int j = 0; j < n; ++j)
				ans[a[j].id] = j <= i ? 1 : 2;
			for(int j = 0; j < n; ++j)
				cout << ans[j] << ' ';
			cout << '\n';
			return;
		}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		f();
	return 0;
}