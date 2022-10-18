#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_mx(int n) {
	return (n - 1) * (n - 1) / 4;
}

vector<int> solve(int n, int m) {
	if(m > get_mx(n)) {
		return {-1};
	} else if(n == 1) {
		return {1};
	} else {
		int k = n;
		while(get_mx(k - 1) > m) {
			k--;
		}
		k--;
		vector<int> a;
		for(int i = 1; i <= k; i++) {
			a.push_back(i);
		}
		int res = m - get_mx(k);
		int max_step = get_mx(k + 1) - get_mx(k);
		if(res) {
			a.push_back(k + 1 + 2 * (max_step - res));
		}
		for(int i = 0; i < (n - k - bool(res)); i++) {
			a.push_back(4 * n + 2 * k * i + 1);
		}
		return a;
	}
}

signed main() {
	for(int n = 1; n <= 0; n++) {
		for(int m = 0; m <= n * n * n; m++) {
			cerr << n << ' ' << m << endl;
			auto a = solve(n, m);
			for(auto it: a) {
				cerr << it << ' ';
			}
			cerr << endl;
			if(m > get_mx(n)) {
				assert(a == vector<int>{-1});
			} else {
				int check = 0;
				for(int k = 0; k < n; k++) {
					for(int j = 0; j < k; j++) {
						assert(a[j] < a[k]);
						for(int i = 0; i < j; i++) {
							check += a[i] + a[j] == a[k];
						}
					}
				}
				cerr << ": " << check << ' ' << m << endl;
				assert(check == m);
			}
		}
	}
	int n, m;
	cin >> n >> m;
	auto res = solve(n, m);
	for(auto it: res) {
		cout << it << ' ';
	}
	return 0;
}