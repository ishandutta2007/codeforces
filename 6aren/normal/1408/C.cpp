#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, ll;
		cin >> n >> ll;
		vector<int> a(n);
		for (int &e : a)
			cin >> e;
		double l = 0, r = ll;

		for (int rep = 0; rep < 100; rep++) {
			double mid = (l + r) / 2;
			double time_a = 0;
			double time_b = 0;
			double cur = 0;
			int speed = 1;
			for (int i = 0; i < n; i++) {
				if (a[i] > mid)
					break;
				time_a += (a[i] - cur) / speed;
				speed++;
				cur = a[i];
			}
			time_a += (mid - cur) / speed;

			speed = 1;
			cur = ll;
			for (int i = n - 1; i >= 0; i--) {
				if (a[i] < mid)
					break;
				time_b += (cur - a[i]) / speed;
				speed++;
				cur = a[i];
			}
			time_b += (cur - mid) / speed;


			if (time_a > time_b)
				r = mid;
			else 
				l = mid;
		}


		double ans = 0;
		double cur = 0;
		int speed = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] > l)
				break;
			ans += (a[i] - cur) / speed;
			speed++;
			cur = a[i];
		}
		ans += (l - cur) / speed;

		cout << setprecision(10) << fixed << ans << '\n';
	}

	return 0;
}