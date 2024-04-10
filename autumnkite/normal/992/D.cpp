#include <bits/stdc++.h>

const int N = 200005;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
int a[N];
int pre[N], suf[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}

	pre[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 1) {
			pre[i] = pre[i - 1] + 1;
		} else {
			pre[i] = 0;
		}
	}
	suf[n + 1] = 0;
	for (int i = n; i; --i) {
		if (a[i] == 1) {
			suf[i] = suf[i + 1] + 1;
		} else {
			suf[i] = 0;
		}
	}

	long long ans = 0;
	for (int r = 1; r <= n; ++r) {
		long long mul = 1, sum = 0;
		for (int l = r; l; l = l - 1 - pre[l - 1]) {
			if (mul < INF / a[l]) {
				mul *= a[l];
			} else {
				break;
			}
			sum += a[l];
			if (mul % k == 0) {
				long long d = mul / k - sum;
				if (0 <= d && d <= pre[l - 1]) {
					++ans;
				}
			}
			sum += pre[l - 1];
		}
	}
	std::cout << ans << "\n";
}