#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <int> p(n);
		for (auto &c : p) {
			cin >> c;
		}
		sort(all(p));
		vector <int> pr(n + 1);
		for (int i = 1; i <= n; i++) {
			pr[i] = pr[i - 1] + p[i - 1];
		}
		int x, a, y, b;
		cin >> x >> a >> y >> b;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
		int k;
		cin >> k;
		int left = 0, right = n + 1;
		int l = (a * b) / gcd(a, b);
		while (right - left > 1) {
			int mid = (left + right) / 2;
			int both = mid / l;
			int f = mid / a - both;
			int s = mid / b - both;
			int sum = ((pr[n] - pr[n - both]) / 100) * (x + y);
			int sum1 = ((pr[n - both] - pr[n - both - f]) / 100) * x;
			int sum2 = ((pr[n - both - f] - pr[n - both - f - s]) / 100) * y;
			if (sum + sum1 + sum2 >= k) {
				right = mid;
			} else {
				left = mid;
			}
		}
		if (right == n + 1) {
			cout << -1 << "\n";
		} else {
			cout << right << "\n";
		}
	}
	return 0;
}