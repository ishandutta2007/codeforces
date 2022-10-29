#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

int n;

inline void init() {
	scanf("%d", &n);
}

vector<ll> ans;
inline void solve() {
	for (int d = 1; d * d <= n; d++) {
		if (!(n % d)) {
			ans.push_back((n - d + 2) * 1ll * (n / d) / 2);
			
			if (d * d != n) {
				ans.push_back((n - (n / d) + 2) * 1ll * d / 2);
			}	
		}
	}
	sort(ans.begin(), ans.end());
	for (auto e : ans)
		printf("%I64d ", e);
}

int main() {
	init();
	solve();
	return 0;
}