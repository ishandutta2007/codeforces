#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = (int) 2e5 + 9;
ll a[MxN + 9];
ll cs1[MxN + 9];
ll cs2[MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cs1[i] = cs1[i - 1] + a[i] * (i & 1);
		cs2[i] = cs2[i - 1] + a[i] * ((i & 1) ^ 1);
	}

	const ll total = accumulate(a + 1, a + 1 + n, 0LL);

	int ans = 0;

	for (int i = 1; i <= n; ++i) {
		const ll curr = cs1[i - 1] + cs2[n] - cs2[i];
		ans += curr * 2 == total - a[i];
	}
	cout << ans;
	return 0;
}