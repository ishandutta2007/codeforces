#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 42;
vector<int> pr;
int is_pr[maxn];

vector<int> prime_divs(int n) {
	vector<int> res;
	for(auto it: pr) {
		if(n % it == 0) {
			res.push_back(it);
		}
		while(n % it == 0) {
			n /= it;
		}
	}
	if(n > 1) {
		res.push_back(n);
	}
	return res;
}

signed main() {
	for(int i = 2; i < maxn; i++) {
		if(!is_pr[i]) {
			for(int k = i; k < maxn; k += i) {
				is_pr[k] = 1;
			}
			pr.push_back(i);
		}
	}
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i] % 2;
	}
	const int k = 2;
	for(int j = 0; j < 20; j++) {
		int t = a[rng() % n];
		for(int z = max<int>(1, t - k); z <= t + k; z++) {
			for(auto it: prime_divs(z)) {
				int cur = 0;
				for(int i = 0; i < n; i++) {
					int r = a[i] % it;
					if(a[i] == r) {
						cur += it - r;
					} else {
						cur += min(r, it - r);
					}
				}
				ans = min(ans, cur);
			}
		}
	}
	cout << ans << endl;
	return 0;
}