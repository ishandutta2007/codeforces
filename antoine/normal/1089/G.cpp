#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[7];
int cs[7];

int f(int i) {
	return (i/7) *cs[6] + cs[i%7];
}

int f() {
	int k;
	cin >> k;
	for (int &x : a)
		cin >> x;
	partial_sum(a, a + 7, cs);

	int ans = (int)1e9;
	for (int i = 0; i < 7; ++i) {
		int lo = i;
		int hi = (int) 1e9;
		while (lo < hi) {
			const int mid = (lo + hi) / 2;
			const int s = f(mid) - (i ? cs[i - 1] : 0);
			if(s >= k)
				hi = mid;
			else
				lo = mid + 1;
		}
		ans = min(ans, lo - i + 1);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		cout << f() << '\n';
	return 0;
}