#include <bits/stdc++.h>

const int N = 1000005;

int n, k;
char a[N], b[N];
int cnt[26];

void solve() {
	std::cin >> n >> k;
	std::cin >> (a + 1) >> (b + 1);
	for (int i = 0; i < 26; ++i) {
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		++cnt[a[i] - 'a'];
	}
	for (int i = 1; i <= n; ++i) {
		--cnt[b[i] - 'a'];
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] < 0 || cnt[i] % k != 0) {
			std::cout << "No\n";
			return;
		}
		if (i < 25) {
			cnt[i + 1] += cnt[i];
			cnt[i] = 0;
		}
	}
	std::cout << "Yes\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}